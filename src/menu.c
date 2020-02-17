/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** menu
*/

#include "defender.h"

void init_menu(all_t *s_all)
{
    s_all->s_menu.sp_background = sfSprite_create();
    s_all->s_menu.tx_background =
        sfTexture_createFromFile("sprites/background.png", NULL);
    sfSprite_setTexture(s_all->s_menu.sp_background,
        s_all->s_menu.tx_background, sfTrue);
    s_all->s_menu.main_theme = sfMusic_createFromFile("sounds/main_theme.ogg");
    sfMusic_play(s_all->s_menu.main_theme);
    sfMusic_setLoop(s_all->s_menu.main_theme, sfTrue);
    sfMusic_setVolume(s_all->s_menu.main_theme, 70);
    s_all->s_menu.display = 0;
    sfSprite_setPosition(s_all->s_menu.sp_background, (sfVector2f){0, -50});
}

void button_tab_init(char **tab, char **tab2)
{
    tab[0] = "sprites/buttons/continue.png";
    tab[1] = "sprites/buttons/new_game.png";
    tab[2] = "sprites/buttons/custom_maps.png";
    tab[3] = "sprites/buttons/research.png";
    tab[4] = "sprites/buttons/statistics.png";
    tab[5] = "sprites/buttons/settings.png";
    tab[6] = "sprites/buttons/handbook.png";
    tab[7] = "sprites/buttons/about.png";
    tab2[0] = "sprites/buttons/continue2.png";
    tab2[1] = "sprites/buttons/new_game2.png";
    tab2[2] = "sprites/buttons/custom_maps2.png";
    tab2[3] = "sprites/buttons/research2.png";
    tab2[4] = "sprites/buttons/statistics2.png";
    tab2[5] = "sprites/buttons/settings2.png";
    tab2[6] = "sprites/buttons/handbook2.png";
    tab2[7] = "sprites/buttons/about2.png";
}

void list_menu_buttons(all_t *s_all)
{
    char *tab[8], *tab2[8];
    button_tab_init(tab, tab2);
    s_all->s_buttons = NULL;
    for (int i = 0, y = 120; i != 8; i++, y += 100)
        s_all->s_buttons = 
            push_back_buttons(s_all->s_buttons, tab[i], tab2[i], y);
}

void display_menu_buttons(all_t *s_all)
{
    node_buttons_t *tmp = s_all->s_buttons->begin;
    while (tmp != NULL) {
        menu_buttons_hitbox(tmp, s_all);
        sfRenderWindow_drawSprite(s_all->s_game.window, tmp->sprite, NULL);
        tmp = tmp->next;
    }
}

void display_menu(all_t *s_all)
{
    if (s_all->s_menu.display == 0) {
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_menu.sp_background, NULL);
        display_menu_buttons(s_all);
    }
}