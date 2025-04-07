/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** create_elements.c
*/

#include "../include/graph.h"

static void scale_and_position_rooms(
    float min_x, float min_y, float max_x, float max_y)
{
    rooms_list_t *current = rooms_info()->head;
    const float av_width = 1920 - 2 * 100;
    const float av_height = 1080 - 2 * 100;
    float x_scale = (max_x == min_x) ? 0 : (av_width / (max_x - min_x));
    float y_scale = (max_y == min_y) ? 0 : (av_height / (max_y - min_y));

    while (current != NULL) {
        if (max_x != min_x)
            current->pos.x = 100 + (current->pos.x - min_x) * x_scale;
        else
            current->pos.x = 1920 / 2;
        if (max_y != min_y)
            current->pos.y = 100 + (current->pos.y - min_y) * y_scale;
        else
            current->pos.y = 1080 / 2;
        sfCircleShape_setPosition(current->circle, current->pos);
        sfText_setPosition(current->text,
            (sfVector2f){current->pos.x + 10, current->pos.y + 10});
        current = current->next;
    }
}

static void change_position(void)
{
    rooms_list_t *current = rooms_info()->head;
    float min_x = INFINITY;
    float max_x = -INFINITY;
    float min_y = INFINITY;
    float max_y = -INFINITY;

    while (current != NULL) {
        min_x = current->pos.x < min_x ? current->pos.x : min_x;
        max_x = current->pos.x > max_x ? current->pos.x : max_x;
        min_y = current->pos.y < min_y ? current->pos.y : min_y;
        max_y = current->pos.y > max_y ? current->pos.y : max_y;
        current = current->next;
    }
    scale_and_position_rooms(min_x, min_y, max_x, max_y);
}

static void set_circle_features(rooms_list_t *current,
    const float circle_radius, const int circle_point_count, sfFont *font)
{
    current->circle = sfCircleShape_create();
    sfCircleShape_setRadius(current->circle, circle_radius);
    sfCircleShape_setPointCount(current->circle, circle_point_count);
    sfCircleShape_setOrigin(current->circle,
        (sfVector2f){circle_radius, circle_radius});
    sfCircleShape_setFillColor(current->circle, sfColor_fromRGB(255, 0, 0));
    sfCircleShape_setOutlineThickness(current->circle, 5);
    sfCircleShape_setOutlineColor(current->circle, sfBlack);
    current->text = sfText_create();
    sfText_setFont(current->text, font);
    sfText_setCharacterSize(current->text, 20);
    sfText_setFillColor(current->text, sfColor_fromRGB(220, 220, 220));
    sfText_setString(current->text, my_itoa(current->name));
    sfText_setOrigin(current->text, (sfVector2f){20, 20});
    sfText_setPosition(current->text,
        (sfVector2f){circle_radius, circle_radius});
}

static void create_circle_for_rooms(void)
{
    const float circle_radius = 50;
    const int circle_point_count = 30;
    sfFont *font = sfFont_createFromFile(
        "./bonus/src/resources/fonts/ARCADE_N.TTF");
    rooms_list_t *current = rooms_info()->head;

    if (!font)
        return;
    while (current != NULL) {
        set_circle_features(current, circle_radius, circle_point_count, font);
        if (current->is_start)
            sfCircleShape_setFillColor(
                current->circle, sfColor_fromRGB(0, 255, 0));
        if (current->is_end)
            sfCircleShape_setFillColor(
                current->circle, sfColor_fromRGB(0, 0, 255));
        current = current->next;
    }
}

static void create_rect_for_bots(const float bot_size,
    rooms_list_t *start_room, int i)
{
    bots_list_t *new_bot;
    sfTexture *bot_texture = sfTexture_createFromFile(
        "./bonus/src/resources/images/bot1.png", NULL);

    new_bot = malloc(sizeof(bots_list_t));
    if (!new_bot || !bot_texture)
        return;
    new_bot->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(new_bot->rect,
        (sfVector2f){bot_size, bot_size});
    sfRectangleShape_setTexture(new_bot->rect, bot_texture, sfTrue);
    sfRectangleShape_setOrigin(new_bot->rect,
        (sfVector2f){bot_size / 2, bot_size / 2});
    new_bot->name = i + 1;
    new_bot->pos = start_room->pos;
    new_bot->speed = (sfVector2f){0, 0};
    new_bot->move_vector = (sfVector2f){0, 0};
    sfRectangleShape_setPosition(new_bot->rect, new_bot->pos);
    new_bot->next = bots_info()->head;
    bots_info()->head = new_bot;
}

static void create_bots(void)
{
    const float bot_size = 50;
    int bots_nbr = maze_info()->robot_nbr;
    rooms_list_t *start_room = rooms_info()->head;

    bots_info()->head = NULL;
    while (start_room != NULL && !start_room->is_start)
        start_room = start_room->next;
    if (!start_room)
        return;
    for (int i = 0; i < bots_nbr; i++) {
        create_rect_for_bots(bot_size, start_room, i);
    }
}

void create_elements(void)
{
    fill_elements();
    create_circle_for_rooms();
    change_position();
    create_bots();
    return;
}
