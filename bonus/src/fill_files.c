/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** fill_files.c
*/

#include "../include/graph.h"

static int find_section(int *cur_section, char line[256])
{
    if (strcmp(line, "#number_of_robots") == 0) {
        *cur_section = 1;
        return 1;
    }
    if (strcmp(line, "#rooms") == 0) {
        *cur_section = 2;
        return 1;
    }
    if (strcmp(line, "#tunnels") == 0) {
        *cur_section = 3;
        return 1;
    }
    if (strcmp(line, "#moves") == 0) {
        *cur_section = 4;
        return 1;
    }
    if (line[0] == '\0') {
        return 1;
    }
    return 0;
}

static void write_files(
    int cur_section, char line[256], FILE *robots_file, FILE *rooms_file)
{
    if (cur_section == 1)
        fprintf(robots_file, "%s\n", line);
    if (cur_section == 2)
        fprintf(rooms_file, "%s\n", line);
}

static void write_other_files(
    int cur_section, char line[256], FILE *tunnels_file, FILE *moves_file)
{
    if (cur_section == 3)
        fprintf(tunnels_file, "%s\n", line);
    if (cur_section == 4)
        fprintf(moves_file, "%s\n", line);
}

int fill_files(void)
{
    FILE *robots_file = fopen("./bonus/robot_nbr.txt", "w");
    FILE *rooms_file = fopen("./bonus/rooms.txt", "w");
    FILE *tunnels_file = fopen("./bonus/tunnels.txt", "w");
    FILE *moves_file = fopen("./bonus/moves.txt", "w");
    char line[256];
    int cur_section = 0;

    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = '\0';
        if (find_section(&cur_section, line) == 1)
            continue;
        write_files(cur_section, line, robots_file, rooms_file);
        write_other_files(cur_section, line, tunnels_file, moves_file);
    }
    fclose(robots_file);
    fclose(rooms_file);
    fclose(tunnels_file);
    fclose(moves_file);
    return 0;
}
