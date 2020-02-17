/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** menu2
*/

#include "defender.h"

void menu_press_buttons(all_t *s_all)
{
    node_buttons_t *tmp = s_all->s_buttons->begin;
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    while (tmp != NULL) {
        if ((mouse_pos.x >= tmp->pos.x && mouse_pos.x <= tmp->pos.x + 500)
            && (mouse_pos.y >= tmp->pos.y && mouse_pos.y <= tmp->pos.y + 80))
            sfSprite_setTexture(tmp->sprite, tmp->texture2, sfTrue);
        //if ((mouse_pos.x >= tmp->pos.x && mouse_pos.x <= tmp->pos.x + 500) 
        //    && (mouse_pos.y >= tmp->pos.y && mouse_pos.y <= tmp->pos.y + 80))
        //    s_all->
        tmp = tmp->next;
    }
}

void menu_release_buttons(all_t *s_all)
{
    node_buttons_t *tmp = s_all->s_buttons->begin;
    while (tmp != NULL) {
        sfSprite_setTexture(tmp->sprite, tmp->texture, sfTrue);
        tmp = tmp->next;
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