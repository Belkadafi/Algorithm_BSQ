/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** bsq_main_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int main_error(char *pathfile);

Test (main_error, should_return_84_file_does_not_exist)
{
    cr_assert_eq(84, main_error("toto"));
}

Test (main_error, should_return_84_non_correctly_formated_file)
{
    cr_assert_eq(84, main_error("Makefile"));
}