/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** draw_elements.c
*/

#include "../include/graph.h"

static void create_and_show_tunnels(void)
{
    int room1, room2;

    if (!maze_info()->tunnels)
        return;
    for (int i = 0; maze_info()->tunnels[i] != NULL; i++) {
        char *tunnel = maze_info()->tunnels[i];
        if (sscanf(tunnel, "%d-%d", &room1, &room2) != 2)
            continue;
        rooms_list_t *room_start = NULL;
        rooms_list_t *room_end = NULL;
        rooms_list_t *current = rooms_info()->head;
        while (current != NULL) {
            if (current->name == room1)
                room_start = current;
            if (current->name == room2)
                room_end = current;
            if (room_start && room_end)
                break;
            current = current->next;
        }
        if (room_start && room_end) {
            sfVertexArray *tunnel_line = sfVertexArray_create();
            sfVertexArray_setPrimitiveType(tunnel_line, sfLinesStrip);
            sfVertex start_vertex = {.position = room_start->pos, .color = sfWhite};
            sfVertex end_vertex = {.position = room_end->pos, .color = sfWhite};
            sfVertexArray_append(tunnel_line, start_vertex);
            sfVertexArray_append(tunnel_line, end_vertex);
            sfRenderWindow_drawVertexArray(game_info()->window, tunnel_line, NULL);
            sfVertexArray_destroy(tunnel_line);
        }
    }
}

void draw_elements(void)
{
    rooms_list_t *current_room = rooms_info()->head;

    create_and_show_tunnels();
    while (current_room != NULL) {
        sfRenderWindow_drawRectangleShape(game_info()->window, current_room->rect, NULL);
        sfRenderWindow_drawText(game_info()->window, current_room->text, NULL);
        current_room = current_room->next;
    }

    bots_list_t *current_bot = bots_info()->head;
    while (current_bot != NULL) {
        sfRenderWindow_drawRectangleShape(game_info()->window, current_bot->rect, NULL);
        sfRenderWindow_drawText(game_info()->window, current_bot->text, NULL);
        current_bot = current_bot->next;
    }
}
