/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** parse_map
*/

#include "utils.h"
#include "defender.h"

int get_file_size(int fd)
{
    char c;
    int i = 0;
    for (; read(fd, &c, 1) == 1; i++);
    return (i);
}

char *get_map(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int file_size = get_file_size(fd);
    char *map = malloc(file_size + 1);
    close(fd);
    fd = open(filepath, O_RDONLY);
    read(fd, map, file_size);
    map[file_size] = '\0';
    close(fd);
    return (map);
}

support_t *element_tree(all_t *s_all, support_t *s_support, parsor_t *s_parsor)
{
    if (s_all->s_map.map[s_parsor->i] == 'O') {
        s_support = fill_support(s_support,
        s_parsor->pos, "sprites/turret_support.png", 'O');
        s_parsor->pos.x += 120;
    } if (s_all->s_map.map[s_parsor->i] == 'S') {
        s_support = fill_support(s_support,
        s_parsor->pos, "sprites/spawner.png", 'S'), s_parsor->pos.x += 120;
    } if (s_all->s_map.map[s_parsor->i] == 'C') {
        s_support = fill_support(s_support, s_parsor->pos,
        "sprites/castle.png", 'C'), s_parsor->pos.x += 120;
    } if (s_all->s_map.map[s_parsor->i] == 'G') {
        s_support = fill_support(s_support, s_parsor->pos,
        "sprites/ground.png", 'G'), s_parsor->pos.x += 120;
    }
    if (s_all->s_map.map[s_parsor->i] == '\n') {
        s_parsor->pos.y += 120, s_parsor->pos.x = 0;
    }
    return (s_support);
}

void parse_map(all_t *s_all)
{
    parsor_t s_parsor = {0};
    support_t *s_support = NULL;
    s_parsor.pos.y = 30, s_all->s_map.map = get_map("maps/map1");
    for (; s_all->s_map.map[s_parsor.i] != '#'; s_parsor.i += 1) {
        if (s_all->s_map.map[s_parsor.i] == ' ') {
            s_parsor.pos.x += 120;
        }
        else s_support = element_tree(s_all, s_support, &s_parsor);
    }
    s_all->s_map.s_support = s_support;
}