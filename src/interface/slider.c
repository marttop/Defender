/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** slider
*/

#include "defender.h"

void slider_on2(all_t *s_all)
{
    t_select_t *temp =s_all->s_t_select;
    s_all->s_hard_arrow.pos.x -= 50;
    turret_t *temp1 = s_all->s_turret;
    targetting_t *tmp;
    sfSprite_setPosition(s_all->s_hard_arrow.sprite, s_all->s_hard_arrow.pos);
    while (temp != NULL) {
        sfText_setPosition(temp->text, (sfVector2f){temp->pos.x + 90,
        temp->pos.y + 90});
        temp = temp->next;
    }
    while (temp1 != NULL) {
        tmp = temp1->target->begin;
        while (tmp != NULL) {
            tmp->pos.x -= 50, tmp->text_pos.x -= 50;
            sfSprite_setPosition(tmp->sprite, tmp->pos);
            sfText_setPosition(tmp->str, tmp->text_pos);
            tmp = tmp->next;
        } temp1 = temp1->next;
    }
}

void slider_on1(all_t *s_all, list_targetting_t *s_targetting)
{
    s_all->s_side_menu.pos.x -= 50;
    t_select_t *temp = s_all->s_t_select;
    targetting_t *tmp = s_targetting->begin;
    sfVector2f pos = s_all->s_side_menu.pos;
    pos.x += 138, pos.y = 495;
    sfSprite_setPosition(s_all->s_side_menu.sprite, s_all->s_side_menu.pos);
    for (; temp != NULL; pos.x += 122) {
        temp->pos = pos;
        sfSprite_setPosition(temp->sprite, pos);
        temp = temp->next;
    } if (s_all->s_selected.sel != NULL &&
    (s_all->s_selected.sel->type == 'O' && s_all->s_selected.sel->on != 1))
        while (tmp != NULL) {
            tmp->pos.x -= 50, tmp->text_pos.x -= 50;
            sfSprite_setPosition(tmp->sprite, tmp->pos);
            sfText_setPosition(tmp->str, tmp->text_pos);
            tmp = tmp->next;
        } sfClock_restart(s_all->s_side_menu.clock);
    slider_on2(s_all), slider_on3(s_all);
}

void slider_off2(all_t *s_all)
{
    t_select_t *temp = s_all->s_t_select;
    s_all->s_hard_arrow.pos.x += 50;
    turret_t *temp1 = s_all->s_turret;
    targetting_t *tmp;
    sfSprite_setPosition(s_all->s_hard_arrow.sprite, s_all->s_hard_arrow.pos);
    while (temp != NULL) {
        sfText_setPosition(temp->text, (sfVector2f){temp->pos.x + 90,
        temp->pos.y + 90});
        temp = temp->next;
    }
    while (temp1 != NULL) {
        tmp = temp1->target->begin;
        while (tmp != NULL) {
            tmp->pos.x += 50, tmp->text_pos.x += 50;
            sfSprite_setPosition(tmp->sprite, tmp->pos);
            sfText_setPosition(tmp->str, tmp->text_pos);
            tmp = tmp->next;
        } temp1 = temp1->next;
    }
}

void slider_off1(all_t *s_all, list_targetting_t *s_targetting)
{
    s_all->s_side_menu.pos.x += 50;
    t_select_t *temp = s_all->s_t_select;
    targetting_t *tmp = s_targetting->begin;
    sfVector2f pos = s_all->s_side_menu.pos;
    pos.x += 138, pos.y = 495;
    sfSprite_setPosition(s_all->s_side_menu.sprite, s_all->s_side_menu.pos);
    for (; temp != NULL; pos.x += 122) {
        temp->pos = pos, sfSprite_setPosition(temp->sprite, pos);
        temp = temp->next;
    } if (s_all->s_selected.sel != NULL &&
    (s_all->s_selected.sel->type == 'O' && s_all->s_selected.sel->on != 1))
        while (tmp != NULL) {
            tmp->pos.x += 50, tmp->text_pos.x += 50;
            sfSprite_setPosition(tmp->sprite, tmp->pos);
            sfText_setPosition(tmp->str, tmp->text_pos);
            tmp = tmp->next;
        } sfClock_restart(s_all->s_side_menu.clock);
    slider_off2(s_all), slider_off3(s_all);
}