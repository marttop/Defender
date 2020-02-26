/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** turret_slow
*/

#include "defender.h"

void stop_slow_call(all_t *s_all, tuto_t *mob)
{
    int check = 0;
    for (; mob != NULL; mob = mob->next) {
        check = 0;
        turret_t *turret = s_all->s_turret;
        for (; turret != NULL; turret = turret->next) {
            if (turret->type != 4) continue;
            float magnitude = calcul_magnitude(mob, turret);
            if (magnitude <= turret->range) check++;
        } if (check == 0)
            mob->check = 0, mob->slow = 0, mob->speed = mob->save_speed;
    }
}

void stop_slow(all_t *s_all)
{
    tuto_t *mob = s_all->s_wave_c.round;
    stop_slow_call(s_all, mob);
    mob = s_all->s_wave_c.square;
    stop_slow_call(s_all, mob);
    mob = s_all->s_wave_c.triangle;
    stop_slow_call(s_all, mob);
}

void slow_mobs_in_range(turret_t *turret, all_t *s_all)
{
    tuto_t *tmp = s_all->s_wave_c.round;
    for (; tmp != NULL; tmp = tmp->next) {
        float magnitude = calcul_magnitude(tmp, turret);
        if (magnitude <= turret->range && tmp->check == 0)
            tmp->slow = 1, tmp->speed -= turret->r_speed / 4, tmp->check = 1;
    } tmp = s_all->s_wave_c.square;
    for (; tmp != NULL; tmp = tmp->next) {
        float magnitude = calcul_magnitude(tmp, turret);
        if (magnitude <= turret->range && tmp->check == 0)
            tmp->slow = 1, tmp->speed -= turret->r_speed / 5, tmp->check = 1;
    } tmp = s_all->s_wave_c.triangle;
    for (; tmp != NULL; tmp = tmp->next) {
        float magnitude = calcul_magnitude(tmp, turret);
        if (magnitude <= turret->range && tmp->check == 0)
            tmp->slow = 1, tmp->speed -= turret->r_speed / 2, tmp->check = 1;
    } stop_slow(s_all);
}