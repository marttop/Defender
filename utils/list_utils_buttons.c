/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** menu_buttons
*/

#include "defender.h"

list_buttons_t *new_list_buttons(void)
{
    return (NULL);
}

int is_empty_list_buttons(list_buttons_t *li)
{
    if (li == NULL)
        return (1);
    return (0);
}

node_buttons_t *new_node_buttons(char *tab, char *tab2, int y)
{
    node_buttons_t *node;
    node = malloc(sizeof(*node));
    node->who = 0;
    node->pos = (sfVector2f){1820, y};
    node->sprite = sfSprite_create();
    node->texture = sfTexture_createFromFile(tab, NULL);
    node->texture2 = sfTexture_createFromFile(tab2, NULL);
    sfSprite_setTexture(node->sprite, node->texture, sfTrue);
    sfSprite_setPosition(node->sprite, node->pos);
    node->next = NULL;
    return (node);
}

list_buttons_t *push_back_buttons(list_buttons_t *li, char *tab,
    char *tab2, int y)
{
    node_buttons_t *node = new_node_buttons(tab, tab2, y);
    if (is_empty_list_buttons(li)) {
        li = malloc(sizeof(*li));
        li->length = 0;
        li->clock = sfClock_create();
        li->time = sfClock_getElapsedTime(li->clock);
        li->seconds = li->time.microseconds / 1000000.0;
        li->begin = node;
        li->end = node;
    } else {
        li->end->next = node;
        li->end = node;
    } li->length++;
    return (li);
}

list_buttons_t *pop_front_buttons(list_buttons_t *li)
{
    if (is_empty_list_buttons(li))
        return (new_list_buttons());
    if (li->begin == li->end) {
        free (li->begin);
        free (li);
        return (new_list_buttons());
    }
    node_buttons_t *tmp = li->begin;
    li->begin = li->begin->next;
    tmp->next = NULL;
    free (tmp);
    li->length--;
    return (li);
}