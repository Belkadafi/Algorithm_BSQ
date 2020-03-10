/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** bsq_calc
*/

#include "include.h"

void check_lines(int check, int *x, dimension_t base);

int which_one (int a, int b, int c)
{
    if (a <= b  && a <= c)
        return a;
    if (b <= a && b <= c)
        return b;
    return c;
}

square_t my_find_square(int *square, dimension_t base, int siz)
{
    int i = ((base.length - 1) == base.height) ? 0 : 1;
    int size = (base.length - i) * base.height;
    square_t final_square = {0, 0};

    for (int i = base.length; i < size; i += 1) {
        if (square[i] > 0 && (i % base.length) > 0)
            square[i] = which_one(square[i - 1], square[i - base.length],
            square[i - base.length - 1]) + 1;
        if (square[i] == siz) {
            final_square.size = square[i];
            final_square.i = i;
            return (final_square);
        }
    }
    return (final_square);
}

int *my_parser(char *buffer, int *square, dimension_t base)
{
    int i = 0;
    int y = (base.height - 1);

    for (int x = base.length - 1; buffer[i] != '\0'; i += 1, x -= 1) {
        if (buffer[i] == '.')
            square[i] = 1;
        else if ((buffer[i] == 'o') || (buffer[i] == '\n')) {
            square[i] = (buffer[i] == 'o') ? 0 : -3;
            if (square[i] == -3)
                y -= 1;
            check_lines(square[i], &x, base);
        }
        else {
            square[0] = 69;
            break;
        }
    }
    return (check_height(y, square));
}

void dis_square(char *buffer, square_t final_square, dimension_t base, int test)
{
    if (base.height != 1 && base.length != 2) {
        for (int icr = 0; icr < final_square.size; icr += 1,
        final_square.i -= base.length, test = 0) {
            for (int x = final_square.i; test < final_square.size; test += 1) {
                buffer[x] = 'x';
                x -= 1;
            }
        }
    }
    else {
        for (int i = 0; buffer[i] != '\0' && buffer[i] != 'x'; i += 1) {
            if (buffer[i] == '.') {
                buffer[i] = 'x';
            }
        }
    }
    write (1, buffer, my_strlen(buffer));
    my_putchar('\n');
}

int bsq_calc(char const *filepath, int lines, int columns, char *buffer)
{
    int fs = open (filepath, O_RDONLY);
    dimension_t base;
    square_t final_square;
    int *square;
    int test = 0;
    int size = my_get_size(&buffer, &base, lines, columns);

    if (retrieve_buffer(lines, columns, fs, &buffer))
        return 1;
    square = malloc(sizeof(int) * lines * columns);
    my_parser(buffer, square, base);
    final_square = my_find_square(square, base, size);
    if (square[0] == 69)
        return (my_print_error());
    free(square);
    dis_square(buffer, final_square, base, test);
    free(buffer);
}