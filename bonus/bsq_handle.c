/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** bsq_handle
*/

#include "include.h"

int check_lines(int check, int *x, dimension_t base)
{
    if (check == -3) {
        if (*x != 0)
            return 1;
        else
            *x = base.length;
    }
    return 0;
}

int retrieve_buffer(int lines, int columns, int fs, char **buffer)
{
    int read_size = lines * columns;
    char tempo[1] = "\0";

    while (*tempo != '\n')
        read(fs, tempo, 1);
    read(fs, *buffer, read_size - 1);
    if (*tempo != 0 && *tempo != '\n')
        return (my_print_error());
    return 0;
}

int *check_height(int y, int *square)
{
    if (y != 0)
        square[0] = 69;
    return (square);
}

int my_get_size(char **buffer, dimension_t *base, int lines, int columns)
{
    int size = my_getnbr(*buffer);

    base->height = lines;
    base->length = columns;
    return (size);
}