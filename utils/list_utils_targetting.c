/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** list_utils_targetting
*/

#include "defender.h"

targetting_t *new_node_targetting(all_t *s_all, int x, char *tab)
{
    targetting_t *node;
    node = malloc(sizeof(*node));
    node->pos = (sfVector2f){x, 500};
    node->sprite = sfSprite_create();
    node->texture =
        sfTexture_createFromFile(tab, NULL);
    sfSprite_setTexture(node->sprite, node->texture, sfTrue);
    sfSprite_setPosition(node->sprite, node->pos);
    node->next = NULL;
    return (node);
}

list_targetting_t *push_back_targetting(all_t *s_all, int x, char *tab)
{
    targetting_t *node = new_node_targetting(s_all, x, tab);
    if (is_empty_list_buttons(s_all->s_buttons)) {
        s_all->s_targetting = malloc(sizeof(*s_all->s_buttons));
        s_all->s_targetting->length = 0;
        s_all->s_targetting->clock = sfClock_create();
        s_all->s_targetting->time =
            sfClock_getElapsedTime(s_all->s_buttons->clock);
        s_all->s_targetting->seconds =
            s_all->s_targetting->time.microseconds / 1000000.0;
        s_all->s_targetting->begin = node;
        s_all->s_targetting->end = node;
        sfSprite_setPosition(s_all->s_menu.sp_background, (sfVector2f){0, -50});
        black_init(s_all);
    } else {
        s_all->s_targetting->end->next = node;
        s_all->s_targetting->end = node;
    } s_all->s_targetting->length++;
    return (s_all->s_targetting);
}