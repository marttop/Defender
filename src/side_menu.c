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
    sfSprite_setPosition(s_all->s_side_menu.sprite, (sfVector2f){1420, 0});
}

void display_side_menu(all_t *s_all)
{
    if (s_all->s_selected.on == 1) {
        sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_side_menu.sprite, NULL);
    }
}