/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** turret_rotate
*/

#include "defender.h"
#include "utils.h"

void rotate_turret_maths2(turret_t *tmp, float dif_angle)
{
    float speed = 2, speed_rad = 0.0349066;
    if (dif_angle > 2 || dif_angle < -2) {
        if ((dif_angle < 0 && dif_angle >= -180)
        || (dif_angle < 360 && dif_angle >= 180)) {
            if (tmp->rotate > 360) tmp->rotate -= 360;
            tmp->pos_c2.x = ((tmp->pos_c2.x - tmp->pos_c.x) * cos(speed_rad))
            - ((tmp->pos_c2.y - tmp->pos_c.y) * sin(speed_rad)) + tmp->pos_c.x;
            tmp->pos_c2.y = ((tmp->pos_c2.y - tmp->pos_c.y) * cos(speed_rad))
            + ((tmp->pos_c2.x - tmp->pos_c.x) * sin(speed_rad)) + tmp->pos_c.y;
            tmp->rotate += speed;
        } else {
            if (tmp->rotate > 360) tmp->rotate -= 360;
            tmp->pos_c2.x = ((tmp->pos_c2.x - tmp->pos_c.x)
            * cos(speed_rad * -1)) - ((tmp->pos_c2.y - tmp->pos_c.y)
            * sin(speed_rad * -1)) + tmp->pos_c.x;
            tmp->pos_c2.y = ((tmp->pos_c2.y - tmp->pos_c.y)
            * cos(speed_rad * -1)) + ((tmp->pos_c2.x - tmp->pos_c.x)
            * sin(speed_rad * -1)) + tmp->pos_c.y, tmp->rotate -= speed;
        } sfSprite_setRotation(tmp->sprite_c, tmp->rotate);
    }
}

void rotate_turret_maths(all_t *s_all)
{
    if (s_all->s_turret != NULL) {
        turret_t *tmp = s_all->s_turret;
        while (tmp != NULL) {
            float angle_mob = atan2(s_all->s_tuto->pos.y - (tmp->pos_c.y),
                s_all->s_tuto->pos.x - (tmp->pos_c.x));
            float angle_turret = atan2(tmp->pos_c2.y - (tmp->pos_c.y),
                tmp->pos_c2.x - (tmp->pos_c.x));
            angle_mob = angle_mob * 180 / MY_PI;
            angle_turret = angle_turret * 180 / MY_PI;
            if (angle_mob < 0) angle_mob = 360 + angle_mob;
            if (angle_turret < 0) angle_turret = 360 + angle_turret;
            float dif_angle = angle_turret - angle_mob;
            if (tmp->rotate > 360) tmp->rotate -= 360;
            rotate_turret_maths2(tmp, dif_angle);
            tmp = tmp->next;
        }
    }
}