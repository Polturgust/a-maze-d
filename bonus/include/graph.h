/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** list.h
*/

#ifndef WORLD_H_
    #define WORLD_H_
    #include <fcntl.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <time.h>
    #include <unistd.h>
    #include <math.h>
    #include <sys/stat.h>
    #include <stdbool.h>
    #include <string.h>
    #include <float.h>

typedef struct game_s {
    sfRenderWindow *window;
    sfEvent event;
} game_t;

typedef struct maze_s {
    int robot_nbr;
    char **tunnels;
    char ***moves;
} maze_t;

typedef struct rooms_list_s {
    sfCircleShape *circle;
    sfText *text;
    int name;
    sfVector2f pos;
    bool is_start;
    bool is_end;
    struct rooms_list_s *next;
} rooms_list_t;

typedef struct rooms_s {
    rooms_list_t *head;
} rooms_t;

typedef struct bots_list_s {
    sfRectangleShape *rect;
    int name;
    sfVector2f pos;
    sfVector2f speed;
    sfVector2f target_pos;
    struct bots_list_s *next;
} bots_list_t;

typedef struct bots_s {
    bots_list_t *head;
} bots_t;

typedef struct movement_state_s {
    int current_move_set;
    bool processing_moves;
    bool initialized_movement;
    float base_speed;
    sfClock* pause_clock;
    bool in_pause;
    bool in_hard_pause;
} movement_state_t;

//functions:
void draw_elements(void);
void create_elements(void);
void handle_events(void);
void move_bots(void);
void calculate_bot_pos(movement_state_t *state);
void fill_elements(void);
int fill_files(void);
void destroy_all(void);

//singletons:
game_t *game_info(void);
maze_t *maze_info(void);
rooms_t *rooms_info(void);
bots_t *bots_info(void);
movement_state_t *state_info(void);

//resources:
char **my_stwa(char *input_str, char delimiter);
char *my_itoa(int num);

#endif /* !WORLD_H_ */
