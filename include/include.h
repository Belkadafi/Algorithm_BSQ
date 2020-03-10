/*
** EPITECH PROJECT, 2019
** include
** File description:
** include
*/

#define INCLUDE_H_

#include "my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct square_s {
    int i;
    int size;
} square_t;

typedef struct dimension_s {
    int length;
    int height;
} dimension_t;
