/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** my_strlen
*/

#include "defender.h"
#include "utils.h"

int my_strlen_n(char *str)
{
    int i = 0;
    if (str == NULL)
        return (0);
    for (; str[i] != '\n'; i++);
    return (i);
}

int my_strlen(char *str)
{
    int i = 0;
    if (str == NULL)
        return (0);
    for (; str[i] != '\0'; i++);
    return (i);
}