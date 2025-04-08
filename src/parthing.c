/*
** EPITECH PROJECT, 2025
** B-CPE-200-NCE-2-1-amazed-florent.serra
** File description:
** parthing.c
*/

#include "../include/amazed.h"

static void del(graph_t *graph, char *in, int error)
{
    free(in);
    if (error) {
        if (graph->mat)
            destroy_array((void **)(graph->mat));
        free(graph);
    }
}

int test_line(char *line, int *nb)
{
    if (*nb == 0)
    free(line);
    return 0;
}

graph_t *parth(linked_list_t **node_list)
{
    char *input;
    int error = 0;
    graph_t *graph = malloc(sizeof(graph_t));
    size_t n;

    if (!graph)
        return NULL;
    for (int i = 0; getline(&input, &n, stdin) != -1; i++) {
        error = test_line(my_strndup(input, my_strlen(input) - 1), &i);
        if (error)
            break;
    }
    del(graph, input, error);
    (void)node_list;
    return graph;
}
