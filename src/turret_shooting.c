/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** turret_shooting
*/

#include "defender.h"

sfVector2f find_pos_closest(all_t *s_all, turret_t *turret)
{
    tuto_t *tmp = s_all->s_wave_c.round;
    float closest = __INT_MAX__;
    sfVector2f pos_mob;
    while (tmp != NULL) {
        float vx = tmp->pos.x - turret->pos_c.x;
        float vy = tmp->pos.y - turret->pos_c.y;
        float magnitude = sqrt(pow(vx, 2) + pow(vy, 2));
        if (magnitude < closest) {
            pos_mob = tmp->pos, closest = magnitude;
        } tmp = tmp->next;
    } tmp = s_all->s_wave_c.square;
    while (tmp != NULL) {
        float vx = tmp->pos.x - turret->pos_c.x;
        float vy = tmp->pos.y - turret->pos_c.y;
        float magnitude = sqrt(pow(vx, 2) + pow(vy, 2));
        if (magnitude < closest) {
            pos_mob = tmp->pos, closest = magnitude;
        } tmp = tmp->next;
    } tmp = s_all->s_wave_c.triangle;
    while (tmp != NULL) {
        float vx = tmp->pos.x - turret->pos_c.x;
        float vy = tmp->pos.y - turret->pos_c.y;
        float magnitude = sqrt(pow(vx, 2) + pow(vy, 2));
        if (magnitude < closest) {
            pos_mob = tmp->pos, closest = magnitude;
        } tmp = tmp->next;
    } return (pos_mob);
}

void turret_shoot2(sfVector2f pos_mob, turret_t *tmp)
{
    tmp->time = sfClock_getElapsedTime(tmp->clock);
    tmp->seconds = tmp->time.microseconds / 1000000.0;
    if (((tmp->pos_bullet.x >= pos_mob.x - 25
    && tmp->pos_bullet.x <= pos_mob.x + 25)
    && (tmp->pos_bullet.y >= pos_mob.y - 25)
    && (tmp->pos_bullet.y <= pos_mob.y + 25))
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

void turret_shoot(turret_t *tmp, sfVector2f pos_mob, float dif_angle)
{
    tmp->time = sfClock_getElapsedTime(tmp->clock);
    tmp->seconds = tmp->time.microseconds / 1000000.0;
    if (tmp->shoot == 0 && (dif_angle >= -3 && dif_angle <= 3)) {
        tmp->pos_bullet = tmp->pos_c;
        tmp->shoot = 1;
    } else if (tmp->shoot == 1 && tmp->hit == 0) {
        float vx = pos_mob.x - tmp->pos_bullet.x;
        float vy = pos_mob.y - tmp->pos_bullet.y;
        float normalise = sqrt(pow(vx, 2) + pow(vy, 2));
        tmp->pos_bullet.x = tmp->pos_bullet.x
            + (tmp->bullet_speed * (vx / normalise));
        tmp->pos_bullet.y = tmp->pos_bullet.y
            + (tmp->bullet_speed * (vy / normalise));
        sfSprite_setPosition(tmp->bullet, tmp->pos_bullet);
    } turret_shoot2(pos_mob, tmp);
}