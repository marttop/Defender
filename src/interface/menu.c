/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** menu+
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
}

void list_menu_buttons(all_t *s_all)
{
    button_tab_init(s_all->s_buttons_tab.tab);
    button_tab2_init(s_all->s_buttons_tab.tab2);
    s_all->s_buttons = NULL;
    for (int i = 0, y = 120; i != 12; i++, y += 100) {
        if (i == 8)
            y = 600;
        if (i < 8) s_all->s_buttons = push_back_buttons(s_all, y, 0, i);
        else if (i > 7) s_all->s_buttons = push_back_buttons(s_all, y, 1, i);
    }
}

void display_menu_buttons(all_t *s_all)
{
    node_buttons_t *tmp = s_all->s_buttons->begin;
    if (s_all->s_game.pause == 1 && s_all->s_game.scene != 2)
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_buttons->black, NULL);
    while (tmp != NULL) {
        menu_buttons_hitbox(tmp, s_all);
        if (tmp->who == 0 && s_all->s_game.scene == 0)
            sfRenderWindow_drawSprite(s_all->s_game.window, tmp->sprite, NULL);
        else if ((tmp->who == 1 && s_all->s_game.scene == 1 &&
        s_all->s_game.pause == 1))
            sfRenderWindow_drawSprite(s_all->s_game.window, tmp->sprite, NULL);
        tmp = tmp->next;
    }
}

void display_menu(all_t *s_all)
{
    if (s_all->s_game.scene == 0)
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_menu.sp_background, NULL);
    display_menu_buttons(s_all);
}