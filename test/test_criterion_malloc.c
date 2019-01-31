/*
** EPITECH PROJECT, 2019
** malloc project
** File description:
** Units tests for malloc project
*/

#include <criterion/criterion.h>

Test(get_first_page)
{
        char *my_test = (char *) malloc(10 * sizeof(char));
        free(my_test);

        cr_assert(true, "Every thinks is ok");
}
