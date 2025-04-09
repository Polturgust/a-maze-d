/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** move_bots.c
*/

#include "../include/graph.h"

static void animate_bot(bots_list_t *bot)
{
    static sfClock* anim_clock = NULL;
    static sfIntRect texture_area = {0, 0, 11, 9};

    if (!anim_clock) {
        anim_clock = sfClock_create();
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(anim_clock)) >= 0.2) {
        if (texture_area.left == 0) {
            texture_area.left = 11;
        } else {
            texture_area.left = 0;
        }
        sfClock_restart(anim_clock);
    }
    if (bot->speed.x != 0 || bot->speed.y != 0) {
        sfRectangleShape_setFillColor(bot->rect, sfWhite);
        sfRectangleShape_setTextureRect(bot->rect, texture_area);
    } else
        sfRectangleShape_setFillColor(
            bot->rect, sfColor_fromRGB(150, 150, 155));
}

static void update_bots(void)
{
    bots_t *bots = bots_info();
    bots_list_t *bot = bots->head;

    if (!bots)
        return;
    while (bot) {
        sfRectangleShape_setPosition(bot->rect, bot->pos);
        animate_bot(bot);
        bot = bot->next;
    }
}

void move_bots(void)
{
    calculate_bot_pos(state_info());
    update_bots();
}
