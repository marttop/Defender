/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** wave_parsor
*/

#include "utils.h"
#include "defender.h"

waves_t *fill_waves(waves_t *temp)
{
    waves_t *new = malloc(sizeof(waves_t));
}

void parse_wave(all_t *s_all)
{
    int i = 0, j = 0;
    char *waves = get_file("maps/waves_map1");
    for (; waves[i] != '#'; i++) {
        if (waves[i] == "%") {
            
        }
    }
}