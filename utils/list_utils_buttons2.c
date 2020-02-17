/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** list_utils_buttons2
*/

#include "defender.h"

list_buttons_t *clear_list(list_buttons_t *li)
{
    while (!is_empty_list_buttons(li))
        li = pop_front_buttons(li);
    return (new_list_buttons());
}