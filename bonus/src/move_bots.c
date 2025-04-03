/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** move_bots.c
*/

#include "../include/graph.h"

void move_bots(void)
{
    bots_list_t *current = bots_info()->head;
    sfVector2f new_pos;

    while (current != NULL) {
        new_pos.x = current->pos.x + current->speed.x * current->direction.x;
        new_pos.y = current->pos.y + current->speed.y * current->direction.y;
        if (new_pos.x < 0 || new_pos.x > 1920 || new_pos.y < 0 || new_pos.y > 1080) {
            current->direction.x *= -1;
            current->direction.y *= -1;
        }
        sfRectangleShape_setPosition(current->rect, new_pos);
        sfText_setPosition(current->text, new_pos);
        current = current->next;
    }
}
