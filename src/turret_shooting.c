/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** turret_shooting
*/

#include "defender.h"

void turret_shoot2(all_t *s_all, turret_t *tmp)
{
    tmp->time = sfClock_getElapsedTime(tmp->clock);
    tmp->seconds = tmp->time.microseconds / 1000000.0;
    if (((tmp->pos_bullet.x >= s_all->s_tuto->pos.x - 15
    && tmp->pos_bullet.x <= s_all->s_tuto->pos.x + 15)
    && (tmp->pos_bullet.y >= s_all->s_tuto->pos.y - 15)
    && (tmp->pos_bullet.y <= s_all->s_tuto->pos.y + 15))
    || tmp->hit == 1) {
        tmp->hit = 1;
        sfSprite_setPosition(tmp->bullet, tmp->pos_c);
        if (tmp->seconds > tmp->rate_fire && tmp->shoot == 1) {
            tmp->shoot = 0;
            tmp->hit = 0;
            sfClock_restart(tmp->clock);
        }
    }
}

void turret_shoot(all_t *s_all, turret_t *tmp)
{
    tmp->time = sfClock_getElapsedTime(tmp->clock);
    tmp->seconds = tmp->time.microseconds / 1000000.0;
     if (tmp->shoot == 0) {
        tmp->pos_bullet = tmp->pos_c;
        tmp->shoot = 1;
    } else if (tmp->shoot == 1 && tmp->hit == 0) {
        float vx = s_all->s_tuto->pos.x - tmp->pos_bullet.x;
        float vy = s_all->s_tuto->pos.y - tmp->pos_bullet.y;
        float normalise = sqrt(pow(vx, 2) + pow(vy, 2));
        tmp->pos_bullet.x = tmp->pos_bullet.x
            + (tmp->bullet_speed * (vx / normalise));
        tmp->pos_bullet.y = tmp->pos_bullet.y
            + (tmp->bullet_speed * (vy / normalise));
        sfSprite_setPosition(tmp->bullet, tmp->pos_bullet);
    } turret_shoot2(s_all, tmp);
}