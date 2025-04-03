/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** create_elements.c
*/

#include "../include/graph.h"

static int cnt_lines(FILE *file)
{
    int count = 0;
    char line[256];

    while (fgets(line, sizeof(line), file) != NULL) {
        count++;
    }
    rewind(file);
    return count;
}

static void fill_moves(void)
{
    FILE *file = fopen("./bonus/moves.txt", "r");
    int nbr_lines;
    char line[256];

    if (!file)
        return;
    nbr_lines = cnt_lines(file);
    maze_info()->moves = malloc(sizeof(char **) * (nbr_lines + 1));
    if (!maze_info()->moves)
        return;
    maze_info()->moves[nbr_lines] = NULL;
    for (int i = 0; i < nbr_lines; i++) {
        maze_info()->moves[i] = my_stwa(fgets(line, sizeof(line), file), ' ');
    }
    fclose(file);
}

static void fill_nbr(void)
{
    FILE *file = fopen("./bonus/robot_nbr.txt", "r");
    char line[256];

    if (!file)
        return;
    fgets(line, sizeof(line), file);
    maze_info()->robot_nbr = atoi(line);
    fclose(file);
}

static void fill_tunnels(void)
{
    FILE *file = fopen("./bonus/tunnels.txt", "r");
    char line[256];
    int nbr_lines;

    if (!file) {
        return;
    }
    nbr_lines = cnt_lines(file);
    maze_info()->tunnels = malloc(sizeof(char *) * nbr_lines + 1);
    if (!maze_info()->tunnels)
        return;
    maze_info()->tunnels[nbr_lines] = NULL;
    for (int i = 0; i < nbr_lines; i++) {
        if (fgets(line, sizeof(line), file)) {
            maze_info()->tunnels[i] = strdup(line);
        }
    }
    fclose(file);
}

static void fill_rooms(void)
{
    FILE *file = fopen("./bonus/rooms.txt", "r");
    char line[256];
    bool is_start = false;
    bool is_end = false;
    rooms_list_t *current = NULL;

    if (!file)
        return;
    rooms_info()->head = NULL;
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "##start")) {
            is_start = true;
            continue;
        }
        if (strstr(line, "##end")) {
            is_end = true;
            continue;
        }
        if (line[0] == '#' || line[0] == '\n')
            continue;
        rooms_list_t *new_room = malloc(sizeof(rooms_list_t));
        if (!new_room)
            return;
        sscanf(line, "%d %f %f", &new_room->name, &new_room->pos.x, &new_room->pos.y);
        new_room->is_start = is_start;
        new_room->is_end = is_end;
        new_room->next = NULL;
        if (rooms_info()->head == NULL) {
            rooms_info()->head = new_room;
        } else {
            current = rooms_info()->head;
            while (current->next != NULL)
                current = current->next;
            current->next = new_room;
        }
        is_start = false;
        is_end = false;
    }
    fclose(file);
}

static void change_position(void)
{
    rooms_list_t *current = rooms_info()->head;
    float min_x = INFINITY, max_x = -INFINITY;
    float min_y = INFINITY, max_y = -INFINITY;
    const float screen_margin = 50;
    const float screen_width = 1920;
    const float screen_height = 1080;
    const float available_width = screen_width - 2 * screen_margin;
    const float available_height = screen_height - 2 * screen_margin;
    while (current != NULL) {
        if (current->pos.x < min_x) min_x = current->pos.x;
        if (current->pos.x > max_x) max_x = current->pos.x;
        if (current->pos.y < min_y) min_y = current->pos.y;
        if (current->pos.y > max_y) max_y = current->pos.y;
        current = current->next;
    }
    float x_scale = (max_x == min_x) ? 0 : (available_width / (max_x - min_x));
    float y_scale = (max_y == min_y) ? 0 : (available_height / (max_y - min_y));
    current = rooms_info()->head;
    while (current != NULL) {
        if (max_x != min_x)
            current->pos.x = screen_margin + (current->pos.x - min_x) * x_scale;
        else
            current->pos.x = screen_width / 2;
        if (max_y != min_y)
            current->pos.y = screen_margin + (current->pos.y - min_y) * y_scale;
        else
            current->pos.y = screen_height / 2;
        sfRectangleShape_setPosition(current->rect, current->pos);
        sfText_setPosition(current->text, (sfVector2f){current->pos.x + 10, current->pos.y + 10});
        current = current->next;
    }
}

static void create_rect_for_rooms(void)
{
    rooms_list_t *current = rooms_info()->head;
    sfFont *font = sfFont_createFromFile("./bonus/src/resources/fonts/ARCADE_N.TTF");

    while (current != NULL) {
        current->rect = sfRectangleShape_create();
        sfRectangleShape_setSize(current->rect, (sfVector2f){50, 50});
        sfRectangleShape_setFillColor(current->rect, sfColor_fromRGB(255, 0, 0));
        current->text = sfText_create();
        sfRectangleShape_setOrigin(current->rect, (sfVector2f){25, 25});
        sfText_setFont(current->text, font);
        sfText_setCharacterSize(current->text, 20);
        sfText_setFillColor(current->text, sfWhite);
        sfText_setString(current->text, my_itoa(current->name));
        sfText_setOrigin(current->text, (sfVector2f){25, 25});
        if (current->is_start) {
            sfRectangleShape_setFillColor(current->rect, sfColor_fromRGB(0, 255, 0));
        }
        if (current->is_end) {
            sfRectangleShape_setFillColor(current->rect, sfColor_fromRGB(0, 0, 255));
        }
        current = current->next;
    }
}

static void fill_bots(void)
{
    bots_info()->head = NULL;
    int bots_nbr = maze_info()->robot_nbr;
    rooms_list_t *start_room = rooms_info()->head;
    while (start_room != NULL && !start_room->is_start) {
        start_room = start_room->next;
    }
    if (!start_room) {
        return;
    }
    for (int i = 0; i < bots_nbr; i++) {
        bots_list_t *new_bot = malloc(sizeof(bots_list_t));
        if (!new_bot) {
            return;
        }
        new_bot->rect = sfRectangleShape_create();
        sfRectangleShape_setSize(new_bot->rect, (sfVector2f){30, 30});
        sfRectangleShape_setFillColor(new_bot->rect, sfColor_fromRGB(255, 255, 0));
        sfRectangleShape_setOrigin(new_bot->rect, (sfVector2f){15, 15});
        new_bot->text = sfText_create();
        sfText_setCharacterSize(new_bot->text, 15);
        sfText_setFillColor(new_bot->text, sfWhite);
        sfText_setString(new_bot->text, my_itoa(i + 1));
        sfText_setOrigin(new_bot->text, (sfVector2f){15, 15});
        new_bot->name = i + 1;
        new_bot->pos = start_room->pos;
        new_bot->speed = (sfVector2f){0, 0};
        new_bot->direction = (sfVector2f){0, 0};
        sfRectangleShape_setPosition(new_bot->rect, new_bot->pos);
        sfText_setPosition(new_bot->text, (sfVector2f){new_bot->pos.x + 10, new_bot->pos.y + 10});
        new_bot->next = bots_info()->head;
        bots_info()->head = new_bot;
    }
}

void create_elements()
{
    fill_moves();
    fill_nbr();
    fill_tunnels();
    fill_rooms();
    create_rect_for_rooms();
    change_position();
    fill_bots();
    return;
}
