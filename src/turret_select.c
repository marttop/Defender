/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** turret_select
*/

#include "defender.h"
#include "utils.h"

t_select_t *fill_select(t_select_t *old, sfVector2f pos, int id, char *file)
{
    t_select_t *new = malloc(sizeof(t_select_t));
    new->sprite = sfSprite_create();
    new->texture =
    sfTexture_createFromFile(file , NULL);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setPosition(new->sprite, pos);
    new->pos = pos, new->type = id;
    new->next = old;
    return (new);
}

void generate_selected_turret(all_t *s_all)
{
    sfVector2f pos = s_all->s_side_menu.pos;
    pos.x += 138, pos.y = 700;
    t_select_t *select = NULL;
    char *tab[4] = {"sprites/turret4_select.png", "sprites/turret3_select.png",
    "sprites/turret2_select.png", "sprites/turret1_select.png"};
    for (int i = 0; i != 4; i++) {
        select = fill_select(select, pos, i + 1, tab[i]);
        pos.x += 122;
    }
    s_all->s_t_select = select;
}

void check_selected_turret_hitbox(all_t *s_all)
{
    t_select_t *temp = s_all->s_t_select;
    while (temp != NULL) {
        if (check_selected_turret(s_all, temp)) {
            sfSprite_setPosition(s_all->s_selected2.sprite, temp->pos);
            sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_selected2.sprite, NULL);
        }
        temp = temp->next;
    }
}

void display_selected_turret(all_t *s_all)
{
    t_select_t *temp = s_all->s_t_select;
    if (s_all->s_selected.type == 'O') {
        while (temp != NULL) {
            display_targetting_buttons(s_all);
            sfRenderWindow_drawSprite(s_all->s_game.window, temp->sprite, NULL);
            temp = temp->next;
        }
        if (s_all->s_game.pause == 0)
            check_selected_turret_hitbox(s_all);
        display_clicked_turret(s_all);
    }
}