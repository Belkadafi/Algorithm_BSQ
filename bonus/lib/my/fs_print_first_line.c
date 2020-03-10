/*
** EPITECH PROJECT, 2019
** bsq bootstrap
** File description:
** fs_print_first_line
*/

#include "../../include/include.h"

void fs_print_first_line(char const *filepath)
{
    int fs;
    char test[1];

    fs = fs_open_file(filepath);
    while (test[0] != '\n') {
        read(fs, test, 1);
        my_putstr(test);
    }
}