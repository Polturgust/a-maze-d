/*
** EPITECH PROJECT, 2024
** quest
** File description:
** lib_list.c
*/

#include "list.h"

void push_front(linked_list_t **list, void *data)
{
    linked_list_t *new_node = malloc(sizeof(linked_list_t));

    new_node->data = data;
    new_node->next = *list;
    *list = new_node;
}

void push_back(linked_list_t **list, void *data)
{
    linked_list_t *new_node = malloc(sizeof(linked_list_t));
    linked_list_t *i = *list;

    if (*list == NULL){
        write(STDERR_FILENO, "cannot push: the list is NULL\n", 30);
        return;
    }
    new_node->data = data;
    new_node->next = NULL;
    for (; i->next; i = i->next);
    i->next = new_node;
}

void *pop_front(linked_list_t **list)
{
    linked_list_t *del;
    void *data;

    if (*list == NULL){
        write(STDERR_FILENO, "the list is empty\n", 18);
        return NULL;
    }
    del = *list;
    *list = (*list)->next;
    data = del->data;
    free(del);
    return data;
}

void *pop_back(linked_list_t **list)
{
    linked_list_t *i = *list;
    void *data;

    if (*list == NULL){
        write(STDERR_FILENO, "the list is already empty\n", 26);
        return NULL;
    }
    for (; i->next; i = i->next);
    free(i);
    data = i->data;
    return data;
}
