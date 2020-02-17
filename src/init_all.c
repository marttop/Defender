/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** render
*/

#include "defender.h"
#include "utils.h"

void setup(all_t *s_all)
{
    sfVideoMode mode = {1920, 1080, 32};
    s_all->s_game.clock = sfClock_create();
    s_all->s_game.clear_color = sfColor_fromRGB(22, 24, 23);
    s_all->s_game.window = sfRenderWindow_create(mode, "my_defender",
        sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(s_all->s_game.window, 60);
    sfRenderWindow_setPosition(s_all->s_game.window, (sfVector2i){0, 0});
    s_all->s_game.scene = 0;
}

void init_all(all_t *s_all)
{
    setup(s_all), parse_map(s_all), init_menu(s_all), list_menu_buttons(s_all);
    init_selected(s_all), init_pause_button(s_all), init_side_menu(s_all);
}