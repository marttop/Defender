/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** menu2
*/

#include "defender.h"
#include "utils.h"

void menu_press_buttons(all_t *s_all)
{
    node_buttons_t *tmp = s_all->s_buttons->begin;
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    while (tmp != NULL) {
        if ((mouse_pos.x >= tmp->pos.x && mouse_pos.x <= tmp->pos.x + 500)
            && (mouse_pos.y >= tmp->pos.y && mouse_pos.y <= tmp->pos.y + 80))
            sfSprite_setTexture(tmp->sprite, tmp->texture2, sfTrue);
        tmp = tmp->next;
    }
}

void custom_maps(all_t *s_all)
{
    s_all->s_game.scene = 2;
    s_all->s_game.pause = 1;
}

void menu_release_selector(all_t *s_all, int i)
{
    if (s_all->s_game.pause == 1 && s_all->s_game.scene == 1) {
        if (i == 8)
            s_all->s_game.pause = 0;
        if (i == 11) {
            s_all->s_side_menu.draw = 0;
            s_all->s_hard_arrow.stat = 1;
            s_all->s_game.scene = 0;
            s_all->s_game.pause = 0;
            s_all->s_selected.on = 0;
        }
    }
    if (i == 2 && s_all->s_game.scene == 0)
        custom_maps(s_all);
    if (i == 1 && s_all->s_game.scene == 0)
        s_all->s_game.scene = -1;
}

void menu_release_buttons(all_t *s_all)
{
    node_buttons_t *tmp = s_all->s_buttons->begin;
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    int i = 0;
    while (tmp != NULL) {
        if ((mouse_pos.x >= tmp->pos.x && mouse_pos.x <= tmp->pos.x + 500)
            && (mouse_pos.y >= tmp->pos.y && mouse_pos.y <= tmp->pos.y + 80))
            menu_release_selector(s_all, i);
        sfSprite_setTexture(tmp->sprite, tmp->texture, sfTrue);
        tmp = tmp->next;
        i++;
    }
}

void menu_buttons_hitbox(node_buttons_t *tmp, all_t *s_all)
{
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if ((mouse_pos.x >= tmp->pos.x && mouse_pos.x <= tmp->pos.x + 500)
        && (mouse_pos.y >= tmp->pos.y && mouse_pos.y <= tmp->pos.y + 80)
        && s_all->s_buttons->seconds > 0.01) {
        sfClock_restart(s_all->s_buttons->clock);
        if (tmp->pos.x > 1550)
            tmp->pos.x -= 50;
        sfSprite_setPosition(tmp->sprite, tmp->pos);
    } else if (tmp->pos.x < 1820 && s_all->s_buttons->seconds > 0.01) {
        tmp->pos.x += 50;
        sfSprite_setPosition(tmp->sprite, tmp->pos);
        sfClock_restart(s_all->s_buttons->clock);
    }
}