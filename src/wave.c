/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** wave
*/

#include "defender.h"

void get_random_position(tuto_t *new)
{
    int x = rand() % 42;
    int y = rand() % 42;
    int x_neg = (rand() % 2);
    int y_neg = (rand() % 2);
    if (x_neg == 0 && y_neg == 0) {
        new->pos.x = x, new->pos.y = y;
    } if (x_neg == 1 && y_neg == 1) {
        new->pos.x = (x * -1), new->pos.y = (y * -1);
    } if (x_neg == 1 && y_neg == 0) {
        new->pos.x = (x * -1), new->pos.y = y;
    } if (x_neg == 0 && y_neg == 1) {
        new->pos.x = x, new->pos.y = (y * -1);
    }
}

tuto_t *fill_mobs(tuto_t *s_tuto, all_t *s_all, char *filepath, int id)
{
    tuto_t *new = malloc(sizeof(tuto_t));
    sfVector2f pos = s_all->s_map.spawner_pos;
    new->id = id, get_random_position(new);
    new->sprite = sfSprite_create(), new->clock = sfClock_create();
    new->map_pos = s_all->s_map.spawner, new->increment = 120;
    new->previous = '@', new->state = 0, new->speed = 2, new->seconds = 0;
    new->texture =
    sfTexture_createFromFile(filepath, NULL);
    new->scale = (sfVector2f){0.1, 0.1};
    new->direction = (rand() % 2) == 1 ? 1 : 0;
    sfSprite_setScale(new->sprite, new->scale);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    new->pos.x += (60 + pos.x), new->pos.y += (75 + pos.y), new->move = 20;
    sfSprite_setOrigin(new->sprite, (sfVector2f){27, 27});
    sfSprite_setPosition(new->sprite, new->pos), new->next = s_tuto;
    return (new);
}

void push_rand_rounds(all_t *s_all)
{
    int i = 0;
    if (s_all->s_wave_c.seconds > 0.50) {
        if (s_all->s_wave_c.head->round > 2)
            i = (rand() % 2) + 1;
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
    if (s_all->s_wave_c.go == 1) {
        if (s_all->s_wave_c.head->round != 0) push_rand_rounds(s_all);
        if (s_all->s_wave_c.head->square != 0) push_rand_square(s_all);
        if (s_all->s_wave_c.head->triangle != 0) push_rand_triangle(s_all);
    }
}

void display_mobs(all_t *s_all)
{
    if (s_all->s_wave_c.go == 1 && (s_all->s_wave_c.round != NULL ||
    s_all->s_wave_c.square != NULL || s_all->s_wave_c.triangle != NULL)) {
        display_round(s_all);
        display_square(s_all);
        display_triangle(s_all);
    }
    else if ((s_all->s_wave_c.round == NULL && s_all->s_wave_c.square == NULL &&
    s_all->s_wave_c.triangle == NULL) && s_all->s_wave_c.go == 1)
        s_all->s_wave_c.go = 0;
}