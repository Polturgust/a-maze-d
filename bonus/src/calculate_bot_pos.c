/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** calculate_bot_pos.c
*/

#include "../include/graph.h"

static bool has_ended(movement_state_t *state)
{
    return (maze_info()->moves == NULL ||
        maze_info()->moves[state->current_move_set] == NULL);
}

static sfVector2f get_direction_and_distance(
    sfVector2f pos1, sfVector2f pos2, float *distance)
{
    sfVector2f direction = {pos2.x - pos1.x, pos2.y - pos1.y};

    *distance = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (*distance > 0) {
        direction.x /= *distance;
        direction.y /= *distance;
    }
    return direction;
}

static void reset_movement(bots_list_t *bot)
{
    while (bot) {
        bot->speed = (sfVector2f){0, 0};
        bot->target_pos = bot->pos;
        bot = bot->next;
    }
}

static void go_through_rooms(bots_list_t *bot, int room_id, float base_speed)
{
    rooms_list_t *room = rooms_info()->head;
    float speed;
    float distance;
    sfVector2f direction;

    while (room) {
        if (room->name == room_id) {
            direction = get_direction_and_distance(
                bot->pos, room->pos, &distance);
            bot->target_pos = room->pos;
            speed = base_speed * distance;
            bot->speed.x = direction.x * speed;
            bot->speed.y = direction.y * speed;
            return;
        }
        room = room->next;
    }
}

static void set_targets_and_speed(
    bots_list_t *bot, int bot_id, int room_id, float base_speed)
{
    while (bot) {
        if (bot->name == bot_id) {
            go_through_rooms(bot, room_id, base_speed);
            return;
        }
        bot = bot->next;
    }
}

static void update_bot_position(
    float distance, bots_list_t *bot, bool *all_bots_arrived)
{
    if (distance > 5) {
        bot->pos.x += bot->speed.x;
        bot->pos.y += bot->speed.y;
        *all_bots_arrived = false;
    } else {
        bot->pos = bot->target_pos;
        bot->speed = (sfVector2f){0, 0};
    }
}

static bool check_arrival(movement_state_t *state)
{
    float dx;
    float dy;
    float distance;
    bool all_bots_arrived = true;
    bots_list_t *bot = bots_info()->head;

    while (bot) {
        if (state->initialized_movement) {
            dx = bot->target_pos.x - bot->pos.x;
            dy = bot->target_pos.y - bot->pos.y;
            distance = sqrt(dx * dx + dy * dy);
            update_bot_position(distance, bot, &all_bots_arrived);
        }
        bot = bot->next;
    }
    return all_bots_arrived;
}

static void process_moves(char **current_moves, movement_state_t *state)
{
    int bot_id;
    int room_id;

    for (int j = 0; current_moves[j]; j++) {
        if (sscanf(current_moves[j], "P%d-%d", &bot_id, &room_id) == 2)
        set_targets_and_speed(
            bots_info()->head, bot_id, room_id, state->base_speed);
    }
    state->processing_moves = true;
    state->initialized_movement = true;
}

static void call_arrival_check(movement_state_t *state)
{
    if (check_arrival(state)) {
        state->processing_moves = false;
        state->initialized_movement = false;
        if (!has_ended(state)) {
            state->current_move_set++;
            state->in_pause = true;
            sfClock_restart(state->pause_clock);
        }
    }
}

void calculate_bot_pos(movement_state_t *state)
{
    char **current_moves;

    if (!maze_info() || !maze_info()->moves || !bots_info() ||
    !rooms_info() || has_ended(state) || state->in_hard_pause)
        return;
    if (state->in_pause) {
        if (sfTime_asSeconds(
            sfClock_getElapsedTime(state->pause_clock)) >= 0.3) {
            state->in_pause = false;
            sfClock_restart(state->pause_clock);
        }
        return;
    }
    if (!state->processing_moves) {
        current_moves = maze_info()->moves[state->current_move_set];
        reset_movement(bots_info()->head);
        state->base_speed = 0.02;
        process_moves(current_moves, state);
    }
    call_arrival_check(state);
}
