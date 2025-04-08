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
            sfRenderWindow_clear(
                game_info()->window, sfColor_fromRGB(150, 150, 150));
            handle_events();
            move_bots();
            draw_elements();
            sfRenderWindow_display(game_info()->window);
            sfClock_restart(fps);
        }
    }
    sfClock_destroy(fps);
}

static int check_other_files(FILE *file, char line[256])
{
    file = fopen("./bonus/tunnels.txt", "r");
    if (!file)
        return 84;
    if (strcmp(fgets(line, sizeof(line), file), "error\n") == 0) {
        fclose(file);
        return 84;
    }
    fclose(file);
    file = fopen("./bonus/robot_nbr.txt", "r");
    if (!file)
        return 84;
    if (strcmp(fgets(line, sizeof(line), file), "error\n") == 0) {
        fclose(file);
        return 84;
    }
    fclose(file);
    return 0;
}

static int check_files(void)
{
    FILE *file = fopen("./bonus/moves.txt", "r");
    char line[256];

    if (!file)
        return 84;
    if (strcmp(fgets(line, sizeof(line), file), "error\n") == 0) {
        fclose(file);
        return 84;
    }
    fclose(file);
    file = fopen("./bonus/rooms.txt", "r");
    if (!file)
        return 84;
    if (strcmp(fgets(line, sizeof(line), file), "error\n") == 0) {
        fclose(file);
        return 84;
    }
    fclose(file);
    check_other_files(file, line);
}

int main(void)
{
    sfVideoMode video_mode = {1920, 1080, 32};

    if (check_files() == 84) {
        write(2, "There was a problem with base amazed.\n", 39);
        return 84;
    }
    game_info()->window = sfRenderWindow_create(
        video_mode, "Amazed", sfClose, NULL);
    create_elements();
    while_window_open();
    destroy_all();
}
