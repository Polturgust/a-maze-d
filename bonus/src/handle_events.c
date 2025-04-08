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

static void handle_key_press()
{
    if (game_info()->event.type == sfEvtKeyPressed &&
        game_info()->event.key.code == sfKeySpace) {
            state_info()->in_hard_pause = !state_info()->in_hard_pause;
            printf("%i\n", state_info()->in_hard_pause);
    }
}

void handle_events(void)
{
    while (sfRenderWindow_pollEvent(
        game_info()->window, &game_info()->event)) {
        if (game_info()->event.type == sfEvtMouseButtonPressed)
            handle_mouse_click();
        handle_key_press();
        close_window();
    }
}
