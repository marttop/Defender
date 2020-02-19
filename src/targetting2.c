/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** targetting2
*/

#include "defender.h"

void keep_centered_targetting3(all_t *s_all, targetting_t *tmp, int big_pos)
{
    if (big_pos == 4) {
        s_all->s_targetting->begin->pos.x = (tmp->pos.x +
            (s_all->s_targetting->size * 2));
        s_all->s_targetting->begin->next->pos.x =
            (tmp->pos.x - (s_all->s_targetting->size * 2));
        sfSprite_setPosition(s_all->s_targetting->begin->sprite, s_all->
        s_targetting->begin->pos), sfSprite_setPosition(s_all->s_targetting->
        begin->next->sprite, s_all->s_targetting->begin->next->pos);
    } if (big_pos == 5) {
        tmp->back->back->pos.x =
            (tmp->pos.x - (s_all->s_targetting->size * 2));
        s_all->s_targetting->begin->pos.x =
            (tmp->pos.x + (s_all->s_targetting->size));
        s_all->s_targetting->begin->next->pos.x = (tmp->pos.x +
            (s_all->s_targetting->size * 2));
        sfSprite_setPosition(s_all->s_targetting->begin->sprite, s_all->
        s_targetting->begin->pos), sfSprite_setPosition(s_all->s_targetting->
        begin->next->sprite, s_all->s_targetting->begin->next->pos);
        sfSprite_setPosition(tmp->back->back->sprite, tmp->back->back->pos);
    }
}

void keep_centered_targetting2(all_t *s_all, targetting_t *tmp, int big_pos)
{
    if (big_pos == 2) {
        s_all->s_targetting->end->pos.x = (tmp->pos.x -
            (s_all->s_targetting->size * 2));
        tmp->next->next->pos.x =
            (tmp->pos.x + (s_all->s_targetting->size * 2));
        sfSprite_setPosition(tmp->next->next->sprite, tmp->next->next->pos);
        sfSprite_setPosition(s_all->s_targetting->end->sprite,
            s_all->s_targetting->end->pos);
    } if (big_pos == 3) {
        s_all->s_targetting->begin->pos.x = (tmp->pos.x -
            (s_all->s_targetting->size * 2));
        tmp->next->next->pos.x =
            (tmp->pos.x + (s_all->s_targetting->size * 2));
        sfSprite_setPosition(tmp->next->next->sprite,
            tmp->next->next->pos);
        sfSprite_setPosition(s_all->s_targetting->begin->sprite,
            s_all->s_targetting->begin->pos);
    }
}

void keep_centered_targetting(all_t *s_all)
{
    targetting_t *tmp = s_all->s_targetting->begin;
    int big_pos = 1;
    while (tmp != NULL && tmp->big != 1) {
        big_pos++;
        tmp = tmp->next;
    } tmp = s_all->s_targetting->begin;
    while (tmp != NULL && tmp->big != 1) tmp = tmp->next;
    if (big_pos == 1) {
        tmp->next->next->next->next->pos.x =
            (tmp->pos.x - s_all->s_targetting->size);
        tmp->next->next->next->pos.x =
            (tmp->pos.x - (s_all->s_targetting->size * 2));
        tmp->next->next->pos.x =
            (tmp->pos.x + (s_all->s_targetting->size * 2));
        sfSprite_setPosition(tmp->next->next->next->next->sprite, tmp->next->
        next->next->next->pos), sfSprite_setPosition(tmp->next->next->next->
        sprite, tmp->next->next->next->pos), sfSprite_setPosition(tmp->next->
        next->sprite, tmp->next->next->pos);
    } keep_centered_targetting2(s_all, tmp, big_pos);
    keep_centered_targetting3(s_all, tmp, big_pos);
}