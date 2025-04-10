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

void check_room(room_t **rooms, int idc, int i)
{
    if (rooms[idc]->cost != -2 && rooms[i]->cost >= 0){
        if (rooms[idc]->cost <= 0){
            rooms[idc]->cost = 1 + rooms[i]->cost;
            return;
        }
        if (rooms[i]->cost + 1 < rooms[idc]->cost)
            rooms[idc]->cost = 1 + rooms[i]->cost;
    }
}

int dfs(graph_t *graph, room_t **rooms, int idc)
{
    if (rooms[idc]->name == graph->last){
        rooms[idc]->cost = 0;
        return 0;
    }
    rooms[idc]->is_visited = 1;
    if (rooms[idc]->cost == -2)
        rooms[idc]->cost = -1;
    for (int i = 0; i < graph->nb_node; i++){
        if (graph->mat[idc][i] == 0)
            continue;
        if (!rooms[i]->is_visited){
            dfs(graph, rooms, i);
            check_room(rooms, idc, i);
        }
    }
    rooms[idc]->is_visited = 0;
    return 0;
}

static char check_path(room_t **rooms)
{
    for (int i = 0; rooms[i]; i++)
        if (rooms[i]->cost == 0)
            return 1;
    return 0;
}

room_t **create_room(graph_t *graph)
{
    room_t **rooms = malloc(sizeof(room_t *) * (graph->nb_node + 1));

    if (!rooms)
        return NULL;
    for (int i = 0; i < graph->nb_node; i++){
        rooms[i] = malloc(sizeof(room_t));
        if (!rooms[i]){
            free(rooms);
            return NULL;
        }
        rooms[i]->name = graph->name[i];
        rooms[i]->cost = -2;
        rooms[i]->is_visited = 0;
        rooms[i]->is_occuped = 0;
    }
    rooms[graph->nb_node] = NULL;
    return rooms;
}

char call_dfs(graph_t *graph)
{
    room_t **rooms = create_room(graph);

    if (!rooms)
        return 84;
    dfs(graph, rooms, get_idc_start(graph));
    if (!check_path(rooms)){
        write(2, "There is no path from beginning to end.\n", 40);
        return 84;
    }
    my_printf("#moves\n");
    robot_move(graph, rooms);
    for (int i = 0; rooms[i]; i++)
        free(rooms[i]);
    free(rooms);
    return 0;
}
