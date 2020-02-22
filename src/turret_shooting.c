/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** turret_shooting
*/

#include "defender.h"

void find_pos_closest2(all_t *s_all, turret_t *turret, float *closest,
    tuto_t **locked)
{
    tuto_t *tmp = s_all->s_wave_c.round;
    while (tmp != NULL) {
        float vx = tmp->pos.x - turret->pos_c.x;
        float vy = tmp->pos.y - turret->pos_c.y;
        float magnitude = sqrt(pow(vx, 2) + pow(vy, 2));
        if (magnitude < *closest) {
           *closest = magnitude, *locked = tmp;
        } tmp = tmp->next;
    }
}

void find_pos_closest(all_t *s_all, turret_t *turret)
{
    float closest = __INT_MAX__;
    tuto_t *locked = NULL, *tmp = s_all->s_wave_c.square;
    find_pos_closest2(s_all, turret, &closest, &locked);
    while (tmp != NULL) {
        float vx = tmp->pos.x - turret->pos_bullet.x;
        float vy = tmp->pos.y - turret->pos_bullet.y;
        float magnitude = sqrt(pow(vx, 2) + pow(vy, 2));
        if (magnitude < closest) {
            closest = magnitude, locked = tmp;
        } tmp = tmp->next;
    } tmp = s_all->s_wave_c.triangle;
    while (tmp != NULL) {
        float vx = tmp->pos.x - turret->pos_c.x;
        float vy = tmp->pos.y - turret->pos_c.y;
        float magnitude = sqrt(pow(vx, 2) + pow(vy, 2));
        if (magnitude < closest) {
            closest = magnitude, locked = tmp;
        } tmp = tmp->next;
    } if (turret->locked == NULL) turret->locked = locked;
}

void turret_shoot2(turret_t *tmp)
{
    tmp->time = sfClock_getElapsedTime(tmp->clock);
    tmp->seconds = tmp->time.microseconds / 1000000.0;
    if (tmp->locked != NULL && (((tmp->pos_bullet.x >= tmp->locked->pos.x - 25
    && tmp->pos_bullet.x <= tmp->locked->pos.x + 25) && (tmp->pos_bullet.y >=
    tmp->locked->pos.y - 25) && (tmp->pos_bullet.y <= tmp->locked->pos.y + 25))
    || tmp->hit == 1)) {
        tmp->hit = 1;
        tmp->locked->state = -1;
        sfSprite_setPosition(tmp->bullet, tmp->pos_c);
        if (tmp->seconds > tmp->rate_fire && tmp->shoot == 1) {
            tmp->shoot = 0;
            tmp->hit = 0;
            tmp->locked = NULL;
            sfClock_restart(tmp->clock);
        }
    }
}

void turret_shoot(turret_t *tmp, float dif_angle)
{
    tmp->time = sfClock_getElapsedTime(tmp->clock);
    tmp->seconds = tmp->time.microseconds / 1000000.0;
    if (tmp->shoot == 0 && (dif_angle >= -3 && dif_angle <= 3)) {
        tmp->pos_bullet = tmp->pos_c;
        tmp->shoot = 1;
    } else if (tmp->shoot == 1 && tmp->hit == 0) {
        float vx = tmp->locked->pos.x - tmp->pos_bullet.x;
        float vy = tmp->locked->pos.y - tmp->pos_bullet.y;
        float normalise = sqrt(pow(vx, 2) + pow(vy, 2));
        tmp->pos_bullet.x = tmp->pos_bullet.x
            + (tmp->bullet_speed * (vx / normalise));
        tmp->pos_bullet.y = tmp->pos_bullet.y
            + (tmp->bullet_speed * (vy / normalise));
        sfSprite_setPosition(tmp->bullet, tmp->pos_bullet);
    } turret_shoot2(tmp);
}