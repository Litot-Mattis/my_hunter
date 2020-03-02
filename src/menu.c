/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** menu.c
*/

#include "utilities.h"

void set(my_hunter_t *ht)
{
    ht->s_menu = sfSprite_create();
    ht->texture_menu = sfTexture_createFromFile("imgsrc/bg_menu.png", NULL);
    sfSprite_setTexture(ht->s_menu, ht->texture_menu, sfTrue);
}

int click(my_hunter_t *ht, int x, int y)
{
    if (x >= 410 && x <= 560 && y >= 100 && y <= 140)
        return (0);
    if (x >= 650 && x <= 780 && y >= 100 && y <= 140){
        ht->quit = 1;
        return (0);
    }
    return (1);
}

int event(my_hunter_t *ht)
{
    int returnn = 1;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(ht->window);

    while (sfRenderWindow_pollEvent(ht->window, &ht->event))
        if (ht->event.type == sfEvtClosed){
            ht->quit = 1;
            return (0);
        }
    if (sfMouse_isButtonPressed(sfMouseLeft))
        returnn = click(ht, mouse.x, mouse.y);
    return (returnn);
}

void destroy(my_hunter_t *ht)
{
    sfSprite_destroy(ht->s_menu);
    sfTexture_destroy(ht->texture_menu);
}

void menu(my_hunter_t *ht)
{
    int boucle = 1;
    set(ht);
    while (boucle) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            break;
        boucle = event(ht);
        sfRenderWindow_drawSprite(ht->window, ht->s_menu, NULL);
        sfRenderWindow_display(ht->window);
    }
    destroy(ht);
}