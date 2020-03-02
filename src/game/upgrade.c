/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** upgrade
*/

#include "defender.h"
#include "utils.h"

void init_upgrade_turret(all_t *s_all, turret_t *new)
{
    new->upg_price_txt = sfText_create();
    new->lvl_txt = sfText_create();
    if (new->type == 1) new->upg_price = 24;
    if (new->type == 2) new->upg_price = 40;
    if (new->type == 3) new->upg_price = 30;
    if (new->type == 4) new->upg_price = 40;
    new->level = 1, new->strupg_price = strnbr(new->upg_price);
    sfText_setString(new->upg_price_txt, new->strupg_price);
    sfText_setFont(new->upg_price_txt, s_all->s_game.font);
    sfText_setPosition(new->upg_price_txt, (sfVector2f){1743, 845});
    sfText_setString(new->lvl_txt, "1");
    sfText_setFont(new->lvl_txt, s_all->s_game.font);
    sfText_setCharacterSize(new->lvl_txt, 25);
    sfText_setCharacterSize(new->upg_price_txt, 25);
    sfText_setPosition(new->lvl_txt, (sfVector2f){1895, 845});
}

void upgrade2(turret_t *tur)
{
    tur->sell += tur->upg_price / 7;
    free(tur->strsell);
    tur->strsell = strnbr(tur->sell);
    sfText_setString(tur->sell_txt, tur->strsell);
}

void max_upgrade(all_t *s_all, turret_t *tur)
{
    tur->max = 1;
    tur->counter++;
    free(tur->strupg_price);
    sfText_setString(tur->upg_price_txt, "Max");
    sfSprite_setTexture(s_all->s_upgrade.sprite,
    s_all->s_upgrade.texture, sfTrue);
    sfText_setCharacterSize(tur->upg_price_txt, 20);
    sfText_setPosition(tur->upg_price_txt, (sfVector2f){1740, 848});
}