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

char *my_strcpy(char *dest, char *src)
{
    int i = 0;
    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

void my_swap(char *a, char *b)
{
    char i = *a;
    *a = *b;
    *b = i;
}

char *strnbr_float(float n)
{
    int i = n < 1 ? 1 : 0;
    n = n < 1 ? n * 1000 : n * 100;
    if (n == 0) return (my_strdup("0"));
    char *str = strnbr((int)n);
    int len = my_strlen(str) + 2;
    char *new = malloc(sizeof(char) * len + 1);
    new = my_strcpy(new, str), new[len - 1] = '\0';
    int n_len = my_strlen(new);
    if (i == 0) {
        new[n_len] = str[len - 3], new[n_len - 1] = str[len - 4];
        new[n_len - 2] = '.';
    } if (i == 1 && n >= 10) {
        new[4] = '\0', new[3] = new[1], new[2] = new[0], new[0] = '0';
        new[1] = '.';
    } if (i == 1 && n < 100 && n >= 10) {
        my_swap(&new[3], &new[2]), new[4] = '\0';
    } if (n < 10) new[0] = '0', new[1] = '\0';
    free(str);
    return (new);
}