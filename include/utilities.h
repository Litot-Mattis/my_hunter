/*
** EPITECH PROJECT, 2019
** my_hunter-master
** File description:
** utilities.h
*/

#ifndef UTILITIES_H
#define UTILITIES_H

#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct my_hunter_s {
    sfRenderWindow *window;
    sfTexture *texture_bg;
    sfTexture *texture_dk;
    sfTexture *texture_scope;
    sfTexture *texture_menu;
    sfSprite *background;
    sfSprite *scope;
    sfSprite *duck;
    sfSprite *s_menu;
    sfVector2f position;
    sfMusic *music;
    sfClock *clock;
    sfVideoMode video_mode;
    sfIntRect rect;
    sfTime time;
    sfVector2f mouse;
    sfVector2f duck_pos;
    sfVector2f scope_pos;
    sfVector2f scale_scope;
    sfVector2i mouse_pos;
    sfEvent event;
    float frame;
    int quit;
    int offset;
    int max_value;
    float seconde;
    float x_speed;

} my_hunter_t;

// Functions of lib:

void my_putchar(char c);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_len(char const *str);

// Functions of my_create.c:

void my_create_sprite_music(my_hunter_t *ht);
void my_create_window(my_hunter_t *ht);
void my_create_rect(my_hunter_t *ht);
void create(my_hunter_t *ht);
int my_rand(int min, int max);

//Functions of my_hunter.c:

void rand_axis_y(my_hunter_t *ht);
void clock(my_hunter_t *ht);
void display(my_hunter_t *ht);
void duck_unpop(my_hunter_t *ht);
void my_event(my_hunter_t *ht);

//Functions of main.c :

void my_scope(my_hunter_t *ht);
void move_rect(my_hunter_t *ht, int offset, int max_value);
int documentation(void);
int end_this_motherfucker(my_hunter_t *ht);
int main(int ac, char **av);

//menu.c
void menu(my_hunter_t *ht);

#endif
