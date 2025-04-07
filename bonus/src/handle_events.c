/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** handle_events.c
*/

#include "../include/graph.h"

static void close_window(void)
{
    if (game_info()->event.type == sfEvtClosed)
        sfRenderWindow_close(game_info()->window);
    if (game_info()->event.type == sfEvtKeyPressed &&
    game_info()->event.key.code == sfKeyEscape)
        sfRenderWindow_close(game_info()->window);
}

static void handle_mouse_click(void)
{
    return;
}

void handle_events(void)
{
    while (sfRenderWindow_pollEvent(
        game_info()->window, &game_info()->event)) {
        if (game_info()->event.type == sfEvtMouseButtonPressed)
            handle_mouse_click();
        close_window();
    }
}
