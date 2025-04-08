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
    calculate_bot_pos(state_info());
    update_bots();
}
