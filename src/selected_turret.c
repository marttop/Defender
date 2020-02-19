/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** selected_turret
*/

#include "utils.h"
#include "defender.h"

void click_selected_turret(all_t *s_all)
{
    t_select_t *temp = s_all->s_t_select;
    sfVector2i mouse_pos =
    sfMouse_getPositionRenderWindow(s_all->s_game.window);
    while (temp != NULL) {
        if (check_selected_turret(s_all, temp)) {
            sfSprite_setPosition(s_all->s_selected2.clicked_s, temp->pos);
            s_all->s_selected2.click = 1, temp->clicked = 1;
            break;
        }
        else if ((mouse_pos.x >= s_all->s_hard_buttons.pos.x
        && mouse_pos.x <= s_all->s_hard_buttons.pos.x + 85)
        && (mouse_pos.y >= s_all->s_hard_buttons.pos.y
        && mouse_pos.y <= s_all->s_hard_buttons.pos.y + 85)){
            s_all->s_selected2.click = s_all->s_selected2.click == 1 ? 1 : 0;
            temp->clicked = temp->clicked == 1 ? 1 : 0;
        } else {
            s_all->s_selected2.click = 0, temp->clicked = 0;
        } temp = temp->next;
    }
}

void display_clicked_turret(all_t *s_all)
{
    if (s_all->s_selected2.click == 1)
        sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_selected2.clicked_s, NULL);
}