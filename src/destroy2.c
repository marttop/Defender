/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** destroy2
*/

#include "defender.h"
#include "utils.h"

tuto_t *destroy_mob_head(tuto_t *s_tuto, all_t *s_all)
{
    tuto_t *temp = s_tuto->next;
    sfSprite_destroy(s_tuto->sprite);
    sfTexture_destroy(s_tuto->texture);
    sfClock_destroy(s_tuto->clock);
    free(s_tuto);
    s_all->s_wave_c.round = temp;
    return (temp);   
}