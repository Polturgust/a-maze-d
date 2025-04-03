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
