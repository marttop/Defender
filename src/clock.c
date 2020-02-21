/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** clock
*/

#include "defender.h"

void clock_round(all_t *s_all)
{
    if (s_all->s_game.scene == 1) {
        tuto_t *temp = s_all->s_tuto;
        while (temp != NULL) {
            temp->time = sfClock_getElapsedTime(temp->clock);
            temp->seconds = temp->time.microseconds / 1000000.0;
            temp = temp->next;
        }
    }
}

void clock_mobs(all_t *s_all)
{
    if (s_all->s_game.scene == 1) {
        tuto_t *temp = s_all->s_wave_c.round;
        while (temp != NULL) {
            temp->time = sfClock_getElapsedTime(temp->clock);
            temp->seconds = temp->time.microseconds / 1000000.0;
            temp = temp->next;
        } temp = s_all->s_wave_c.square;
        while (temp != NULL) {
            temp->time = sfClock_getElapsedTime(temp->clock);
            temp->seconds = temp->time.microseconds / 1000000.0;
            temp = temp->next;
        } temp = s_all->s_wave_c.triangle;
        while (temp != NULL) {
            temp->time = sfClock_getElapsedTime(temp->clock);
            temp->seconds = temp->time.microseconds / 1000000.0;
            temp = temp->next;
        }
    }
}

void general_game_clock(all_t *s_all)
{
    clock_round(s_all), clock_mobs(s_all);
    s_all->s_game.time = sfClock_getElapsedTime(s_all->s_game.clock);
    s_all->s_game.seconds = s_all->s_game.time.microseconds / 1000000.0;
    s_all->s_buttons->time = sfClock_getElapsedTime(s_all->s_buttons->clock);
    s_all->s_buttons->seconds =
    s_all->s_buttons->time.microseconds / 1000000.0;
    s_all->s_side_menu.time = sfClock_getElapsedTime(s_all->s_side_menu.clock);
    s_all->s_side_menu.seconds =
    s_all->s_side_menu.time.microseconds / 1000000.0;
    if (s_all->s_game.scene == 1) {
        s_all->s_spawning.time =
        sfClock_getElapsedTime(s_all->s_spawning.clock);
        s_all->s_spawning.seconds =
        s_all->s_spawning.time.microseconds / 1000000.0;
        s_all->s_spawning.time2 =
        sfClock_getElapsedTime(s_all->s_spawning.clock2);
        s_all->s_spawning.seconds2 =
        s_all->s_spawning.time2.microseconds / 1000000.0;
    }
}