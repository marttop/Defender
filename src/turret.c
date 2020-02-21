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
    new->sprite = sfSprite_create(), new->sprite_c = sfSprite_create();
    new->bullet = sfSprite_create(), new->type = id, new->pos = pos;
    get_turret_textures(id, new), get_canon_textures(id, new);
    new->text_bullet = sfTexture_createFromFile("sprites/bullet1.png", NULL);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setTexture(new->sprite_c, new->texture_c, sfTrue);
    sfSprite_setTexture(new->bullet, new->text_bullet, sfTrue);
    new->pos_c = (sfVector2f){pos.x + 60, pos.y + 60};
    sfSprite_setPosition(new->sprite, pos), new->shoot = 0, new->hit = 0;
    sfSprite_setOrigin(new->sprite_c, (sfVector2f){60, 60});
    new->pos_c2 = (sfVector2f){pos.x + 120, pos.y + 60};
    sfSprite_setPosition(new->sprite_c, (sfVector2f){pos.x + 60, pos.y + 60});
    sfSprite_setOrigin(new->bullet, (sfVector2f){17, 17});
    sfSprite_setScale(new->bullet, (sfVector2f){0.3, 0.3});
    sfSprite_setPosition(new->bullet, new->pos_c);
    new->clock = sfClock_create(), new->next = old, new->rotate = 0;
    if (new->type == 1) new->r_speed = 2.5, new->rate_fire = 0.5, new->bullet_speed = 8.0;
    else if (new->type == 2) new->r_speed = 1.8, new->rate_fire = 3.0, new->bullet_speed = 25.0;
    else new->r_speed = 1.3, new->rate_fire = 2.0, new->bullet_speed = 8.0;
    sfSprite_setRotation(new->sprite_c, new->rotate);
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
        sfRenderWindow_drawSprite(s_all->s_game.window, temp->bullet, NULL);
        sfRenderWindow_drawSprite(s_all->s_game.window, temp->sprite_c, NULL);
        temp = temp->next;
    }
}