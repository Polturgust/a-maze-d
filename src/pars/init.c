/*
** EPITECH PROJECT, 2024
** B-CPE-200-NCE-2-1-amazed-florent.serra
** File description:
** init.c
*/

#include "../../include/amazed.h"

static int write_error_fd(int fd)
{
    write(fd, "error", 5);
    close(fd);
    return 1;
}

static int get_nb_node(char **file)
{
    unsigned int acc = 0;
    char **line;

    if (!file || my_arraylen(file) < 1)
        return 0;
    for (int i = 1; file[i]; i++) {
        if (file[i][0] == '#')
            continue;
        line = str_to_word_array(file[i], " ");
        if (my_arraylen(line) != 3)
            break;
        destroy_array((void **)line);
        acc++;
    }
    if (line)
        destroy_array((void **)line);
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
    int fd_r = open("bonus/robot_nbr.txt", O_WRONLY | O_TRUNC | O_CREAT, 0644);
    int nb_robot = my_getnbr(file[0]);

    if ((nb_robot == 0 && file[0][0] != 0) || nb_robot < 0)
        return write_error_fd(fd_r);
    else
        write(fd_r, file[0], my_strlen(file[0]));
    close(fd_r);
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
