/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** list_utils_targetting2
*/

#include "defender.h"

list_targetting_t *push_back_turret_targetting(turret_t *tmp, int x,
    char *tab, int big)
{
    static int incre = 0, i = 0, k = 0;
    if (k == 5) k = 0, incre = 0, i = 0;
    if (incre == big) i = 1;
    targetting_t *node = new_node_turret_targetting(x, tab, i);
    if (is_empty_list_targetting(tmp->target)) {
        tmp->target = malloc(sizeof(*tmp->target));
        tmp->target->length = 0;
        tmp->target->clock = sfClock_create();
        tmp->target->time =
            sfClock_getElapsedTime(tmp->target->clock);
        tmp->target->seconds =
            tmp->target->time.microseconds / 1000000.0;
        tmp->target->begin = node, tmp->target->end = node;
    } else {
        tmp->target->end->next = node;
        node->back = tmp->target->end;
        tmp->target->end = node;
    } tmp->target->length++;
    i = 0, tmp->target->size = 50, incre++, k++;
    return (tmp->target);
}