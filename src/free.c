/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** free
*/

#include "free.h"

void free(void *ptr)
{
    if (ptr == NULL)
        return;
    ptr -= sizeof(malloc_t);
    ((malloc_t*)ptr)->isFree = true;
}