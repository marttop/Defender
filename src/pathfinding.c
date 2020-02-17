/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** pathfinding
*/

#include "defender.h"
#include "utils.h"

sfVector2f get_spawner_position(all_t *s_all)
{
    int x = 0, y = 0, i = 0;
    for (; s_all->s_map.map[i] != '#'; i++) {
        if (s_all->s_map.map[i] == '\n') {
            x = 0, y += 120;
            continue;
        }
        if (s_all->s_map.map[i] == 'S') break;
        x += 120;
    }
    s_all->s_map.spawner = i;
    return ((sfVector2f){x, y + 30});
}

void check_path(all_t *s_all, balls_t *s_balls)
{
    int line_len = my_strlen_n(s_all->s_map.map) + 1;
    char up = s_all->s_map.map[s_balls->map_pos - line_len];
    char down = s_all->s_map.map[s_balls->map_pos + line_len];
    char left = s_all->s_map.map[s_balls->map_pos - 1];
    char right = s_all->s_map.map[s_balls->map_pos + 1];
    if ((up == 'G' || up == 'C') && s_balls->previous != 'D') {
        move_up(s_balls, line_len);
        return;
    } if ((down == 'G' || down == 'C') && s_balls->previous != 'U') {
        move_down(s_balls, line_len);
        return;
    } if ((left == 'G' || left == 'C') && s_balls->previous != 'R') {
        move_left(s_balls);
        return;
    } if ((right == 'G' || right == 'C') && s_balls->previous != 'L') {
        move_right(s_balls);
        return;
    }
}