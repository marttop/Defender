/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** turret_support
*/

#include "defender.h"

support_t *fill_support(support_t *s_support, sfVector2f pos,
                        char *filepath, char type)
{
    support_t *new = malloc(sizeof(support_t));
    new->sprite = sfSprite_create(), new->sprite_base = sfSprite_create();
    new->texture =
    sfTexture_createFromFile(filepath, NULL);
    new->texture_base =
    sfTexture_createFromFile("sprites/spawner_base.png", NULL);
    sfSprite_setTexture(new->sprite_base, new->texture_base, sfTrue);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    new->pos = pos, new->base_pos = pos, new->type = type;
    if (type == 'S') {
        sfSprite_setOrigin(new->sprite, (sfVector2f){60, 60});
        sfSprite_setPosition(new->sprite,
        (sfVector2f){pos.x + 60, pos.y + 60});
    }
    else sfSprite_setPosition(new->sprite, pos);
    sfSprite_setPosition(new->sprite_base, pos);
    new->next = s_support;
    return (new);
}

void rotate_spawner(support_t *s_support, all_t *s_all)
{
    float rotate = s_all->s_game.seconds;
    if (s_all->s_game.pause == 0)
        sfSprite_rotate(s_support->sprite, 100 * rotate);
    sfClock_restart(s_all->s_game.clock);
}

void display_support(all_t *s_all)
{
    support_t *temp = s_all->s_map.s_support;
    while (temp != NULL) {
        if (temp->type == 'S') {
            rotate_spawner(temp, s_all);
            sfRenderWindow_drawSprite(s_all->s_game.window,
            temp->sprite_base, NULL);
        }
        sfRenderWindow_drawSprite(s_all->s_game.window, temp->sprite, NULL);
        temp = temp->next;
    }
    display_pause_button(s_all);
}