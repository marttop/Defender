/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** turret
*/

#include "defender.h"
#include "utils.h"

void get_turret_textures(int id, turret_t *new)
{
    switch (id) {
    case 1 :
        new->texture =
        sfTexture_createFromFile("sprites/turret1_base.png", NULL);
        break;
    case 2 :
        new->texture =
        sfTexture_createFromFile("sprites/turret2_base.png", NULL);
        break;
    case 3 :
        new->texture =
        sfTexture_createFromFile("sprites/turret3_base.png", NULL);
        break;
    case 4 :
        new->texture =
        sfTexture_createFromFile("sprites/turret4_base.png", NULL);
        break;
    }
}

void get_canon_textures(int id, turret_t *new)
{
    switch (id) {
    case 1 :
        new->texture_c =
        sfTexture_createFromFile("sprites/turret1_canon.png", NULL);
        break;
    case 2 :
        new->texture_c =
        sfTexture_createFromFile("sprites/turret2_canon.png", NULL);
        break;
    case 3 :
        new->texture_c =
        sfTexture_createFromFile("sprites/turret3_canon.png", NULL);
        break;
    case 4 :
        new->texture_c =
        sfTexture_createFromFile("sprites/turret4_canon.png", NULL);
        break;
    }
}

turret_t *fill_turret(turret_t *old, sfVector2f pos, int id)
{
    turret_t *new = malloc(sizeof(turret_t));
    new->sprite = sfSprite_create();
    new->sprite_c = sfSprite_create();
    get_turret_textures(id, new), get_canon_textures(id, new);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setTexture(new->sprite_c, new->texture_c, sfTrue);
    new->type = id, new->pos = pos;
    sfSprite_setPosition(new->sprite, pos);
    sfSprite_setPosition(new->sprite_c, (sfVector2f){pos.x + 60, pos.y + 60});
    new->next = old;
    new->rotate = 0;
    sfSprite_setRotation(new->sprite_c, new->rotate);
    sfSprite_setOrigin(new->sprite_c, (sfVector2f){60, 60});
    return (new);
}

void place_turret(all_t *s_all)
{
    t_select_t *temp = s_all->s_t_select;
    while (temp != NULL) {
        if (check_selected_turret(s_all, temp) &&
        s_all->s_selected2.click == 1 && temp->clicked == 1 &&
        s_all->s_selected.sel->on != 1 && s_all->s_selected.sel->type == 'O') {
            s_all->s_turret = fill_turret(s_all->s_turret,
            s_all->s_selected.pos2, temp->type);
            s_all->s_selected.sel->on = 1;
        }
        temp = temp->next;
    }
}

void display_turret(all_t *s_all)
{
    turret_t *temp = s_all->s_turret;
    while (temp != NULL) {
        sfRenderWindow_drawSprite(s_all->s_game.window, temp->sprite, NULL);
        sfRenderWindow_drawSprite(s_all->s_game.window, temp->sprite_c, NULL);
        temp = temp->next;
    }
}