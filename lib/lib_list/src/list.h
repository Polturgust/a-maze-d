/*
** EPITECH PROJECT, 2024
** quest
** File description:
** list.h
*/

#ifndef _LIST_H_
    #define _LIST_H_
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdbool.h>

typedef struct linked_list_s {
    void *data;
    struct linked_list_s *next;
} linked_list_t;

int get_len(linked_list_t *list);
void push_front(linked_list_t **list, void *data);
void push_back(linked_list_t **list, void *data);
void insert_node_at_idc(linked_list_t **list, void *data, int idc);
void *pop_front(linked_list_t **list);
void *pop_back(linked_list_t **list);
void *pop_at_idc(linked_list_t **list, int idc);
void *get_data_by_idc(linked_list_t *list, int ind);
linked_list_t *get_node_by_index(linked_list_t *list, int idc);
#endif /* _LIST_H_ */
