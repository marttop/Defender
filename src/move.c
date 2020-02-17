/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** move
*/

#include "utils.h"
#include "defender.h"

void move_up(balls_t *s_balls, int len)
{
    if (s_balls->seconds > 0.01) {
        if (s_balls->increment != 0) {
            s_balls->pos.y -= s_balls->speed;
            s_balls->increment -= s_balls->speed;
        } else {
            s_balls->previous = 'U';
            s_balls->map_pos -= len;
            s_balls->increment = 120;
        }
        sfClock_restart(s_balls->clock);
    }
}

void move_down(balls_t *s_balls, int len)
{
    if (s_balls->seconds > 0.01) {
        if (s_balls->increment != 0) {
            s_balls->pos.y += s_balls->speed;
            s_balls->increment -= s_balls->speed;
        } else {
            s_balls->previous = 'D';
            s_balls->map_pos += len;
            s_balls->increment = 120;
        }
        sfClock_restart(s_balls->clock);
    }
}

void move_left(balls_t *s_balls)
{
    if (s_balls->seconds > 0.01) {
        if (s_balls->increment != 0) {
            s_balls->pos.x -= s_balls->speed;
            s_balls->increment -= s_balls->speed;
        } else {
            s_balls->previous = 'L';
            s_balls->map_pos -= 1;
            s_balls->increment = 120;
        }
        sfClock_restart(s_balls->clock);
    }
}

void move_right(balls_t *s_balls)
{
    if (s_balls->seconds > 0.01) {
        if (s_balls->increment != 0) {
            s_balls->pos.x += s_balls->speed;
            s_balls->increment -= s_balls->speed;
        } else {
            s_balls->previous = 'R';
            s_balls->map_pos += 1;
            s_balls->increment = 120;
        }
        sfClock_restart(s_balls->clock);
    }
}