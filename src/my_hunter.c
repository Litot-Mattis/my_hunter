/*
** EPITECH PROJECT, 2019
** my_hunter-master
** File description:
** my_hunter.c
*/

#include "utilities.h"

void rand_axis_y(my_hunter_t *ht)
{
    sfSprite_setTextureRect(ht->duck, ht->rect);
    if (sfSprite_getPosition(ht->duck).x > 800)
        sfSprite_setPosition(ht->duck, (sfVector2f){-135, my_rand(100, 400)});
}

void clock(my_hunter_t *ht)
{
    ht->time = sfClock_getElapsedTime(ht->clock);
    ht->seconde = ht->time.microseconds / 1000000.0;
    if (ht->seconde > ht->x_speed) {
        move_rect(ht, 110, 220);
        sfClock_restart(ht->clock);
    }
}

void display(my_hunter_t *ht)
{
    rand_axis_y(ht);
    my_scope(ht);
    sfSprite_setScale(ht->scope, ht->scale_scope);
    sfSprite_setPosition(ht->scope, ht->scope_pos);
    sfRenderWindow_drawSprite(ht->window, ht->background, NULL);
    sfRenderWindow_drawSprite(ht->window, ht->duck, NULL);
    sfRenderWindow_drawSprite(ht->window, ht->scope, NULL);
    sfSprite_move(ht->duck, (sfVector2f){3, 0});
    clock(ht);
    sfRenderWindow_display(ht->window);
}

void duck_unpop(my_hunter_t *ht)
{
    int i = 110;
    int x = -135;

    if (ht->mouse.x >= ht->duck_pos.x && ht->mouse.x <= ht->duck_pos.x + i) {
        if (ht->mouse.y >= ht->duck_pos.y && ht->mouse.y <= ht->duck_pos.y + i)
            sfSprite_setPosition(ht->duck, (sfVector2f) {x, my_rand(i, 400)});
    }
}

void my_event(my_hunter_t *ht)
{
    int i = ht->event.mouseButton.button;

    if (ht->event.type == sfEvtClosed)
        sfRenderWindow_close(ht->window);
    ht->mouse.x = sfMouse_getPositionRenderWindow(ht->window).x;
    ht->mouse.y = sfMouse_getPositionRenderWindow(ht->window).y;
    ht->duck_pos = sfSprite_getPosition(ht->duck);
    if (ht->event.type == sfEvtMouseButtonPressed && i == sfMouseLeft)
        duck_unpop(ht);
}