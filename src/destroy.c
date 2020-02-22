/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** destroy
*/

#include "defender.h"
#include "utils.h"

void destroy_regroup(all_t *s_all)
{
    destroy_music(s_all);
}

int mob_destroy_animation(tuto_t *s_tuto)
{
    s_tuto->scale.x -= (s_tuto->seconds + 0.04);
    s_tuto->scale.y -= (s_tuto->seconds + 0.04);
    sfSprite_setScale(s_tuto->sprite, s_tuto->scale);
    return (0);
}

tuto_t *free_node(tuto_t *s_tuto, tuto_t *prev)
{
    tuto_t *temp = s_tuto->next;
    if (temp == NULL) {
        if (s_tuto->scale.x > 0.1 && s_tuto->scale.y > 0.1)
            mob_destroy_animation(s_tuto);
        else {
            prev->next = s_tuto->next;
            sfTexture_destroy(s_tuto->texture), sfClock_destroy(s_tuto->clock);
            sfSprite_destroy(s_tuto->sprite), free(s_tuto);
        } return (NULL);
    } if (s_tuto->scale.x > 0.1 && s_tuto->scale.y > 0.1) {
        mob_destroy_animation(s_tuto);
        return (s_tuto->next);
    } else {
        prev->next = s_tuto->next;
        sfSprite_destroy(s_tuto->sprite), sfTexture_destroy(s_tuto->texture);
        sfClock_destroy(s_tuto->clock), free(s_tuto);
    } return (prev->next);
}

void free_node2(all_t *s_all, tuto_t *temp)
{
    if (temp->scale.x > 0.1 && temp->scale.y > 0.1) {
        mob_destroy_animation(temp);
        return;
    }
    else {
        sfSprite_destroy(temp->sprite);
        sfTexture_destroy(temp->texture);
        sfClock_destroy(temp->clock);
        free(temp);
        s_all->s_wave_c.round = NULL;
    }
}

void check_destroy_ball(all_t *s_all)
{
    tuto_t *temp = s_all->s_wave_c.round;
    tuto_t *temp2;
    while (temp != NULL) {
        if (temp->state == -1 && (linked_len(s_all->s_wave_c.round) > 1)) {
            temp = free_node(temp, temp2);
            continue;
        }
        if (temp->state == -1 && (linked_len(s_all->s_wave_c.round) == 1)) {
            free_node2(s_all, temp);
            break;
        }
        temp2 = temp;
        temp = temp->next;
    }
}