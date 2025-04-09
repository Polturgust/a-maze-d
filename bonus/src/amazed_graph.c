/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** amazed_graph.c
*/

#include "../include/graph.h"

static int check_other_files(void)
{
    FILE *file = fopen("./bonus/tunnels.txt", "r");
    char l[256];

    if (!file)
        return 84;
    if (fgets(l, sizeof(l), file) == NULL || strcmp(l, "error\n") == 0) {
        fclose(file);
        return 84;
    }
    fclose(file);
    file = fopen("./bonus/robot_nbr.txt", "r");
    if (!file)
        return 84;
    if (fgets(l, sizeof(l), file) == NULL || strcmp(l, "error\n") == 0) {
        fclose(file);
        return 84;
    }
    fclose(file);
    return 0;
}

static int check_files(void)
{
    FILE *file = fopen("./bonus/moves.txt", "r");
    char l[256];

    if (!file)
        return 84;
    if (fgets(l, sizeof(l), file) == NULL || strcmp(l, "error\n") == 0) {
        fclose(file);
        return 84;
    }
    fclose(file);
    file = fopen("./bonus/rooms.txt", "r");
    if (!file)
        return 84;
    if (fgets(l, sizeof(l), file) == NULL || strcmp(l, "error\n") == 0) {
        fclose(file);
        return 84;
    }
    fclose(file);
    return check_other_files();
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

static int show_h(void)
{
    printf("\nBONUS USAGE:\n");
    printf("To run the bonus version of amazed, use the following command:\n");
    printf("./amazed < labyrinth_file | ./amazed_bonus\n");
    return 1;
}

static int check_args(int argc, char **argv)
{
    if (argc > 2)
        return 84;
    if (argc == 2) {
        if (strcmp(argv[1], "-h") == 0)
            return show_h();
        else
            return 84;
    }
    return 0;
}

int main(int argc, char **argv)
{
    sfVideoMode video_mode = {1920, 1080, 32};
    int args_validity = check_args(argc, argv);

    fill_files();
    if (args_validity == 84)
        return 84;
    if (args_validity == 1)
        return 0;
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
