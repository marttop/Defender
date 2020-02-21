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

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef READ_SIZE
#define READ_SIZE (30)
#endif

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

char *get_next_line(int fd);

#endif /* !UTILS_H_ */
