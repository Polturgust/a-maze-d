/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** amazed_graph.c
*/

#include "../include/graph.h"

static void destroy_all(void)
{
    return;
}

static void while_window_open(void)
{
    sfClock *fps = sfClock_create();

    sfClock_restart(fps);
    while (sfRenderWindow_isOpen(game_info()->window)) {
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(fps)) >= 1000 / 30) {
            sfRenderWindow_clear(game_info()->window, sfBlack);
            handle_events();
            draw_elements();
            sfRenderWindow_display(game_info()->window);
            sfClock_restart(fps);
        }
    }
    sfClock_destroy(fps);
}

int main(void)
{
    sfVideoMode video_mode = {1920, 1080, 32};

    game_info()->window = sfRenderWindow_create(video_mode, "Amazed", sfClose, NULL);
    create_elements();
    while_window_open();
    destroy_all();
}
