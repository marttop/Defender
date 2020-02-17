/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** destroy
*/

#include "defender.h"

void destroy_regroup(all_t *s_all)
{
    destroy_music(s_all);
}

void free_node(balls_t *s_balls)
{
    balls_t *temp = s_balls->next;
    s_balls->next = temp->next;
    sfSprite_destroy(temp->sprite);
    sfTexture_destroy(temp->texture);
    sfClock_destroy(temp->clock);
    free(temp);
}

void check_destroy_ball(all_t *s_all)
{
    balls_t *temp = s_all->s_balls;
    while (temp != NULL) {
        if (temp->next != NULL)
            if (temp->next->state == -1) free_node(temp);
        temp = temp->next;
    }
}