/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** turret_shooting2
*/

#include "defender.h"
#include "utils.h"

int check_in_range(turret_t *turret, tuto_t *locked)
{
    if (locked != NULL) {
        float vx = locked->pos.x - turret->pos_bullet.x;
        float vy = locked->pos.y - turret->pos_bullet.y;
        float magnitude = sqrt(pow(vx, 2) + pow(vy, 2));
        if (magnitude <= turret->range)
            return (1);
    } return (0);
}

void lock_target_in_range(turret_t *turret, tuto_t *locked)
{
    if (turret->locked == NULL)
        turret->locked = locked;
    if (turret->locked != NULL
    && check_in_range(turret, turret->locked) == 0) {
        turret->locked = NULL;
        turret->pos_bullet = turret->pos_c;
        sfSprite_setPosition(turret->bullet, turret->pos_bullet);
    }
}

void find_pos_last2(all_t *s_all, turret_t *turret, tuto_t **locked1,
    tuto_t *tmp)
{
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->state == -1) continue;
        float len = calcul_magnitude(tmp, turret);
        if (len <= turret->range) { *locked1 = tmp;
            break; }
    } tmp = s_all->s_wave_c.square;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->state == -1) continue;
        float len = calcul_magnitude(tmp, turret);
        if (len <= turret->range && *locked1 == NULL) { *locked1 = tmp;
            break;
        } else if (len <= turret->range && locked1 != NULL) {
            if ((*locked1)->nb < tmp->nb) *locked1 = tmp;
            break; }
    }
}

void find_pos_last(all_t *s_all, turret_t *turret)
{
    tuto_t *locked1 = NULL, *tmp = s_all->s_wave_c.round;
    find_pos_last2(s_all, turret, &locked1, tmp);
    tmp = s_all->s_wave_c.triangle;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->state == -1) continue;
        float len = calcul_magnitude(tmp, turret);
        if (len <= turret->range && locked1 == NULL) { locked1 = tmp;
            break;
        } else if (len <= turret->range && locked1 != NULL) {
            if (locked1->nb < tmp->nb) locked1 = tmp;
            break; }
    } lock_target_in_range(turret, locked1);
}

void slow_mobs_in_range(turret_t *turret, all_t *s_all)
{
    tuto_t *tmp = s_all->s_wave_c.round;
    for (; tmp != NULL; tmp = tmp->next) {
        float magnitude = calcul_magnitude(tmp, turret);
        if (magnitude <= turret->range && tmp->speed == tmp->save_speed) {
            tmp->slow = 1, tmp->speed -= turret->r_speed / 2;
            sfRenderWindow_drawSprite(s_all->s_game.window, tmp->snow, NULL);
        } else tmp->speed = tmp->save_speed, tmp->slow = 0;
    } tmp = s_all->s_wave_c.square;
    for (; tmp != NULL; tmp = tmp->next) {
        float magnitude = calcul_magnitude(tmp, turret);
        if (magnitude <= turret->range && tmp->speed == tmp->save_speed) {
            tmp->slow = 1, tmp->speed -= turret->r_speed / 3;
            sfRenderWindow_drawSprite(s_all->s_game.window, tmp->snow, NULL);
        } else tmp->speed = tmp->save_speed, tmp->slow = 0;
    } tmp = s_all->s_wave_c.triangle;
    for (; tmp != NULL; tmp = tmp->next) {
        float magnitude = calcul_magnitude(tmp, turret);
        if (magnitude <= turret->range && tmp->speed == tmp->save_speed) {
            tmp->slow = 1, tmp->speed -= turret->r_speed;
            sfRenderWindow_drawSprite(s_all->s_game.window, tmp->snow, NULL);
        } else tmp->speed = tmp->save_speed, tmp->slow = 0;
    }
}