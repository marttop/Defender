/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** wave_button
*/

#include "defender.h"

void init_wave_button(all_t *s_all)
{
    s_all->s_hard_buttons2.pos = (sfVector2f){25, 870};
    s_all->s_hard_buttons2.sprite = sfSprite_create();
    s_all->s_hard_buttons2.texture =
        sfTexture_createFromFile("sprites/buttons/wave_button.png", NULL);
    s_all->s_hard_buttons2.texture2 =
        sfTexture_createFromFile("sprites/buttons/wave_button2.png", NULL);
    sfSprite_setTexture(s_all->s_hard_buttons2.sprite,
        s_all->s_hard_buttons2.texture, sfTrue);
    sfSprite_setPosition(s_all->s_hard_buttons2.sprite,
        s_all->s_hard_buttons2.pos);
}

void hitbox_wave_button(all_t *s_all)
{
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if ((mouse_pos.x >= s_all->s_hard_buttons2.pos.x
        && mouse_pos.x <= s_all->s_hard_buttons2.pos.x + 120)
        && (mouse_pos.y >= s_all->s_hard_buttons2.pos.y
        && mouse_pos.y <= s_all->s_hard_buttons2.pos.y + 120)) {
        sfSprite_setTexture(s_all->s_hard_buttons2.sprite,
            s_all->s_hard_buttons2.texture2, sfTrue);
    }
}

void release_wave_button(all_t *s_all)
{
    sfSprite_setTexture(s_all->s_hard_buttons2.sprite,
        s_all->s_hard_buttons2.texture, sfTrue);
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if ((mouse_pos.x >= s_all->s_hard_buttons2.pos.x
        && mouse_pos.x <= s_all->s_hard_buttons2.pos.x + 120)
        && (mouse_pos.y >= s_all->s_hard_buttons2.pos.y
        && mouse_pos.y <= s_all->s_hard_buttons2.pos.y + 120) && s_all->s_game.pause == 0) {
        if (s_all->s_wave_c.head->next != NULL && s_all->s_wave_c.start == 0) {
            s_all->s_wave_c.go = 1, s_all->s_wave_c.start = 1;
        } else if (s_all->s_wave_c.head->next != NULL &&
        s_all->s_wave_c.go == 0) {
            s_all->s_wave_c.go = 1;
            s_all->s_wave_c.head = s_all->s_wave_c.head->next;
        }
    }
        
}

void display_wave_button(all_t *s_all)
{
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_hard_buttons2.sprite, NULL);
}