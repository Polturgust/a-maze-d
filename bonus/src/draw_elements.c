/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** draw_elements.c
*/

#include "../include/graph.h"

static void find_points(rooms_list_t **room_start, rooms_list_t **room_end,
    int room1, int room2)
{
    rooms_list_t *current = rooms_info()->head;

    *room_start = NULL;
    *room_end = NULL;
    while (current != NULL) {
        if (current->name == room1)
            *room_start = current;
        if (current->name == room2)
            *room_end = current;
        if (*room_start && *room_end)
            break;
        current = current->next;
    }
}

static void create_and_draw_vertexes(rooms_list_t *room_start,
    rooms_list_t *room_end, sfVector2f dir, const float line_thickness)
{
    sfVector2f perpendicular = {.x = -dir.y * line_thickness,
        .y = dir.x * line_thickness};
    sfVertexArray *tunnel_line = sfVertexArray_create();
    sfVertex v1 = {.position = {room_start->pos.x + perpendicular.x,
        room_start->pos.y + perpendicular.y}, .color = sfBlack};
    sfVertex v2 = {.position = {room_start->pos.x - perpendicular.x,
        room_start->pos.y - perpendicular.y}, .color = sfBlack};
    sfVertex v3 = {.position = {room_end->pos.x + perpendicular.x,
        room_end->pos.y + perpendicular.y}, .color = sfBlack};
    sfVertex v4 = {.position = {room_end->pos.x - perpendicular.x,
        room_end->pos.y - perpendicular.y}, .color = sfBlack};

    sfVertexArray_setPrimitiveType(tunnel_line, sfTrianglesStrip);
    sfVertexArray_append(tunnel_line, v1);
    sfVertexArray_append(tunnel_line, v2);
    sfVertexArray_append(tunnel_line, v3);
    sfVertexArray_append(tunnel_line, v4);
    sfRenderWindow_drawVertexArray(
        game_info()->window, tunnel_line, NULL);
    sfVertexArray_destroy(tunnel_line);
}

static sfVector2f find_dir(rooms_list_t *room_start, rooms_list_t *room_end)
{
    sfVector2f dir = {.x = room_end->pos.x - room_start->pos.x,
        .y = room_end->pos.y - room_start->pos.y};
    float length = sqrtf(dir.x * dir.x + dir.y * dir.y);

    if (length > 0) {
        dir.x /= length;
        dir.y /= length;
    }
    return dir;
}

static void create_and_show_tunnels(void)
{
    int room1;
    int room2;
    const float thickness = 3;
    rooms_list_t *room_start = NULL;
    rooms_list_t *room_end = NULL;
    sfVector2f dir;
    char *tunnel;

    if (!maze_info()->tunnels)
        return;
    for (int i = 0; maze_info()->tunnels[i] != NULL; i++) {
        tunnel = maze_info()->tunnels[i];
        if (sscanf(tunnel, "%d-%d", &room1, &room2) != 2)
            continue;
        find_points(&room_start, &room_end, room1, room2);
        if (room_start && room_end) {
            dir = find_dir(room_start, room_end);
            create_and_draw_vertexes(room_start, room_end, dir, thickness);
        }
    }
}

void draw_elements(void)
{
    rooms_list_t *current_room = rooms_info()->head;
    bots_list_t *current_bot = bots_info()->head;

    create_and_show_tunnels();
    while (current_room != NULL) {
        sfRenderWindow_drawCircleShape(
            game_info()->window, current_room->circle, NULL);
        sfRenderWindow_drawText(game_info()->window, current_room->text, NULL);
        current_room = current_room->next;
    }
    while (current_bot != NULL) {
        sfRenderWindow_drawRectangleShape(
            game_info()->window, current_bot->rect, NULL);
        current_bot = current_bot->next;
    }
}
