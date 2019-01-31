/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** args
*/

#include "malloc.h"

bool check_args(size_t size)
{
    if (size == 0)
        return (false);
    if (Mlc == NULL)
        add_page(size);
    return (true);
}