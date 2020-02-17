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
    sfSprite_setTexture(s_all->s_side_menu.sprite,
    s_all->s_side_menu.texture, sfTrue);
    s_all->s_side_menu.pos = (sfVector2f){1920, 0};
    sfSprite_setPosition(s_all->s_side_menu.sprite, s_all->s_side_menu.pos);
}

void slider_on(all_t *s_all)
{
    if (s_all->s_side_menu.pos.x > 1420 &&
    s_all->s_side_menu.seconds > 0.01) {
        s_all->s_side_menu.pos.x -= 20;
        sfSprite_setPosition(s_all->s_side_menu.sprite,
        s_all->s_side_menu.pos);
        sfClock_restart(s_all->s_side_menu.clock);
    }
    sfRenderWindow_drawSprite(s_all->s_game.window,
    s_all->s_side_menu.sprite, NULL);
}

void slider_off(all_t *s_all)
{
    s_all->s_side_menu.pos = (sfVector2f){1920, 0};
    sfSprite_setPosition(s_all->s_side_menu.sprite, (sfVector2f){1920, 0});
}

void display_side_menu(all_t *s_all)
{
    if (s_all->s_selected.on == 1) {
        slider_on(s_all);
    }
    else {
        slider_off(s_all);
    }
}