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
    float time_elapsed = 0;

    sfClock_restart(fps);
    while (sfRenderWindow_isOpen(game_info()->window)) {
        time_elapsed = sfTime_asMilliseconds(sfClock_getElapsedTime(fps));
        if (time_elapsed >= 1000 / 30) {
            sfRenderWindow_clear(game_info()->window, sfBlack);
            handle_events();
            move_bots();
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
