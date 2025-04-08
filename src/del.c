/*
** EPITECH PROJECT, 2024
** B-CPE-200-NCE-2-1-amazed-florent.serra
** File description:
** del.c
*/

#include "../include/amazed.h"

void del_graph(graph_t *graph)
{
    if (!graph)
        return;
    if (graph->mat)
        destroy_array((void **)graph->mat);
    if (graph->name)
        free(graph->name);
    free(graph);
}
