/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** stats
*/

#include "defender.h"
#include "utils.h"

turret_t *get_turret(all_t *s_all)
{
    turret_t *temp = s_all->s_turret;
    while (temp != NULL) {
        if ((temp->pos.x == s_all->s_selected.pos2.x) &&
        temp->pos.y == s_all->s_selected.pos2.y)
            return (temp);
        temp = temp->next;
    }
    return (NULL);
}

void display_turret_stats(all_t *s_all)
{
    if (s_all->s_selected.type == 'O' && s_all->s_selected.tur != NULL &&
    s_all->s_selected.tur->draw_stat == 1) {
        sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_selected.tur->range_txt, NULL);
        sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_selected.tur->b_speed_txt, NULL);
        sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_selected.tur->r_speed_txt, NULL);
        sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_selected.tur->dmg_txt, NULL);
        sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_selected.tur->rof_txt, NULL);
        sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_selected.tur->zone, NULL);
        sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_selected.tur->sell_txt, NULL);
        sfRenderWindow_drawRectangleShape(s_all->s_game.window, s_all->
        s_selected.tur->under, NULL), sfRenderWindow_drawRectangleShape(s_all->
        s_game.window, s_all->s_selected.tur->xp_bar, NULL);
    }
}

void set_txt_sizes(turret_t *new)
{
    sfText_setCharacterSize(new->rof_txt, 20);
    sfText_setCharacterSize(new->dmg_txt, 20);
    sfText_setCharacterSize(new->range_txt, 20);
    sfText_setCharacterSize(new->b_speed_txt, 20);
    sfText_setCharacterSize(new->r_speed_txt, 20);
}