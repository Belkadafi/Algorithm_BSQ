/*
** EPITECH PROJECT, 2019
** bsq bootstrap
** File description:
** fs_get_number_from_line
*/

#include "../../include/include.h"

int fs_get_number_from_first_line(char const *filepath)
{
    int fs;
    int len = 0;
    char test[1] = "\0";
    char *buffer;
    int result;

    fs  = open(filepath, O_RDONLY);
    while (test[0] != '\n') {
        read(fs, test, 1);
        len += 1;
    }
    buffer = malloc(sizeof(char) * len);
    fs = open(filepath, O_RDONLY);
    read(fs, buffer, len);
    result = my_getnbr(buffer);
}