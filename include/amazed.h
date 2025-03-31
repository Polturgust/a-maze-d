/*
** EPITECH PROJECT, 2024
** B-CPE-200-NCE-2-1-amazed-florent.serra
** File description:
** amazed.h
*/

#ifndef AMAZED_H_
    #define AMAZED_H_
    #include "my.h"
    #include "list.h"
    #include <stdbool.h>

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
//////////////////
//
// parth take a nul lnk-list complete it if the file is good and return mat-adj
// else it return null
//
//////////////////
int **parth(linked_list_t **node_list);

#endif /* amazed.h */
