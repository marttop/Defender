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

void free_node(tuto_t *s_tuto)
{
    tuto_t *temp = s_tuto->next;
    s_tuto->next = temp->next;
    sfSprite_destroy(temp->sprite);
    sfTexture_destroy(temp->texture);
    sfClock_destroy(temp->clock);
    free(temp);
}

void check_destroy_ball(all_t *s_all)
{
    tuto_t *temp = s_all->s_tuto;
    while (temp != NULL) {
        if (temp->next != NULL)
            if (temp->next->state == -1) free_node(temp);
        temp = temp->next;
    }
}