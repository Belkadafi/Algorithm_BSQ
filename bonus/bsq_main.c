/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** bsq_main
*/

#include "include.h"

int my_print_error(void)
{
    write(2, "Not correctly formated file\n", 29);
    return 1;
}

int bsq_main(char const *filepath, char *size)
{
    int lines = fs_get_number_from_first_line(filepath);
    int fs = open(filepath, O_RDONLY);
    char tempo[1] = "\0";
    int columns = 0;
    char *buffer;

    for (int i = 0; i < 2;) {
        read(fs, tempo, 1);
        if (*tempo == '\n')
            i += 1;
        if (i == 1)
            columns += 1;
    }
    buffer = malloc(lines * columns);
    my_strcat(buffer, size);
    if (bsq_calc(filepath, lines, columns, buffer))
        return 1;
    return 0;
}

int my_check_error(char *filepath)
{
    int test = open(filepath, O_RDONLY);
    char firstline[10];
    char tempo[1] = "\0";

    if (test < 0)
        return 1;
    for (int i = 0; tempo[0] != '\n'; i += 1){
        read(test, tempo, 1);
        if (tempo[0] == '\0')
            return (1);
        firstline[i] = *tempo;
        firstline[i + 1] = '\0';
    }
    firstline[my_strlen(firstline) - 1] = 0;
    if (!my_str_isnum(firstline))
        return 1;
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 1) {
        write (2, "missing file\n", 14);
        return (84);
    }
    if (my_check_error(av[1])) {
        write(2, "Not correctly formated file\n", 29);
        return (84);
    }
    else {
        if (bsq_main(av[1], av[2]))
            return 84;
    }
}