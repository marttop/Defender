/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** round_mob
*/

#include "defender.h"

balls_t *fill_balls(balls_t *s_balls, sfVector2f pos, int map_pos)
{
    balls_t *new = malloc(sizeof(balls_t));
    new->sprite = sfSprite_create();
    new->clock = sfClock_create();
    new->map_pos = map_pos, new->increment = 120;
    new->previous = '@';
    new->texture =
    sfTexture_createFromFile("sprites/mob_balls.png", NULL);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    new->pos.x = pos.x, new->pos.y = pos.y;
    new->state = 0, new->speed = 2;
    sfSprite_setPosition(new->sprite, pos);
    new->next = s_balls;
    return (new);
}

void generate_round_mobs(all_t *s_all)
{
    balls_t *s_balls = NULL;
    sfVector2f pos = get_spawner_position(s_all);
    for (int i = 0; i != 1; i++) {
        s_balls = fill_balls(s_balls, pos, s_all->s_map.spawner);
    }
    s_all->s_balls = s_balls;
}

void display_round_mobs(all_t *s_all)
{
    balls_t *temp = s_all->s_balls;
    while (temp != NULL) {
        check_path(s_all, temp);
        sfSprite_setPosition(temp->sprite, temp->pos);
        sfRenderWindow_drawSprite(s_all->s_game.window,
        temp->sprite, NULL);
        temp = temp->next;
    }
}