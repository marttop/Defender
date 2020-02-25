/*
** EPITECH PROJECT, 2019
** my_putnbr
** File description:
** my_putnbr
*/

#include "defender.h"
#include "utils.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str) - 1;
    char temp;

    for (int i = 0; i < len; i++) {
        temp = str[i];
        str[i] = str[len];
        str[len] = temp;
        len--;
    }
    return (str);
}

char *strnbr(int n)
{
    int modulo, a = 10, i = 0;
    char *str = malloc(15);
    if (n == 0)
        str[i++] = n + 48;
    for (; n > 0;) {
        if (n < 10) {
            str[i++] = (48 + n);
            n = 0;
        }
        else {
            modulo = (n % a);
            n = (n - modulo) / a;
            str[i++] = 48 + modulo;
        }
    }
    str[i] = '\0';
    my_revstr(str);
    return (str);
}