/*
** EPITECH PROJECT, 2024
** B-CPE-200-NCE-2-1-amazed-florent.serra
** File description:
** add.c
*/

#include "../../include/amazed.h"

static int get_idn(int val, graph_t *graph)
{
    int i = 0;

    for (; i < graph->nb_node; i++)
        if (graph->name[i] == val)
            return i;
    return -1;
}

int add_strart_end(char **file, int *nb, graph_t *graph)
{
    int i = 0;
    char **frag_line;

    if (my_strcmp(&file[*nb][2], "end") != 0 && my_strcmp(&file[*nb][2],
    "start") != 0)
        return 1;
    writer(file[*nb]);
    (*nb) += 1;
    writer(file[*nb]);
    frag_line = str_to_word_array(file[*nb], " ");
    if (my_arraylen(frag_line) != 3)
        return 1;
    for (; graph->name[i] != -1; i++);
    graph->name[i] = my_getnbr(frag_line[0]);
    if (my_strcmp(&file[(*nb) - 1][2], "end") == 0)
        graph->last = my_getnbr(frag_line[0]);
    if (my_strcmp(&file[(*nb) - 1][2], "start") == 0)
        graph->first = my_getnbr(frag_line[0]);
    destroy_array((void **)frag_line);
    return 0;
}

int add_node(char *line, graph_t *graph)
{
    int i = 0;
    char **frag_line = str_to_word_array(line, " ");

    writer(line);
    for (; graph->name[i] != -1; i++);
    graph->name[i] = my_getnbr(frag_line[0]);
    destroy_array((void **)frag_line);
    return 0;
}

int add_way(char *line, graph_t *graph)
{
    char **frag_line = str_to_word_array(line, "-");
    int i = my_getnbr(frag_line[0]);
    int j = my_getnbr(frag_line[1]);
    int id_i = get_idn(i, graph);
    int id_j = get_idn(j, graph);

    writer(line);
    destroy_array((void **)frag_line);
    if (id_i == -1 || id_j == -1)
        return 1;
    if (i == j)
        return 0;
    graph->mat[id_i][id_j] = 1;
    graph->mat[id_j][id_i] = 1;
    return 0;
}
