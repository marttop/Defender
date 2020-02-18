/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** round_mob
*/

#include "defender.h"

tuto_t *fill_balls(tuto_t *s_tuto, sfVector2f pos, int map_pos,
                    sfVector2f scale)
{
    tuto_t *new = malloc(sizeof(tuto_t));
    new->sprite = sfSprite_create(), new->clock = sfClock_create();
    new->map_pos = map_pos, new->increment = 120;
    new->previous = '@', new->state = 0, new->speed = 2, new->seconds = 0;
    sfSprite_setScale(new->sprite, scale);
    new->texture =
    sfTexture_createFromFile("sprites/mob_balls.png", NULL);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    new->pos.x = pos.x + 60, new->pos.y = pos.y + 60;
    sfSprite_setOrigin(new->sprite, (sfVector2f){27, 27});
    sfSprite_setPosition(new->sprite, pos);
    new->next = s_tuto;
    return (new);
}

void generate_round_mobs(all_t *s_all)
{
    tuto_t *s_tuto = NULL;
    sfVector2f pos = get_spawner_position(s_all);
    s_all->s_map.spawner_pos = pos;
    s_all->s_map.castle_pos = get_castle_position(s_all);
    for (int i = 0; i != 1; i++) {
        s_tuto = fill_balls(s_tuto, pos, s_all->s_map.spawner,
        (sfVector2f){0.25, 0.25});
    }
    s_all->s_tuto = s_tuto;
}

void display_round_mobs(all_t *s_all)
{
    tuto_t *temp = s_all->s_tuto;
    while (temp != NULL) {
        check_path(s_all, temp), sfSprite_setPosition(temp->sprite, temp->pos);
        sfRenderWindow_drawSprite(s_all->s_game.window,
        temp->sprite, NULL), temp = temp->next;
    }
    if (s_all->s_spawning.seconds2 > 0.40) {
        s_all->s_tuto = fill_balls(s_all->s_tuto, s_all->s_map.spawner_pos,
        s_all->s_map.spawner, (sfVector2f){0.25, 0.25});
        sfClock_restart(s_all->s_spawning.clock2);
    } check_destroy_ball(s_all);
}