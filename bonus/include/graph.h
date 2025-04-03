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
    int name;
    sfVector2f pos;
    bool is_start;
    bool is_end;
    struct rooms_list_s *next;
} rooms_list_t;

typedef struct rooms_s {
    rooms_list_t *head;
} rooms_t;

//functions:
void draw_elements(void);
void create_elements(void);
void handle_events(void);

//singletons:
game_t *game_info(void);
maze_t *maze_info(void);
rooms_t *rooms_info(void);

//resources:
char **my_stwa(char *input_str, char delimiter);

#endif /* !WORLD_H_ */
