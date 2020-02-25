/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** turret_area
*/

#include "defender.h"
#include "utils.h"

void load_turret(turret_t *new, sfVector2f pos)
{
    new->text_bullet = sfTexture_createFromFile("sprites/bullet1.png", NULL);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setTexture(new->sprite_c, new->texture_c, sfTrue);
    sfSprite_setTexture(new->bullet, new->text_bullet, sfTrue);
    new->pos_c = (sfVector2f){pos.x + 60, pos.y + 60};
    new->pos_bullet = (sfVector2f){pos.x + 60, pos.y + 60};
    sfSprite_setPosition(new->sprite, pos), new->shoot = 0, new->hit = 0;
    sfSprite_setOrigin(new->sprite_c, (sfVector2f){60, 60});
    new->pos_c2 = (sfVector2f){pos.x + 120, pos.y + 60};
    sfSprite_setPosition(new->sprite_c, (sfVector2f){pos.x + 60, pos.y + 60});
    sfSprite_setOrigin(new->bullet, (sfVector2f){17, 17});
    sfSprite_setScale(new->bullet, (sfVector2f){0.3, 0.3});
    sfSprite_setPosition(new->bullet, new->pos_c);
}

void get_turret_texts(turret_t *new, all_t *s_all)
{
    new->r_speed_txt = sfText_create(), new->range_txt = sfText_create();
    new->rof_txt = sfText_create(), new->dmg_txt = sfText_create();
    new->b_speed_txt = sfText_create();
    sfText_setFont(new->r_speed_txt, s_all->s_game.font);
    sfText_setFont(new->range_txt, s_all->s_game.font);
    sfText_setFont(new->rof_txt, s_all->s_game.font);
    sfText_setFont(new->dmg_txt, s_all->s_game.font);
    sfText_setFont(new->b_speed_txt, s_all->s_game.font);
    new->r_speed_str = strnbr_float(new->r_speed);
    new->rof_str = strnbr_float(new->rate_fire);
    new->b_speed_str = strnbr_float(new->bullet_speed);
    new->range_str = strnbr(new->range);
    new->dmg_str = strnbr(new->dmg);
    sfText_setString(new->r_speed_txt, new->r_speed_str);
    sfText_setString(new->range_txt, new->range_str);
    sfText_setString(new->rof_txt, new->rof_str);
    sfText_setString(new->dmg_txt, new->dmg_str);
    sfText_setString(new->b_speed_txt, new->b_speed_str);
}

void get_turret_type(turret_t *new, all_t *s_all)
{
    if (new->type == 1) {
        new->r_speed = 2.5, new->rate_fire = 0.5, new->bullet_speed = 8.0;
        new->dmg = 34, new->range = 280;
    } else if (new->type == 2) {
        new->r_speed = 1.8, new->rate_fire = 3.0, new->bullet_speed = 25.0;
        new->dmg = 150, new->range = 560;
    } else {
        new->r_speed = 1.3, new->rate_fire = 2.0, new->bullet_speed = 8.0;
        new->dmg = 80, new->range = 200;
    }
    get_turret_texts(new, s_all);
    sfText_setPosition(new->b_speed_txt, (sfVector2f){1620, 405});
    sfText_setPosition(new->r_speed_txt, (sfVector2f){1620, 260});
    sfText_setPosition(new->rof_txt, (sfVector2f){1620, 329});
    sfText_setPosition(new->dmg_txt, (sfVector2f){1870, 260});
    sfText_setPosition(new->range_txt, (sfVector2f){1870, 340});
    set_txt_sizes(new);
}

void move_mob(tuto_t *mob, sfVector2f scl)
{
    if (mob->direction == 0 && (scl.x >= 1 && scl.y >= 1)) {
        mob->pos.x -= mob->seconds + 0.7;
        mob->move -= mob->seconds + 0.7;
        if (mob->move <= 0) mob->direction = 1;
    }
    if (mob->direction == 1 && (scl.x >= 1 && scl.y >= 1)) {
        mob->pos.x += mob->seconds + 0.7;
        mob->move += mob->seconds + 0.7;
        if (mob->move >= 20) mob->direction = 0;
    }
    sfClock_restart(mob->clock);
}