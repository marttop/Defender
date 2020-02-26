/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** display
*/

#include "defender.h"

void display_snow(all_t *s_all)
{
    tuto_t *tmp = s_all->s_wave_c.round;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->slow == 1)
            sfRenderWindow_drawSprite(s_all->s_game.window, tmp->snow, NULL);
    } tmp = s_all->s_wave_c.square;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->slow == 1)
            sfRenderWindow_drawSprite(s_all->s_game.window, tmp->snow, NULL);
    } tmp = s_all->s_wave_c.triangle;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->slow == 1)
            sfRenderWindow_drawSprite(s_all->s_game.window, tmp->snow, NULL);
    }
}

void display(all_t *s_all)
{
    sfRenderWindow_clear(s_all->s_game.window, s_all->s_game.clear_color);
    if (s_all->s_game.scene != 0) {
        display_support(s_all), display_round_mobs(s_all);
        generate_waves(s_all), display_mobs(s_all);
        check_support_hitbox(s_all), display_clicked(s_all);
        display_turret(s_all), display_count_wave_button(s_all);
        display_snow(s_all);
        if (s_all->s_selected.tur == NULL) {
            display_side_menu(s_all, s_all->s_targetting);
        } else display_side_menu(s_all, s_all->s_selected.tur->target);
        display_sell_button(s_all);
        display_selected_turret(s_all), display_player_info(s_all);
        display_pause_button(s_all), display_wave_button(s_all);
        display_slider_arrow(s_all), display_turret_stats(s_all);
        display_turret_target(s_all);
        display_info_texts(s_all);
    } display_menu(s_all);
    sfRenderWindow_display(s_all->s_game.window);
}

void display_clicked(all_t *s_all)
{
    if (s_all->s_selected.on == 1 && s_all->s_selected.pos2.x != 0)
        sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_selected.clicked_s, NULL);
}
