/*
** EPITECH PROJECT, 2025
** dfs.c
** File description:
** dfs.c
*/

#include "../../include/amazed.h"
#include <stdlib.h>

typedef struct room_s {
    int name;
    int cost;
    int waiting;
    char is_visited;
} room_t;

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
    if (rooms[idc]->name == graph->last){
        rooms[idc]->cost = 0;
        return 1;
    }
    for (int i = 0; i < graph->nb_node; i++){
        if (graph->mat[idc][i] == 0)
            continue;
        if (!rooms[i]->is_visited) {
            rooms[i]->cost += dfs(graph, rooms, i);
            return rooms[i]->cost;
        }
    }
    return -1;
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
        rooms[i]->cost = -1;
        rooms[i]->is_visited = 0;
    }
    dfs(graph, rooms, get_idc_start(graph));
    return 0;
}
