/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** wave
*/

#include "defender.h"

tuto_t *fill_mobs(tuto_t *s_tuto, all_t *s_all, char *filepath, int id)
{
    tuto_t *new = malloc(sizeof(tuto_t));
    sfVector2f pos = s_all->s_map.spawner_pos;
    int x = rand() % 45, y = rand() % 45, i = rand() % 2;
    if (i == 1) {
        pos.x += x, pos.y += y;
    } else {
        pos.x -= x, pos.y -= y;
    } new->id = id;
    new->sprite = sfSprite_create(), new->clock = sfClock_create();
    new->map_pos = s_all->s_map.spawner, new->increment = 120;
    new->previous = '@', new->state = 0, new->speed = 2, new->seconds = 0;
    new->texture =
    sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    new->pos.x = pos.x + 60, new->pos.y = pos.y + 60;
    sfSprite_setOrigin(new->sprite, (sfVector2f){27, 27});
    sfSprite_setPosition(new->sprite, pos);
    new->next = s_tuto;
    return (new);
}

void push_rand_rounds(all_t *s_all)
{
    int i = 0;
    if (s_all->s_wave_c.seconds > 1.25) {
        if (s_all->s_wave_c.head->round > 6)
            i = (rand() % 4) + 1;
        else i = rand() % s_all->s_wave_c.head->round + 1;
        if (s_all->s_wave_c.head->round < i) i -= 1;
        s_all->s_wave_c.head->round -= i;
        for (; i != 0; i--)
            s_all->s_wave_c.round = fill_mobs(s_all->s_wave_c.round,
            s_all, "sprites/round.png", 1);
        sfClock_restart(s_all->s_wave_c.clock);
    }
}

void generate_waves(all_t *s_all)
{
    s_all->s_wave_c.time = sfClock_getElapsedTime(s_all->s_wave_c.clock);
    s_all->s_wave_c.seconds =
    s_all->s_wave_c.time.microseconds / 1000000.0;
    if (s_all->s_wave_c.head->round != 0) push_rand_rounds(s_all);
    if (s_all->s_wave_c.head->square != 0) push_rand_square(s_all);
    if (s_all->s_wave_c.head->triangle != 0) push_rand_triangle(s_all);
}

void display_mobs(all_t *s_all)
{
    display_round(s_all);
    display_square(s_all);
    display_triangle(s_all);
}