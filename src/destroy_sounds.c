/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** destroy_sounds
*/

#include "defender.h"

void destroy_music(all_t *s_all)
{
    sfMusic_destroy(s_all->s_menu.main_theme);
}