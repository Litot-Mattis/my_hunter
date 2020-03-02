/*
** EPITECH PROJECT, 2019
** my_hunter-master
** File description:
** main.c
*/

#include "utilities.h"

void my_scope(my_hunter_t *ht)
{
    ht->mouse_pos = sfMouse_getPositionRenderWindow(ht->window);
    ht->scope_pos.x = ht->mouse.x;
    ht->scope_pos.y = ht->mouse.y;
}

void move_rect(my_hunter_t *ht, int offset, int max_value)
{
    if (ht->rect.left == 220)
        ht->rect.left = 0;
    else
        ht->rect.left += offset;
}

int documentation(void)
{
    my_putstr("~~HOW TO PLAY~~\n");
    my_putstr("Your are the shooter, \n");
    my_putstr("You have 3 life no less no more, \n");
    my_putstr("don't miss your targets and have fun :)\n");
}

int end_this_motherfucker(my_hunter_t *ht)
{
    sfRenderWindow_destroy(ht->window);
    sfMusic_destroy(ht->music);
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2 && (av[1][0] == 'h' || av[1][1] == 'h')) {
        documentation();
        return (0);
    }
    my_hunter_t *ht = malloc(sizeof(my_hunter_t));

    create(ht);
    sfMusic_play(ht->music);
    menu(ht);
    if (ht->quit)
        return (end_this_motherfucker(ht));
    while (sfRenderWindow_isOpen(ht->window)) {
        display(ht);
        while (sfRenderWindow_pollEvent(ht->window, &ht->event)) {
            my_event(ht);
        }
    }
    sfRenderWindow_destroy(ht->window);
    sfMusic_destroy(ht->music);
    return (0);
}