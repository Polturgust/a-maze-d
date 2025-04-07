/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** move_bots.c
*/

#include "../include/graph.h"

static void update_bots(void)
{
    bots_t *bots = bots_info();
    bots_list_t *bot = bots->head;

    if (!bots)
        return;
    while (bot) {
        sfRectangleShape_setPosition(bot->rect, bot->pos);
        bot = bot->next;
    }
}

void move_bots(void)
{
    static movement_state_t state = {0};

    if (!state.pause_clock) {
        state.pause_clock = sfClock_create();
    }
    calculate_bot_pos(&state);
    update_bots();
}
