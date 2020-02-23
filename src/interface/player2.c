/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** player2
*/

#include "defender.h"

int my_if(tuto_t *temp)
{
    if (temp->castle == 1 && temp->id != 0 && temp->scale.x <= 0.1)
        return (1);
    return (0);
}