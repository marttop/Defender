/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** turret_shooting2
*/

#include "defender.h"

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
    if (turret->locked == NULL && check_in_range(turret, locked) == 1)
        turret->locked = locked;
    if (turret->locked != NULL && check_in_range(turret, locked) == 0)
        turret->locked = NULL;
}