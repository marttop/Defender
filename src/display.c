/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** display
*/

#include "defender.h"

void display(all_t *s_all)
{
    sfRenderWindow_clear(s_all->s_game.window, s_all->s_game.clear_color);
    if (s_all->s_game.scene != 0) {
        display_support(s_all);
        display_round_mobs(s_all);
        check_support_hitbox(s_all);
        display_clicked(s_all);
        display_turret(s_all);
        display_side_menu(s_all);
        display_selected_turret(s_all);
        display_pause_button(s_all);
        display_slider_arrow(s_all);
    } display_menu(s_all);
    sfRenderWindow_display(s_all->s_game.window);
}

void display_clicked(all_t *s_all)
{
    if (s_all->s_selected.on == 1 && s_all->s_selected.pos2.x != 0)
        sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_selected.clicked_s, NULL);
}
