/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** slider2
*/

#include "defender.h"

void slider_off3(all_t *s_all)
{
    s_all->s_sell.pos.x += 50;
    sfSprite_setPosition(s_all->s_sell.sprite, s_all->s_sell.pos);
    s_all->s_info_text.pos_txt.x += 50;
    s_all->s_info_text.pos_title.x += 50;
    sfText_setPosition(s_all->s_info_text.castle_txt,
    s_all->s_info_text.pos_txt);
    sfText_setPosition(s_all->s_info_text.ground_txt,
    s_all->s_info_text.pos_txt);
    sfText_setPosition(s_all->s_info_text.spawner_txt,
    s_all->s_info_text.pos_txt);
    sfText_setPosition(s_all->s_info_text.title_c,
     s_all->s_info_text.pos_title);
    sfText_setPosition(s_all->s_info_text.title_g,
     s_all->s_info_text.pos_title);
    sfText_setPosition(s_all->s_info_text.title_s,
     s_all->s_info_text.pos_title);
}

void slider_on3(all_t *s_all)
{
    s_all->s_sell.pos.x -= 50;
    sfSprite_setPosition(s_all->s_sell.sprite, s_all->s_sell.pos);
    s_all->s_info_text.pos_txt.x -= 50;
    s_all->s_info_text.pos_title.x -= 50;
    sfText_setPosition(s_all->s_info_text.castle_txt,
    s_all->s_info_text.pos_txt);
    sfText_setPosition(s_all->s_info_text.ground_txt,
    s_all->s_info_text.pos_txt);
    sfText_setPosition(s_all->s_info_text.spawner_txt,
    s_all->s_info_text.pos_txt);
    sfText_setPosition(s_all->s_info_text.title_c,
     s_all->s_info_text.pos_title);
    sfText_setPosition(s_all->s_info_text.title_g,
     s_all->s_info_text.pos_title);
    sfText_setPosition(s_all->s_info_text.title_s,
     s_all->s_info_text.pos_title);
}