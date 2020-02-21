/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** round_mob
*/

#include "defender.h"

tuto_t *fill_balls(tuto_t *s_tuto, sfVector2f pos, int map_pos)
{
    tuto_t *new = malloc(sizeof(tuto_t));
    new->sprite = sfSprite_create(), new->clock = sfClock_create();
    new->map_pos = map_pos, new->increment = 120;
    new->previous = '@', new->state = 0, new->speed = 2, new->seconds = 0;
    new->texture =
    sfTexture_createFromFile("sprites/path.png", NULL);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    new->pos.x = pos.x + 60, new->pos.y = pos.y + 60;
    sfSprite_setOrigin(new->sprite, (sfVector2f){15, 15});
    sfSprite_setPosition(new->sprite, pos);
    new->next = s_tuto;
    return (new);
}

void generate_round_mobs(all_t *s_all)
{
    tuto_t *s_tuto = NULL;
    sfVector2f pos = s_all->s_map.spawner_pos;
    for (int i = 0; i != 1; i++) {
        s_tuto = fill_balls(s_tuto, pos, s_all->s_map.spawner);
    }
    s_all->s_tuto = s_tuto;
}

void display_round_mobs(all_t *s_all)
{
    tuto_t *temp = s_all->s_tuto;
    rotate_turret_maths(s_all);
    while (temp != NULL) {
        check_path(s_all, temp), sfSprite_setPosition(temp->sprite, temp->pos);
        sfRenderWindow_drawSprite(s_all->s_game.window,
        temp->sprite, NULL), temp = temp->next;
    }
    if (s_all->s_spawning.seconds2 > 0.4) {
        s_all->s_tuto = fill_balls(s_all->s_tuto, s_all->s_map.spawner_pos,
        s_all->s_map.spawner);
        sfClock_restart(s_all->s_spawning.clock2);
    } check_destroy_ball(s_all);
}