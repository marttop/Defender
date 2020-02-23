/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** player
*/

#include "defender.h"

void init_play_texts(all_t *s_all)
{
    s_all->s_player.txt_life = sfText_create();
    s_all->s_player.txt_money = sfText_create();
    sfText_setFont(s_all->s_player.txt_life, s_all->s_game.font);
    sfText_setFont(s_all->s_player.txt_money, s_all->s_game.font);
    sfText_setString(s_all->s_player.txt_life, "100");
    sfText_setString(s_all->s_player.txt_money, "100");
    sfText_setPosition(s_all->s_player.txt_life, (sfVector2f){265, 20});
    sfText_setPosition(s_all->s_player.txt_money, (sfVector2f){405, 20});
}

void init_player_infos(all_t *s_all)
{
    s_all->s_player.sprite_h = sfSprite_create();
    s_all->s_player.sprite_m = sfSprite_create();
    s_all->s_player.texture_h =
    sfTexture_createFromFile("sprites/life.png", NULL);
    s_all->s_player.texture_m =
    sfTexture_createFromFile("sprites/money.png", NULL);
    sfSprite_setTexture(s_all->s_player.sprite_h,
    s_all->s_player.texture_h, sfTrue);
    sfSprite_setTexture(s_all->s_player.sprite_m,
    s_all->s_player.texture_m, sfTrue);
    s_all->s_player.life = 100, s_all->s_player.money = 100;
    sfSprite_setPosition(s_all->s_player.sprite_h, (sfVector2f){360, 20});
    sfSprite_setPosition(s_all->s_player.sprite_m, (sfVector2f){470, 20});
    init_play_texts(s_all);
}

void display_player_info(all_t *s_all)
{
    sfRenderWindow_drawSprite(s_all->s_game.window,
    s_all->s_player.sprite_h, NULL);
    sfRenderWindow_drawSprite(s_all->s_game.window,
    s_all->s_player.sprite_m, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
    s_all->s_player.txt_life, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
    s_all->s_player.txt_money, NULL);
}