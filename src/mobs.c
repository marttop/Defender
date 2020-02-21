/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** mobs
*/

#include "defender.h"

void display_round(all_t *s_all)
{
    tuto_t *temp = s_all->s_wave_c.round;
    while (temp != NULL) {
        check_path(s_all, temp), sfSprite_setPosition(temp->sprite, temp->pos);
        sfRenderWindow_drawSprite(s_all->s_game.window,
        temp->sprite, NULL), temp = temp->next;
    }
}

void display_square(all_t *s_all)
{
    tuto_t *temp = s_all->s_wave_c.square;
    while (temp != NULL) {
        check_path(s_all, temp), sfSprite_setPosition(temp->sprite, temp->pos);
        sfRenderWindow_drawSprite(s_all->s_game.window,
        temp->sprite, NULL), temp = temp->next;
    }
}

void display_triangle(all_t *s_all)
{
    tuto_t *temp = s_all->s_wave_c.triangle;
    while (temp != NULL) {
        check_path(s_all, temp), sfSprite_setPosition(temp->sprite, temp->pos);
        sfRenderWindow_drawSprite(s_all->s_game.window,
        temp->sprite, NULL), temp = temp->next;
    }
}

void push_rand_square(all_t *s_all)
{
    int i = 0;
    if (s_all->s_wave_c.seconds > 1) {
        if (s_all->s_wave_c.head->square != 0)
            i = rand() % s_all->s_wave_c.head->square + 1;
        else i = 0;
        if (s_all->s_wave_c.head->square < i) i -= 1;
        s_all->s_wave_c.head->square -= i;
        for (; i != 0; i--)
            s_all->s_wave_c.square = fill_mobs(s_all->s_wave_c.square,
            s_all, "sprites/square.png", 2);
        sfClock_restart(s_all->s_wave_c.clock);
    }
}

void push_rand_triangle(all_t *s_all)
{
    int i = 0;
    if (s_all->s_wave_c.seconds > 1) {
        if (s_all->s_wave_c.head->triangle != 0)
            i = rand() % s_all->s_wave_c.head->triangle + 1;
        else i = 0;
        if (s_all->s_wave_c.head->triangle < i) i -= 1;
        s_all->s_wave_c.head->triangle -= i;
        for (; i != 0; i--)
            s_all->s_wave_c.triangle = fill_mobs(s_all->s_wave_c.triangle,
            s_all, "sprites/triangle.png", 3);
        sfClock_restart(s_all->s_wave_c.clock);
    }
}