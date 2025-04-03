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

typedef struct game_s {
    sfRenderWindow *window;
    sfEvent event;
} game_t;

//functions:
void draw_elements(void);
void create_elements(void);
void handle_events(void);

//singletons:
game_t *game_info(void);

//resources:


#endif /* !WORLD_H_ */
