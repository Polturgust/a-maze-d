/*
** EPITECH PROJECT, 2024
** B-CPE-200-NCE-2-1-amazed-florent.serra
** File description:
** amazed.h
*/

#ifndef AMAZED_H_
    #define AMAZED_H_
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include "my.h"
    #include "list.h"

/*
** matrice struct
*/
///////////////////
//
// mat is the matrice (d'adjacence), nb_node is nb_node is the number of node
//
///////////////////
typedef struct graph_s {
    int **mat;
    int *name;
    int nb_node;
    int nb_robots;
    int first;
    int last;
} graph_t;

typedef struct room_s {
    int name;
    int cost;
    int waiting;
    char is_visited;
    char is_occuped;
} room_t;

typedef struct robot_s {
    int id;
    int pos;
} robot_t;
/*
** pathing
*/
///////////////////
//
// parth take a nul lnk-list complete it if the file is good and return mat-adj
// else it return null
//
///////////////////
void robot_move(graph_t *graph, room_t **room);
char call_dfs(graph_t *graph);
int dfs(graph_t *graph, room_t **rooms, int idc);
graph_t *pars(void);
void writer(char *str);
int init(char **file, graph_t *graph);
void del_graph(graph_t *graph);
int add_strart_end(char **file, int *nb, graph_t *graph);
int add_node(char *line, graph_t *graph);
int add_way(char *line, graph_t *graph);

#endif /* amazed.h */
