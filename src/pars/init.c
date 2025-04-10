/*
** EPITECH PROJECT, 2024
** B-CPE-200-NCE-2-1-amazed-florent.serra
** File description:
** init.c
*/

#include "../../include/amazed.h"

static int get_nb_node(char **file)
{
    unsigned int acc = 0;
    char **line;
    int size_line = 0;

    if (!file || my_arraylen(file) < 1)
        return 0;
    for (int i = 1; file[i]; i++) {
        if (file[i][0] == '#')
            continue;
        line = str_to_word_array(file[i], " ");
        size_line  =my_arraylen(line);
        destroy_array((void **)line);
        if (size_line != 3)
            break;
        acc++;
    }
    return acc;
}

static void init_name(graph_t *graph)
{
    graph->name = malloc(sizeof(int) * (graph->nb_node));
    for (int i = 0; i < graph->nb_node; i++)
        graph->name[i] = -1;
}

static int set_mat(graph_t *graph)
{
    for (int i = 0; i < graph->nb_node; i++) {
        graph->mat[i] = malloc(sizeof(int) * graph->nb_node);
        if (!graph->mat[i])
            return 1;
        for (int j = 0; j < graph->nb_node; j++)
            graph->mat[i][j] = 0;
    }
    graph->first = -1;
    graph->last = -1;
    write(1, "#rooms\n", 7);
    return 0;
}

int init(char **file, graph_t *graph)
{
    int nb_robot = my_getnbr(file[0]);

    if ((nb_robot == 0 && file[0][0] != 0) || nb_robot < 0)
        return 1;
    write(1, "#number_of_robots\n", 18);
    write(1, file[0], my_strlen(file[0]));
    write(1, "\n", 1);
    graph->nb_robots = nb_robot;
    graph->nb_node = get_nb_node(file);
    init_name(graph);
    graph->mat = malloc(sizeof(int *) * (graph->nb_node + 1));
    if (!graph->name || !graph->mat)
        return 1;
    graph->mat[graph->nb_node] = NULL;
    return set_mat(graph);
}
