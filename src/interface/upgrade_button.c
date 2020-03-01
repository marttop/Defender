/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** upgrade_button
*/

#include "defender.h"
#include "utils.h"

void init_upgrade_button(all_t *s_all)
{
    s_all->s_upgrade.pos = (sfVector2f){1930, 830};
    s_all->s_upgrade.sprite = sfSprite_create();
    s_all->s_upgrade.gold = sfSprite_create();
    s_all->s_upgrade.texture =
        sfTexture_createFromFile("sprites/buttons/upgrade1.png", NULL);
    s_all->s_upgrade.texture2 =
        sfTexture_createFromFile("sprites/buttons/upgrade2.png", NULL);
    s_all->s_upgrade.texture3 =
        sfTexture_createFromFile("sprites/buttons/upgrade3.png", NULL);
    s_all->s_upgrade.gold_txt =
        sfTexture_createFromFile("sprites/money.png", NULL);
    sfSprite_setTexture(s_all->s_upgrade.sprite,
        s_all->s_upgrade.texture3, sfTrue);
    sfSprite_setTexture(s_all->s_upgrade.gold,
        s_all->s_upgrade.gold_txt, sfTrue);
    sfSprite_setPosition(s_all->s_upgrade.sprite,
        s_all->s_upgrade.pos);
    sfSprite_setPosition(s_all->s_upgrade.gold,
        (sfVector2f){s_all->s_upgrade.pos.x + 300, s_all->s_upgrade.pos.y});
}

void hitbox_upgrade_button(all_t *s_all)
{
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if ((mouse_pos.x >= s_all->s_upgrade.pos.x
        && mouse_pos.x <= s_all->s_upgrade.pos.x + 320)
        && (mouse_pos.y >= s_all->s_upgrade.pos.y
        && mouse_pos.y <= s_all->s_upgrade.pos.y + 63)) {
        if (s_all->s_player.money >= s_all->s_selected.tur->price
        && s_all->s_selected.tur != NULL)
            sfSprite_setTexture(s_all->s_upgrade.sprite,
                s_all->s_upgrade.texture2, sfTrue);
    }
}

void release_upgrade_button(all_t *s_all)
{
    if (s_all->s_selected.tur != NULL
    && s_all->s_player.money >=  s_all->s_selected.tur->price)
    sfSprite_setTexture(s_all->s_upgrade.sprite,
        s_all->s_upgrade.texture3, sfTrue);
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if ((mouse_pos.x >= s_all->s_upgrade.pos.x
    && mouse_pos.x <= s_all->s_upgrade.pos.x + 320)
    && (mouse_pos.y >= s_all->s_upgrade.pos.y
    && mouse_pos.y <= s_all->s_upgrade.pos.y + 63)
    && s_all->s_game.pause == 0 && s_all->s_game.scene == 1) {
    }
}

void display_upgrade_button(all_t *s_all)
{
    if (s_all->s_player.money < s_all->s_selected.tur->price)
        sfSprite_setTexture(s_all->s_upgrade.sprite,
            s_all->s_upgrade.texture, sfTrue);
    else sfSprite_setTexture(s_all->s_upgrade.sprite,
            s_all->s_upgrade.texture3, sfTrue);
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_upgrade.sprite, NULL);
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_upgrade.gold, NULL);
}