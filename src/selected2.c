/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** selected2
*/

#include "defender.h"
#include "utils.h"

void init_selected(all_t *s_all)
{
    s_all->s_selected.on = 0;
    s_all->s_selected.sprite = sfSprite_create();
    s_all->s_selected.clicked_s = sfSprite_create();
    s_all->s_selected.texture =
    sfTexture_createFromFile("sprites/selected.png", NULL);
    s_all->s_selected.clicked =
    sfTexture_createFromFile("sprites/clicked.png", NULL);
    sfSprite_setTexture(s_all->s_selected.sprite,
    s_all->s_selected.texture, sfTrue);
    sfSprite_setTexture(s_all->s_selected.clicked_s,
    s_all->s_selected.clicked, sfTrue);
    s_all->s_selected.pos2 = (sfVector2f){0, 0};
    s_all->s_selected.type = ' ';
}