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
    s_all->s_info_text.pos_txt.x += 50, s_all->s_info_text.pos_title.x += 50;
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
    sfText_setPosition(s_all->s_info_text.title_o,
        s_all->s_info_text.pos_title);
    sfText_setPosition(s_all->s_info_text.
        support_txt, s_all->s_info_text.pos_txt);
}

void slider_on3(all_t *s_all)
{
  s_all->s_sell.pos.x -= 50;
    sfSprite_setPosition(s_all->s_sell.sprite, s_all->s_sell.pos);
    s_all->s_info_text.pos_txt.x -= 50, s_all->s_info_text.pos_title.x -= 50;
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
    sfText_setPosition(s_all->s_info_text.title_o,
        s_all->s_info_text.pos_title);
    sfText_setPosition(s_all->s_info_text.
        support_txt, s_all->s_info_text.pos_txt);
}

void slider_on4(all_t *s_all)
{
    s_all->s_upgrade.pos.x -= 50;
    sfVector2f money = (sfVector2f){s_all->s_upgrade.pos.x + 350,
        s_all->s_upgrade.pos.y + 10};
    sfSprite_setPosition(s_all->s_upgrade.sprite, s_all->s_upgrade.pos);
    sfSprite_setPosition(s_all->s_upgrade.gold, money);
    if (s_all->s_selected.tur != NULL) {
        s_all->s_selected.tur->pos_xp.x -= 50;
        sfText_setPosition(s_all->s_selected.tur->name, (sfVector2f){s_all->
        s_info_text.pos_title.x, s_all->s_info_text.pos_title.y - 20});
        sfRectangleShape_setPosition(s_all->s_selected.tur->xp_bar,
            s_all->s_selected.tur->pos_xp);
        sfRectangleShape_setPosition(s_all->s_selected.tur->under,
            s_all->s_selected.tur->pos_xp);
    }
}

void slider_off4(all_t *s_all)
{
    s_all->s_upgrade.pos.x += 50;
    sfVector2f money = (sfVector2f){s_all->s_upgrade.pos.x + 350,
        s_all->s_upgrade.pos.y + 10};
    sfSprite_setPosition(s_all->s_upgrade.sprite, s_all->s_upgrade.pos);
    sfSprite_setPosition(s_all->s_upgrade.gold, money);
    if (s_all->s_selected.tur != NULL) {
        s_all->s_selected.tur->pos_xp.x += 50;
        sfText_setPosition(s_all->s_selected.tur->name, (sfVector2f){s_all->
        s_info_text.pos_title.x, s_all->s_info_text.pos_title.y - 20});
        sfRectangleShape_setPosition(s_all->s_selected.tur->xp_bar,
            s_all->s_selected.tur->pos_xp);
        sfRectangleShape_setPosition(s_all->s_selected.tur->under,
            s_all->s_selected.tur->pos_xp);
    }
}