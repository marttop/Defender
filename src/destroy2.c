/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** destroy2
*/

#include "defender.h"
#include "utils.h"

tuto_t *destroy_mob_head(tuto_t *s_tuto, tuto_t *temp3, all_t *s_all)
{
    tuto_t *temp = s_tuto->next;
    if (s_tuto->scale.x > 0.1 && s_tuto->scale.y > 0.1) {
        mob_destroy_animation(s_tuto);
        return (temp);
    } else {
        sfSprite_destroy(s_tuto->sprite);
        sfTexture_destroy(s_tuto->texture);
        sfClock_destroy(s_tuto->clock);
        free(s_tuto);
        if (temp3 == s_all->s_wave_c.round)
            s_all->s_wave_c.round = temp;
        if (temp3 == s_all->s_wave_c.square)
            s_all->s_wave_c.square = temp;
        if (temp3 == s_all->s_wave_c.triangle)
            s_all->s_wave_c.triangle = temp;
        return (temp);
    }
}