/*
** EPITECH PROJECT, 2025
** dfs.c
** File description:
** dfs.c
*/

#include "../../include/amazed.h"

robot_t *init_robot(graph_t *graph)
{
    robot_t *robot = malloc(sizeof(robot_t));
    static int id = 1;

    if (!robot)
        return NULL;
    robot->id = id;
    robot->pos = graph->first;
    id++;
    return robot;
}

linked_list_t *create_robot(graph_t *graph)
{
    linked_list_t *robot = NULL;

    for (int i = 0; i < graph->nb_robots; i++)
        push_back(&robot, init_robot(graph));
    return robot;
}

int change_room(graph_t *graph, room_t **rooms, int idc_rooms, robot_t *robot)
{
    int retval = 0;

    if (!rooms[idc_rooms]->is_occuped){
        robot->pos = idc_rooms;
        retval = 1;
        my_printf("P%i-%i ", robot->id, robot->pos);
    }
    if (graph->name[robot->pos] != graph->last)
        rooms[robot->pos]->is_occuped = 1;
    return retval;
}

int select_room(robot_t *robot, graph_t *graph, room_t **rooms)
{
    int idc_rooms = -1;

    if (graph->name[robot->pos] == graph->last)
        return 1;
    rooms[robot->pos]->is_occuped = 0;
    for (int i = 0; i < graph->nb_node; i++){
        if (graph->mat[robot->pos][i] == 0 || rooms[i]->cost == -1)
            continue;
        if (idc_rooms == -1){
            idc_rooms = i;
            continue;
        }
        if (rooms[idc_rooms]->cost >= rooms[i]->cost + rooms[i]->is_occuped)
            idc_rooms = i;
    }
    if (change_room(graph, rooms, idc_rooms, robot))
        return 0;
    return -1;
}

static void parcour_rob(graph_t *graph, room_t **rooms, linked_list_t *robot,
    int *arrived)
{
    int verif = 0;

        for (linked_list_t *i = robot; i; i = i->next){
            verif = select_room((robot_t *)i->data, graph, rooms);
            if (verif == -1)
                break;
            *arrived += verif;
        }
}

void robot_move(graph_t *graph, room_t **room)
{
    linked_list_t *robot = create_robot(graph);
    int arrived = 0;

    while (arrived != graph->nb_robots){
        arrived = 0;
        parcour_rob(graph, room, robot, &arrived);
        my_printf("\n");
    }
    while (robot){
        free((robot_t *)pop_front(&robot));
    }
    free(robot);
}
