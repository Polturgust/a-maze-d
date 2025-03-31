/*
** EPITECH PROJECT, 2024
** quest
** File description:
** list2.c
*/

#include "list.h"

static int error_handling(linked_list_t *list, int idc)
{
    if (get_len(list) <= idc || idc < 0){
        write(STDERR_FILENO, "Error: index out of range.\n", 27);
        return true;
    }
    if (list == NULL){
        write(STDERR_FILENO, "the list is empty\n", 18);
        return true;
    }
    return false;
}

int get_len(linked_list_t *list)
{
    int lenght = 0;

    for (linked_list_t *i = list; i != NULL; i = i->next){
        lenght++;
    }
    return lenght;
}

void *get_data_by_idc(linked_list_t *list, int idc)
{
    linked_list_t *i = list;
    void *data;

    if (error_handling(list, idc) == true)
        return NULL;
    for (; i->next != NULL && idc != 0; i = i->next)
        idc--;
    data = i->data;
    return data;
}

linked_list_t *get_node_by_index(linked_list_t *list, int idc)
{
    linked_list_t *i = list;

    if (error_handling(list, idc) == true)
        return NULL;
    for (; i->next != NULL && idc != 0; i = i->next)
        idc--;
    return i;
}

void insert_node_at_idc(linked_list_t **list, void *data, int idc)
{
    linked_list_t *new_node = malloc(sizeof(linked_list_t));
    linked_list_t *i = *list;

    if (error_handling(*list, idc) == true)
        return;
    for (; i->next != NULL && idc != 0; i = i->next)
        idc--;
    new_node->next = i->next;
    i->next = new_node;
}

void *pop_at_idc(linked_list_t **list, int idc)
{
    linked_list_t *prev = NULL;
    linked_list_t *curr = *list;
    void *data;

    if (error_handling(*list, idc) == true)
        return NULL;
    if (idc == 0)
        return pop_front(list);
    for (; curr != NULL && idc != 0; curr = curr->next){
        prev = curr;
        idc--;
    }
    prev->next = curr->next;
    data = curr->data;
    free(curr);
    return data;
}
