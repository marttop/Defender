/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** targetting
*/

#include "defender.h"

void list_targetting(all_t *s_all)
{
    char *tab[5];
    tab[0] = "sprites/buttons/FIRST.png";
    tab[1] = "sprites/buttons/LAST.png";
    tab[2] = "sprites/buttons/WEAKEST.png";
    tab[3] = "sprites/buttons/STRONGEST.png";
    tab[4] = "sprites/buttons/NEAREST.png";
    s_all->s_targetting = NULL;
    for (int i = 0, x = 1520; i != 5; i++, x += 75) {
        s_all->s_targetting = push_back_targetting(s_all, x, tab[i]);
    }
}

void display_targetting_buttons(all_t *s_all)
{
    targetting_t *tmp = s_all->s_targetting->begin;
    while (tmp != NULL) {
        if (tmp->big == 0) {
            sfSprite_setColor(tmp->sprite, (sfColor){125, 125, 125, 255});
            sfRenderWindow_drawSprite(s_all->s_game.window, tmp->sprite, NULL);
        } tmp = tmp->next;
    } tmp = s_all->s_targetting->begin;
    while (tmp != NULL) {
        if (tmp->big == 1) {
            sfSprite_setColor(tmp->sprite, (sfColor){255, 255, 255, 255});
            sfRenderWindow_drawSprite(s_all->s_game.window, tmp->sprite, NULL);
        } tmp = tmp->next;
    }
}

void hitbox_change_targetting_back(all_t *s_all)
{
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if ((mouse_pos.x >= 1665 && mouse_pos.x <= 1692)
        && (mouse_pos.y >= 419 && mouse_pos.y <= 454)) {
        targetting_t *tmp = s_all->s_targetting->begin;
        while (tmp != NULL && tmp->big == 0) {
            tmp = tmp->next;
        } if (tmp->back != NULL) { 
            sfSprite_setScale(tmp->sprite, (sfVector2f){0.75, 0.75});
            sfSprite_setScale(tmp->back->sprite, (sfVector2f){1, 1});
            tmp->back->big = 1;
            tmp->big = 0;
        } else {
            sfSprite_setScale(tmp->sprite, (sfVector2f){0.75, 0.75});
            sfSprite_setScale(s_all->s_targetting->end->sprite,
                (sfVector2f){1, 1});
            s_all->s_targetting->end->big = 1;
            tmp->big = 0;
        }
    }
}

void hitbox_change_targetting_next(all_t *s_all)
{
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if ((mouse_pos.x >= 1868 && mouse_pos.x <= 1893)
        && (mouse_pos.y >= 417 && mouse_pos.y <= 455)) {
        targetting_t *tmp = s_all->s_targetting->begin;
        while (tmp != NULL && tmp->big == 0) {
            tmp = tmp->next;
        } if (tmp->next != NULL) { 
            sfSprite_setScale(tmp->sprite, (sfVector2f){0.75, 0.75});
            sfSprite_setScale(tmp->next->sprite, (sfVector2f){1, 1});
            tmp->next->big = 1;
            tmp->big = 0;
        } else {
            sfSprite_setScale(tmp->sprite, (sfVector2f){0.75, 0.75});
            sfSprite_setScale(s_all->s_targetting->begin->sprite,
                (sfVector2f){1, 1});
            s_all->s_targetting->begin->big = 1;
            tmp->big = 0;
        }
    }
}