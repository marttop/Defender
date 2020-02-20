/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** turret_rotate
*/

#include "defender.h"
#include "utils.h"

void rotate_turret_maths(all_t *s_all)
{
    if (s_all->s_turret != NULL) {
        turret_t *tmp = s_all->s_turret;
        while (tmp != NULL) {
            float angle = atan2(s_all->s_tuto->pos.y - (tmp->pos.y + 60),
                s_all->s_tuto->pos.x - (tmp->pos.x + 60));
            angle = angle * 180 / MY_PI;
            if (tmp->rotate <= angle + 89)
                tmp->rotate += 2;
            else if (tmp->rotate >= angle + 92 && tmp->rotate <= 270)
                tmp->rotate -= 2;
            sfSprite_setRotation(tmp->sprite_c, tmp->rotate);
            tmp = tmp->next;
            printf("%f\n", angle);
        }
    }
}