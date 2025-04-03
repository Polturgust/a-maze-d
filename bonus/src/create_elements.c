/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** create_elements.c
*/

#include "../include/graph.h"

static int cnt_lines(FILE *file)
{
    int count = 0;
    char line[256];

    while (fgets(line, sizeof(line), file) != NULL) {
        count++;
    }
    rewind(file);
    return count;
}

static void fill_moves(void)
{
    FILE *file = fopen("./bonus/moves.txt", "r");
    int nbr_lines;
    char line[256];

    if (!file)
        return;
    nbr_lines = cnt_lines(file);
    maze_info()->moves = malloc(sizeof(char **) * (nbr_lines + 1));
    if (!maze_info()->moves)
        return;
    maze_info()->moves[nbr_lines] = NULL;
    for (int i = 0; i < nbr_lines; i++) {
        maze_info()->moves[i] = my_stwa(fgets(line, sizeof(line), file), ' ');
    }
    fclose(file);
}

static void fill_nbr(void)
{
    FILE *file = fopen("./bonus/robot_nbr.txt", "r");
    char line[256];

    if (!file)
        return;
    fgets(line, sizeof(line), file);
    maze_info()->robot_nbr = atoi(line);
    fclose(file);
}

static void fill_tunnels(void)
{
    FILE *file = fopen("./bonus/tunnels.txt", "r");
    char line[256];
    int nbr_lines;

    if (!file) {
        return;
    }
    nbr_lines = cnt_lines(file);
    maze_info()->tunnels = malloc(sizeof(char *) * nbr_lines + 1);
    if (!maze_info()->tunnels)
        return;
    maze_info()->tunnels[nbr_lines] = NULL;
    for (int i = 0; i < nbr_lines; i++) {
        if (fgets(line, sizeof(line), file)) {
            maze_info()->tunnels[i] = strdup(line);
        }
    }
    fclose(file);
}

static void fill_rooms(void)
{
    FILE *file = fopen("./bonus/rooms.txt", "r");
    char line[256];
    bool is_start = false;
    bool is_end = false;
    rooms_list_t *current = NULL;

    if (!file)
        return;
    rooms_info()->head = NULL;
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "##start")) {
            is_start = true;
            continue;
        }
        if (strstr(line, "##end")) {
            is_end = true;
            continue;
        }
        if (line[0] == '#' || line[0] == '\n')
            continue;
        rooms_list_t *new_room = malloc(sizeof(rooms_list_t));
        if (!new_room)
            return;
        sscanf(line, "%d %f %f", &new_room->name, &new_room->pos.x, &new_room->pos.y);
        new_room->is_start = is_start;
        new_room->is_end = is_end;
        new_room->next = NULL;
        if (rooms_info()->head == NULL) {
            rooms_info()->head = new_room;
        } else {
            current = rooms_info()->head;
            while (current->next != NULL)
                current = current->next;
            current->next = new_room;
        }
        is_start = false;
        is_end = false;
    }
    fclose(file);
}

void create_elements(void)
{
    fill_moves();
    fill_nbr();
    fill_tunnels();
    fill_rooms();
    test_all();
    return;
}
