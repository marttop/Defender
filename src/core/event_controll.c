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
            click_sell_button(s_all);
            hitbox_pause_button(s_all), hitbox_wave_button(s_all);
            place_turret(s_all), click_selected_turret(s_all);
            hitbox_slider_arrow(s_all), hitbox_change_targetting_next(s_all);
            hitbox_change_targetting_back(s_all), hitbox_upgrade_button(s_all);
            if (s_all->s_selected.tur != NULL) {
                hitbox_change_targetting_next_turret(s_all,
                    s_all->s_selected.tur->target);
                hitbox_change_targetting_back_turret(s_all,
                    s_all->s_selected.tur->target);
            } click_support(s_all);
        } map_editor_click(s_all);
    } else if (s_all->s_game.event.type == sfEvtMouseButtonReleased) {
        menu_release_buttons(s_all), release_slider_arrow(s_all);
        release_pause_button(s_all), release_wave_button(s_all);
        release_sell_button(s_all), release_upgrade_button(s_all);
        map_editor_release(s_all), map_selector_release(s_all);
    }
}

void event_controll(all_t *s_all)
{
    if (s_all->s_game.event.type == sfEvtClosed)
        sfRenderWindow_close(s_all->s_game.window);
    if (sfKeyboard_isKeyPressed(sfKeySpace) == 1) {
        sfClock_restart(s_all->s_game.clock);
        sfClock_restart(s_all->s_wave_c.clock);
        restart_tuto_clocks(s_all);
        sfClock_restart(s_all->s_spawning.clock2);
        s_all->s_game.scene = 1, sfClock_restart(s_all->s_spawning.clock);
    } event_controll_buttons(s_all);
}