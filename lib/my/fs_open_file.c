/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** open_file
*/

#include "../../include/include.h"

int fs_open_file(char const *filepath)
{
    int test;

    test = open(filepath, O_RDONLY);
    if (test >= 0)
        my_putstr("SUCCESS\n");
    else
        my_putstr("FAILURE\n");
    return (test);
}