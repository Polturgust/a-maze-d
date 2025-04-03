/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** singletons.c
*/

#include "../include/graph.h"

game_t *game_info(void)
{
    static game_t game_info;

    return &game_info;
}

maze_t *maze_info(void)
{
    static maze_t maze_info;

    return &maze_info;
}

rooms_t *rooms_info(void)
{
    static rooms_t rooms_info;

    return &rooms_info;
}

bots_t *bots_info(void)
{
    static bots_t bots_info;

    return &bots_info;
}
