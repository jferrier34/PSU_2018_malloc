/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc
*/

#include "../include/free.h"

void free(void *ptr)
{
    if (ptr == NULL)
        return;
    ptr = ptr - sizeof(malloc_t);
    ((malloc_t*)ptr)->isFree = 0;
}

