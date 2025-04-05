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
    const float line_thickness = 3.0f;

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
            sfVector2f dir = {
                .x = room_end->pos.x - room_start->pos.x,
                .y = room_end->pos.y - room_start->pos.y
            };
            float length = sqrtf(dir.x * dir.x + dir.y * dir.y);
            if (length > 0) {
                dir.x /= length;
                dir.y /= length;
            }
            sfVector2f perpendicular = {.x = -dir.y * line_thickness, .y = dir.x * line_thickness};

            sfVertexArray *tunnel_line = sfVertexArray_create();
            sfVertexArray_setPrimitiveType(tunnel_line, sfTrianglesStrip);
            sfVertex v1 = {.position = {
                room_start->pos.x + perpendicular.x,
                room_start->pos.y + perpendicular.y
            }, .color = sfBlack};
            sfVertex v2 = {.position = {
                room_start->pos.x - perpendicular.x,
                room_start->pos.y - perpendicular.y
            }, .color = sfBlack};
            sfVertex v3 = {.position = {
                room_end->pos.x + perpendicular.x,
                room_end->pos.y + perpendicular.y
            }, .color = sfBlack};
            sfVertex v4 = {.position = {
                room_end->pos.x - perpendicular.x,
                room_end->pos.y - perpendicular.y
            }, .color = sfBlack};
            sfVertexArray_append(tunnel_line, v1);
            sfVertexArray_append(tunnel_line, v2);
            sfVertexArray_append(tunnel_line, v3);
            sfVertexArray_append(tunnel_line, v4);
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
        sfRenderWindow_drawCircleShape(game_info()->window, current_room->circle, NULL);
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
