/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** side_menu
*/

#include "defender.h"

void init_side_menu(all_t *s_all)
{
    s_all->s_side_menu.sprite = sfSprite_create();
    s_all->s_side_menu.clock = sfClock_create();
    s_all->s_side_menu.texture =
    sfTexture_createFromFile("sprites/side_menu.png", NULL);
    s_all->s_side_menu.texture2 =
    sfTexture_createFromFile("sprites/side_select.png", NULL);
    sfSprite_setTexture(s_all->s_side_menu.sprite,
    s_all->s_side_menu.texture, sfTrue);
    s_all->s_side_menu.pos = (sfVector2f){1790, 0};
    sfSprite_setPosition(s_all->s_side_menu.sprite, s_all->s_side_menu.pos);
    s_all->s_side_menu.slide = 0;
}

void slider_on(all_t *s_all)
{
    t_select_t *temp = s_all->s_t_select;
    targetting_t *tmp = s_all->s_targetting->begin;
    if (s_all->s_side_menu.pos.x > 1290 &&
    s_all->s_side_menu.seconds > 0.01) {
        s_all->s_side_menu.pos.x -= 50;
        sfVector2f pos = s_all->s_side_menu.pos;
        pos.x += 138, pos.y = 500;
        sfSprite_setPosition(s_all->s_side_menu.sprite,
        s_all->s_side_menu.pos);
        for (; temp != NULL; pos.x += 122) {
            temp->pos = pos;
            sfSprite_setPosition(temp->sprite, pos);
            temp = temp->next;
        }
        while (tmp != NULL) {
            tmp->pos.x -= 50;
            sfSprite_setPosition(tmp->sprite, tmp->pos);
            tmp = tmp->next;
        } sfClock_restart(s_all->s_side_menu.clock);
    }
}

void slider_off(all_t *s_all)
{
    t_select_t *temp = s_all->s_t_select;
    targetting_t *tmp = s_all->s_targetting->begin;
    if (s_all->s_side_menu.pos.x < 1790 &&
    s_all->s_side_menu.seconds > 0.01) {
        s_all->s_side_menu.pos.x += 50;
        sfVector2f pos = s_all->s_side_menu.pos;
        pos.x += 138, pos.y = 500;
        sfSprite_setPosition(s_all->s_side_menu.sprite,
        s_all->s_side_menu.pos);
        for (; temp != NULL; pos.x += 122) {
            temp->pos = pos;
            sfSprite_setPosition(temp->sprite, pos);
            temp = temp->next;
        }
        while (tmp != NULL) {
            tmp->pos.x += 50;
            sfSprite_setPosition(tmp->sprite, tmp->pos);
            tmp = tmp->next;
        } sfClock_restart(s_all->s_side_menu.clock);
    } else if (s_all->s_side_menu.pos.x >= 1790)
        s_all->s_side_menu.slide = 0;
}

void display_side_menu(all_t *s_all)
{
    if (s_all->s_selected.on == 1) {
        slider_on(s_all);
    }
    else {
        slider_off(s_all);
    }
    if (s_all->s_side_menu.slide == 1)
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_side_menu.sprite, NULL);
}