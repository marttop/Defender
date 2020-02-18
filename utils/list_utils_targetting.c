/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** list_utils_targetting
*/

#include "defender.h"

int is_empty_list_targetting(list_targetting_t *li)
{
    if (li == NULL)
        return (1);
    return (0);
}

targetting_t *new_node_targetting(int x, char *tab, int i)
{
    targetting_t *node;
    node = malloc(sizeof(*node));
    node->pos = (sfVector2f){x, 200};
    node->sprite = sfSprite_create();
    node->texture =
        sfTexture_createFromFile(tab, NULL);
    sfSprite_setTexture(node->sprite, node->texture, sfTrue);
    sfSprite_setPosition(node->sprite, node->pos);
    sfSprite_setOrigin(node->sprite, (sfVector2f){50, 48});
    sfSprite_setScale(node->sprite, (sfVector2f){0.75, 0.75});
    node->next = NULL;
    node->back = NULL;
    if (i == 1) { sfSprite_setScale(node->sprite, (sfVector2f){1, 1});
        node->big = 1;
    } else node->big = 0;
    return (node);
}

list_targetting_t *push_back_targetting(all_t *s_all, int x, char *tab)
{
    static int i = 1;
    targetting_t *node = new_node_targetting(x, tab, i);
    i = 0;
    if (is_empty_list_targetting(s_all->s_targetting)) {
        s_all->s_targetting = malloc(sizeof(*s_all->s_targetting));
        s_all->s_targetting->length = 0;
        s_all->s_targetting->clock = sfClock_create();
        s_all->s_targetting->time =
            sfClock_getElapsedTime(s_all->s_targetting->clock);
        s_all->s_targetting->seconds =
            s_all->s_targetting->time.microseconds / 1000000.0;
        s_all->s_targetting->begin = node;
        s_all->s_targetting->end = node;
    } else {
        s_all->s_targetting->end->next = node;
        node->back = s_all->s_targetting->end;
        s_all->s_targetting->end = node;
    } s_all->s_targetting->length++;
    return (s_all->s_targetting);
}