/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** map
*/

#include "defender.h"

void init_map(all_t *s_all)
{
    s_all->s_map.sprite = sfSprite_create();
    s_all->s_map.texture = sfTexture_createFromFile("sprites/map.png", NULL);
    sfSprite_setTexture(s_all->s_map.sprite, s_all->s_map.texture, sfTrue);
}

void display_map(all_t *s_all)
{
    sfRenderWindow_drawSprite(s_all->s_game.window, s_all->s_map.sprite, NULL);
}