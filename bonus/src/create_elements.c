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

static char ***fill_moves(FILE *file, int nbr_lines)
{
    char ***res = malloc(sizeof(char **) * (nbr_lines + 1));
    char line[256];

    if (!res)
        return NULL;
    res[nbr_lines] = NULL;
    for (int i = 0; i < nbr_lines; i++) {
        res[i] = my_stwa(fgets(line, sizeof(line), file), ' ');
    }
    return res;
}

static void read_moves(void)
{
    FILE *file = fopen("./bonus/moves.txt", "r");
    int nbr_lines;

    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    nbr_lines = cnt_lines(file);
    moves_info()->moves = fill_moves(file, nbr_lines);
    fclose(file);
}

void create_elements(void)
{
    read_moves();
    return;
}
