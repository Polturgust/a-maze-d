/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** draw_elements.c
*/

#include "../include/graph.h"

void draw_elements(void)
{
    rooms_list_t *current = rooms_info()->head;

    while (current != NULL) {
        sfRenderWindow_drawRectangleShape(game_info()->window, current->rect, NULL);
        sfRenderWindow_drawText(game_info()->window, current->text, NULL);
        current = current->next;
    }
}
