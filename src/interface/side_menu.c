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
    s_all->s_side_menu.draw = 0;
}

void slider_on(all_t *s_all)
{
    if (s_all->s_side_menu.pos.x > 1290 && s_all->s_side_menu.seconds > 0.01) {
        slider_on1(s_all);
    }
}

void slider_off(all_t *s_all)
{
    if (s_all->s_side_menu.pos.x < 1790 && s_all->s_side_menu.seconds > 0.01) {
        slider_off1(s_all);
    } else if (s_all->s_side_menu.pos.x >= 1790)
        s_all->s_side_menu.slide = 0;
}

void display_side_menu(all_t *s_all)
{
    if (s_all->s_selected2.click == 1) {
        if (s_all->s_selected2.zone != NULL)
            sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_selected2.zone->sprite_a, NULL);
    }
    if (s_all->s_hard_arrow.stat == 0) {
        slider_on(s_all);
    }
    else if (s_all->s_hard_arrow.stat == 1) {
        slider_off(s_all);
    }
    if (s_all->s_side_menu.draw == 1)
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_side_menu.sprite, NULL);
}