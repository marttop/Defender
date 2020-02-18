/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** turret_select
*/

#include "defender.h"
#include "utils.h"

t_select_t *fill_select(t_select_t *old, sfVector2f pos, int id)
{
    t_select_t *new = malloc(sizeof(t_select_t));
    new->sprite = sfSprite_create();
    new->texture =
    sfTexture_createFromFile("sprites/turret1_select.png", NULL);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setPosition(new->sprite, pos);
    new->type = id;
    new->next = old;
    return (new);
}

void generate_selected_turret(all_t *s_all)
{
    sfVector2f pos = s_all->s_side_menu.pos;
    pos.x += 138, pos.y = 700;
    t_select_t *select = NULL;
    for (int i = 0; i != 4; i++) {
        select = fill_select(select, pos, i + 1);
        pos.x += 122;
    }
    s_all->s_t_select = select;
}

void display_selected_turret(all_t *s_all)
{
    t_select_t *temp = s_all->s_t_select;
    if (s_all->s_selected.type == 'O')
        while (temp != NULL) {
            display_targetting_buttons(s_all);
            sfRenderWindow_drawSprite(s_all->s_game.window, temp->sprite, NULL);
            temp = temp->next;
        }
}