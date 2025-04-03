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
    int nb_node;
} graph_t;

/*
** node structure (only for graphique)
*/
typedef struct node_s {
    int number;
    int pos[2];
    bool is_start;
    bool is_end;
} node_t;

/*
** pathing
*/
///////////////////
//
// parth take a nul lnk-list complete it if the file is good and return mat-adj
// else it return null
//
///////////////////
graph_t *parth(linked_list_t **node_list);

#endif /* amazed.h */
