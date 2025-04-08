/*
** EPITECH PROJECT, 2025
** dfs.c
** File description:
** dfs.c
*/

#include "../../include/amazed.h"

int get_idc_start(graph_t *graph)
{
    int start = graph->first;

    for (int i = 0; i < graph->nb_node; i++){
        if (graph->name[i] == start)
           return i;
    }
    return -1;
}

int dfs(graph_t *graph, room_t **rooms, int idc)
{
    int retval = -1;    

    printf("room %i:\n", rooms[idc]->name);
    for (int i = 0; i < graph->nb_node; i++)
        printf("%i", graph->mat[idc][i]);
    printf("\n");
    if (rooms[idc]->name == graph->last){
        rooms[idc]->cost = 0;
        return 1;
    }
    rooms[idc]->is_visited = 1;
    for (int i = 0; i < graph->nb_node; i++){
        printf("bah je suis la frr\n");
        if (graph->mat[idc][i] == 0)
            continue;
        printf("romms numero -> %i\n", rooms[i]->name);
        if (!rooms[i]->is_visited) {
            rooms[i]->cost += 1 + dfs(graph, rooms, i);
            retval = rooms[i]->cost;
        }
    }
    return retval;
}

char call_dfs(graph_t *graph)
{
    room_t **rooms = malloc(sizeof(room_t *) * (graph->nb_node + 1));

    if (!rooms)
        return 84;
    for (int i = 0; i < graph->nb_node; i++){
        rooms[i] = malloc(sizeof(room_t));
        if (!rooms[i]){
            free(rooms);
            return 84;
        }
        rooms[i]->name = graph->name[i];
        rooms[i]->cost = 0;
        rooms[i]->is_visited = 0;
    }
    printf("\n");
    rooms[graph->nb_node] = NULL;
    dfs(graph, rooms, get_idc_start(graph));
    for (int i = 0; rooms[i]; i++)
        printf("rooms [name: %i\ncost: %i\nis_visited: %i]\n",rooms[i]->name, rooms[i]->cost, rooms[i]->is_visited);
    return 0;
}
