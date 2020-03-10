/*
** EPITECH PROJECT, 2019
** my get nbr base
** File description:
** get nbr in decimal
*/

#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src);

int my_getnbr(char const *str);

int my_array_to_nbr(char **src)
{
    int result = 0;
    for (int i = 0; src[i] != NULL; i++)
        result = result + my_getnbr(src[i]);
    return (result);
}

int my_strconvert(char *src, char const *base)
{
    char **retn;
    retn = malloc(my_strlen(src));
    for (int i = 0; retn[i] != NULL; i++)
        retn[i] = malloc(2);
    int j = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        while (src[i] != base[j])
            j++;
    }
    int x = my_array_to_nbr(retn);
    return x;
}

int my_getnbr_base(char const *str, char const *base)
{
    char nbr[my_strlen(str)];
    my_strcpy(nbr, str);
    return (my_strconvert(nbr, base));
}