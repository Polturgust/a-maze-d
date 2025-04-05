#include "../include/graph.h"

typedef struct movement_state_s {
    int current_move_set;
    bool processing_moves;
    bool initialized_movement;
    float base_speed;
} movement_state_t;

static bool has_ended(movement_state_t *state)
{
    return (maze_info()->moves == NULL || 
            maze_info()->moves[state->current_move_set] == NULL);
}

static sfVector2f get_direction_and_distance(sfVector2f pos1, sfVector2f pos2, float *distance)
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

static void set_targets_and_speed(bots_list_t *bot, int bot_id, int room_id, float base_speed)
{
    rooms_list_t *room = rooms_info()->head;

    while (bot) {
        if (bot->name == bot_id) {
            while (room) {
                if (room->name == room_id) {
                    float distance;
                    sfVector2f direction = get_direction_and_distance(bot->pos, room->pos, &distance);
                    bot->target_pos = room->pos;
                    float speed = base_speed * distance;
                    bot->speed.x = direction.x * speed;
                    bot->speed.y = direction.y * speed;
                    return;
                }
                room = room->next;
            }
        }
        bot = bot->next;
    }
}

static bool check_arrival(movement_state_t *state)
{
    bool all_bots_arrived = true;
    bots_list_t *bot = bots_info()->head;

    while (bot) {
        if (state->initialized_movement) {
            float dx = bot->target_pos.x - bot->pos.x;
            float dy = bot->target_pos.y - bot->pos.y;
            float distance = sqrt(dx*dx + dy*dy);
            if (distance > 5) {
                bot->pos.x += bot->speed.x;
                bot->pos.y += bot->speed.y;
                all_bots_arrived = false;
            } else {
                bot->pos = bot->target_pos;
                bot->speed = (sfVector2f){0, 0};
            }
        }
        bot = bot->next;
    }
    return all_bots_arrived;
}

static void calculate_bot_pos(movement_state_t *state)
{
    if (!maze_info() || !maze_info()->moves || !bots_info() || !rooms_info() || has_ended(state))
        return;
    if (!state->processing_moves) {
        char **current_moves = maze_info()->moves[state->current_move_set];
        reset_movement(bots_info()->head);
        state->base_speed = 0.02f;
        for (int j = 0; current_moves[j]; j++) {
            int bot_id, room_id;
            if (sscanf(current_moves[j], "P%d-%d", &bot_id, &room_id) == 2) {
                set_targets_and_speed(bots_info()->head, bot_id, room_id, state->base_speed);
            }
        }
        state->processing_moves = true;
        state->initialized_movement = true;
    }
    if (check_arrival(state)) {
        state->processing_moves = false;
        state->initialized_movement = false;
        if (!has_ended(state)) {
            state->current_move_set++;
        }
    }
}

static void update_bots(void)
{
    bots_t *bots = bots_info();
    if (!bots) return;

    bots_list_t *bot = bots->head;
    while (bot) {
        sfRectangleShape_setPosition(bot->rect, bot->pos);
        sfText_setPosition(bot->text, (sfVector2f){bot->pos.x + 10, bot->pos.y + 10});
        bot = bot->next;
    }
}

void move_bots(void)
{
    static movement_state_t state = {0};
    calculate_bot_pos(&state);
    update_bots();
}
