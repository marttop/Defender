/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** utils
*/

#ifndef UTILS_H_
#define UTILS_H_
#include <stdlib.h>
#include <unistd.h>
#include "defender.h"


typedef struct parsor {
    sfVector2f pos;
    int i;
    char *map;
} parsor_t;

void parse_map(all_t *s_all);
char *my_strdup(char *str);
int my_strlen(char *str);
int my_strlen_n(char *str);
char *strnbr(int n);
char *adapt(char const *filepath);
char *get_file(char const *filepath);
void parse_wave(all_t *s_all);
int get_int(char *av);


#endif /* !UTILS_H_ */
