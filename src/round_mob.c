/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** round_mob
*/

#include "defender.h"

balls_t *fill_balls(balls_t *s_balls, sfVector2f pos)
{
    balls_t *new = malloc(sizeof(balls_t));
    new->sprite = sfSprite_create();
    new->clock = sfClock_create();
    new->texture =
    sfTexture_createFromFile("sprites/mob_balls.png", NULL);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    new->pos.x = pos.x, new->pos.y = pos.y;
    new->state = 0, new->speed = 120;
    sfSprite_setPosition(new->sprite, pos);
    sfSprite_setScale(new->sprite, (sfVector2f){0.40, 0.40});
    new->next = s_balls;
    return (new);
}

void generate_round_mobs(all_t *s_all)
{
    balls_t *s_balls = NULL;
    int x = 985, y = 350;
    for (int i = 0; i != 0; i++) {
        s_balls = fill_balls(s_balls, (sfVector2f){x, y});
        x += 12;
    }
    s_all->s_balls = s_balls;
}

void move_ball2(balls_t *s_balls)
{
    if (s_balls->state == 4) {
        if (s_balls->pos.y > 530)
            s_balls->pos.y -= s_balls->speed * s_balls->seconds;
        else s_balls->state = 5;
    } if (s_balls->state == 5) {
        if (s_balls->pos.x > 800)
            s_balls->pos.x -= s_balls->speed * s_balls->seconds;
        else s_balls->state = 6;
    } if (s_balls->state == 6) {
        if (s_balls->pos.y > 180)
            s_balls->pos.y -= s_balls->speed * s_balls->seconds;
        else s_balls->state = -1;
    }
}

void move_ball(balls_t *s_balls, all_t *s_all)
{
    if (s_balls->state == 0) {
        if (s_balls->pos.y > 170)
            s_balls->pos.y -= s_balls->speed * s_balls->seconds;
        else {
            s_balls->state = 1;
            s_all->s_balls = fill_balls(s_balls, (sfVector2f){985, 350});
        }
    } if (s_balls->state == 1) {
        if (s_balls->pos.x < 1165)
            s_balls->pos.x += s_balls->speed * s_balls->seconds;
        else s_balls->state = 2;
    } if (s_balls->state == 2) {
        if (s_balls->pos.y < 720)
            s_balls->pos.y += s_balls->speed * s_balls->seconds;
        else s_balls->state = 3;
    } if (s_balls->state == 3) {
        if (s_balls->pos.x > 990)
            s_balls->pos.x -= s_balls->speed * s_balls->seconds;
        else s_balls->state = 4;
    } move_ball2(s_balls);
}

void display_round_mobs(all_t *s_all)
{
    balls_t *temp = s_all->s_balls;
    while (temp != NULL) {
        move_ball(temp, s_all);
        sfSprite_setPosition(temp->sprite, temp->pos);
        sfRenderWindow_drawSprite(s_all->s_game.window,
        temp->sprite, NULL);
        sfClock_restart(temp->clock);
        temp = temp->next;
    }
    check_destroy_ball(s_all);
}