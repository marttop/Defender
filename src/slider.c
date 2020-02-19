/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** slider
*/

#include "defender.h"

void slider_on1(all_t *s_all)
{
    s_all->s_side_menu.pos.x -= 50;
    t_select_t *temp = s_all->s_t_select;
    targetting_t *tmp = s_all->s_targetting->begin;
    sfVector2f pos = s_all->s_side_menu.pos;
    pos.x += 138, pos.y = 495;
    sfSprite_setPosition(s_all->s_side_menu.sprite, s_all->s_side_menu.pos);
    for (; temp != NULL; pos.x += 122) {
        temp->pos = pos;
        sfSprite_setPosition(temp->sprite, pos);
        temp = temp->next;
    }
    while (tmp != NULL) {
        tmp->pos.x -= 50, tmp->text_pos.x -= 50;
        sfSprite_setPosition(tmp->sprite, tmp->pos);
        sfText_setPosition(tmp->str, tmp->text_pos);
        tmp = tmp->next;
    } sfClock_restart(s_all->s_side_menu.clock);
}

void slider_off1(all_t *s_all)
{
    s_all->s_side_menu.pos.x += 50;
    t_select_t *temp = s_all->s_t_select;
    targetting_t *tmp = s_all->s_targetting->begin;
    sfVector2f pos = s_all->s_side_menu.pos;
    pos.x += 138, pos.y = 495;
    sfSprite_setPosition(s_all->s_side_menu.sprite, s_all->s_side_menu.pos);
    for (; temp != NULL; pos.x += 122) {
        temp->pos = pos, sfSprite_setPosition(temp->sprite, pos);
        temp = temp->next;
    }
    while (tmp != NULL) {
        tmp->pos.x += 50, tmp->text_pos.x += 50;
        sfSprite_setPosition(tmp->sprite, tmp->pos);
        sfText_setPosition(tmp->str, tmp->text_pos);
        tmp = tmp->next;
    } sfClock_restart(s_all->s_side_menu.clock);
}