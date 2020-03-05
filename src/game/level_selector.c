/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** level_selector
*/

#include "defender.h"
#include "utils.h"

levels_t *fill_levels(levels_t *old, char *filepath, sfVector2f pos)
{
    static int id = 1;
    levels_t *new = malloc(sizeof(levels_t));
    new->sprite = sfSprite_create();
    new->texture = sfTexture_createFromFile("sprites/clicked.png", NULL);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    new->pos = pos;
    new->id = id;
    new->filepath = filepath;
    id++;
    sfSprite_setPosition(new->sprite, pos);
    new->next = old;
    return (new);
}

void init_level_buttons(all_t *s_all)
{
    s_all->s_levels = NULL;
    char *tab[3] = {"custom_maps/custom_map_4", "maps/map2", "maps/map3"};
    sfVector2f pos = (sfVector2f){300, 300};
    for (int i = 0; i != 3; i++) {
        s_all->s_levels = fill_levels(s_all->s_levels, tab[i], pos);
        pos.x += 200;
    }
}

void select_map(all_t *s_all, levels_t *temp)
{
    s_all->s_wave_c.round = free_mobs(s_all->s_wave_c.round);
    s_all->s_wave_c.square = free_mobs(s_all->s_wave_c.square);
    s_all->s_wave_c.triangle = free_mobs(s_all->s_wave_c.triangle);
    s_all->s_wave_c.go = 0, s_all->s_wave_c.min = 0, s_all->s_wave_c.start = 0;
    s_all->s_wave_c.strwave = strnbr(s_all->s_wave_c.min);
    parse_wave(s_all);
    s_all->s_wave_c.strwave = strnbr(0);
    my_strcat(s_all->s_wave_c.strwave, s_all->s_wave_c.base);
    sfText_setString(s_all->s_wave_c.text, s_all->s_wave_c.strwave);
    s_all->s_tuto = free_mobs(s_all->s_tuto);
    s_all->s_turret = free_turret(s_all->s_turret);
    s_all->s_map.map = adapt(temp->filepath);
    s_all->s_map.s_support = free_support(s_all->s_map.s_support);
    s_all->s_map.s_support = parse_map(s_all->s_map.map);
    s_all->s_map.castle_pos = get_castle_position(s_all);
    s_all->s_map.spawner_pos = get_spawner_position(s_all);
    generate_round_mobs(s_all);
    s_all->s_game.scene = 1;
}

void map_selector_release(all_t *s_all)
{
    sfVector2i mouse_pos =
    sfMouse_getPositionRenderWindow(s_all->s_game.window);
    levels_t *temp = s_all->s_levels;
    if (s_all->s_game.scene != -1)
        return;
    while (temp != NULL) {
        if ((mouse_pos.x > temp->pos.x && mouse_pos.x < temp->pos.x + 120)
        && (mouse_pos.y > temp->pos.y && mouse_pos.y < temp->pos.y + 120)) {
            select_map(s_all, temp);
        }
        temp = temp->next;
    }
}

void display_level_selector(all_t *s_all)
{
    levels_t *temp = s_all->s_levels;
    while (temp != NULL) {
        sfRenderWindow_drawSprite(s_all->s_game.window, temp->sprite, NULL);
        temp = temp->next;
    }
}