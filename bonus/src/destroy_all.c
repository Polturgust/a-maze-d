/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** destroy_all.c
*/

#include "../include/graph.h"

static void free_moves(maze_t *maze)
{
    for (int i = 0; maze->moves[i]; i++) {
        for (int j = 0; maze->moves[i][j]; j++) {
            free(maze->moves[i][j]);
        }
        free(maze->moves[i]);
    }
}

static void destroy_maze(void)
{
    maze_t *maze = maze_info();

    if (maze->tunnels) {
        for (int i = 0; maze->tunnels[i]; i++) {
            free(maze->tunnels[i]);
        }
        free(maze->tunnels);
    }
    if (maze->moves) {
        free_moves(maze);
        free(maze->moves);
    }
}

static void destroy_rooms(void)
{
    rooms_list_t *room = rooms_info()->head;
    rooms_list_t *next;

    while (room) {
        next = room->next;
        if (room->circle)
            sfCircleShape_destroy(room->circle);
        if (room->text)
            sfText_destroy(room->text);
        free(room);
        room = next;
    }
    rooms_info()->head = NULL;
}

static void destroy_bots(void)
{
    bots_list_t *bot = bots_info()->head;
    bots_list_t *next;
    movement_state_t *state = state_info();

    while (bot) {
        next = bot->next;
        if (bot->rect)
            sfRectangleShape_destroy(bot->rect);
        free(bot);
        bot = next;
    }
    bots_info()->head = NULL;
    if (state->pause_clock) {
        sfClock_destroy(state->pause_clock);
    }
}

void destroy_all(void)
{
    if (game_info()->window) {
        sfRenderWindow_destroy(game_info()->window);
    }
    destroy_maze();
    destroy_rooms();
    destroy_bots();
}
