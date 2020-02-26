/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** wave
*/

#include "defender.h"

void fill_mobs2(tuto_t *new)
{
    new->life_bar = sfRectangleShape_create();
    new->black = sfRectangleShape_create();
    sfRectangleShape_setFillColor(new->life_bar,
        (sfColor){100, 255, 100, 200});
    sfRectangleShape_setFillColor(new->black,
        (sfColor){0, 0, 0, 200});
    sfRectangleShape_setPosition(new->life_bar,
        (sfVector2f){-200, -200});
    sfRectangleShape_setPosition(new->black,
        (sfVector2f){-200, -200});
    sfRectangleShape_setSize(new->life_bar, (sfVector2f){60, 5});
    sfRectangleShape_setSize(new->black, (sfVector2f){62, 7});
    new->snow = sfSprite_create();
    new->snow_text = sfTexture_createFromFile("sprites/snow.png", NULL);
    sfSprite_setTexture(new->snow, new->snow_text, sfTrue);
    sfSprite_setPosition(new->snow, (sfVector2f){new->pos.x - 17,
        new->pos.y - 50}), new->slow = 0;
}

tuto_t *fill_mobs(tuto_t *s_tuto, all_t *s_all, char *filepath, int id)
{
    tuto_t *new = malloc(sizeof(tuto_t));
    sfVector2f pos = s_all->s_map.spawner_pos;
    new->id = id, get_random_position(new);
    new->sprite = sfSprite_create(), new->clock = sfClock_create();
    new->map_pos = s_all->s_map.spawner, new->increment = 120;
    new->previous = '@', new->state = 0, new->seconds = 0;
    new->texture = sfTexture_createFromFile(filepath, NULL);
    new->scale = (sfVector2f){0.1, 0.1};
    new->direction = (rand() % 2) == 1 ? 1 : 0;
    sfSprite_setScale(new->sprite, new->scale);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    new->pos.x += (60 + pos.x), new->pos.y += (75 + pos.y), new->move = 20;
    sfSprite_setOrigin(new->sprite, (sfVector2f){27, 27});
    sfSprite_setPosition(new->sprite, new->pos), new->next = s_tuto;
    fill_mobs2(new), new->castle = 0, new->nb = s_all->s_game.mob_nb;
    if (id == 1) new->life = 100, new->speed = 2, s_all->s_game.mob_nb++;
    if (id == 2) new->life = 200, new->speed = 1.5, s_all->s_game.mob_nb++;
    if (id == 3) new->life = 65, new->speed = 3.5, s_all->s_game.mob_nb++;
    new->save_speed = new->speed;
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
    else if ((s_all->s_wave_c.round == NULL && s_all->s_wave_c.square == NULL
    && s_all->s_wave_c.triangle == NULL) && s_all->s_wave_c.go == 1 &&
    s_all->s_wave_c.seconds > 2.5)
        s_all->s_wave_c.go = 0, update_wave_button(s_all);
}