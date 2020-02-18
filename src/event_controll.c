/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** event_controll
*/

#include "defender.h"

void event_controll_buttons(all_t *s_all)
{
    if (s_all->s_game.event.type == sfEvtMouseButtonPressed) {
        if (s_all->s_game.scene == 0 || s_all->s_game.pause == 1)
            menu_press_buttons(s_all);
        else if (s_all->s_game.scene == 1) {
            hitbox_pause_button(s_all);
            click_support(s_all);
        }
    } else if (s_all->s_game.event.type == sfEvtMouseButtonReleased) {
        menu_release_buttons(s_all);
        release_pause_button(s_all);
    }
}

void event_controll(all_t *s_all)
{
    if (s_all->s_game.event.type == sfEvtClosed)
        sfRenderWindow_close(s_all->s_game.window);
    if (sfKeyboard_isKeyPressed(sfKeySpace) == 1) {
        sfClock_restart(s_all->s_game.clock), sfClock_restart(s_all->s_spawning.clock2);
        s_all->s_game.scene = 1, sfClock_restart(s_all->s_spawning.clock);
    } event_controll_buttons(s_all);
}