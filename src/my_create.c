/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** my_create.c
*/

#include "utilities.h"

void my_create_sprite_music(my_hunter_t *ht)
{
    ht->music = sfMusic_createFromFile("imgsrc/saxguy.ogg");
    ht->background = sfSprite_create();
    ht->duck = sfSprite_create();
    ht->scope = sfSprite_create();
    ht->texture_bg = sfTexture_createFromFile("imgsrc/bg.png", NULL);
    ht->texture_dk = sfTexture_createFromFile("imgsrc/duck.png", NULL);
    ht->texture_scope = sfTexture_createFromFile("imgsrc/scope.png", NULL);
}

void my_create_window(my_hunter_t *ht)
{
    ht->video_mode.width = 800;
    ht->video_mode.height = 600;
    ht->video_mode.bitsPerPixel = 32;
}

void my_create_rect(my_hunter_t *ht)
{
    ht->clock = sfClock_create();
    ht->x_speed = 0.2;
    ht->rect.top = 0;
    ht->rect.left = 0;
    ht->rect.width = 110;
    ht->rect.height = 110;
}

void create(my_hunter_t *ht)
{
    my_create_rect(ht);
    my_create_window(ht);
    my_create_sprite_music(ht);
    sfSprite_setTexture(ht->background, ht->texture_bg, sfTrue);
    sfSprite_setTexture(ht->duck, ht->texture_dk, sfTrue);
    sfSprite_setTexture(ht->scope, ht->texture_scope, sfTrue);
    ht->window = sfRenderWindow_create(ht->video_mode,
        "duck_hunter", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(ht->window, 60);
}

int my_rand(int min, int max)
{
    int x = -135;
    int y = (rand() % (max - min + 1)) + min;
}