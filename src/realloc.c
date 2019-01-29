/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** realloc
*/

#include "realloc.h"

void *realloc(void *ptr, size_t size)
{
    void *new_malloc;
    size_t tmp = 0;

    if (ptr == NULL)
        return (new_malloc);

    if (new_malloc = malloc(size) == NULL)
        return (NULL);

    while (size > tmp) {
        ((char *)new_malloc)[tmp] = ((char *)ptr)[tmp];
        tmp++;
    }
    free(ptr);
    return (new_malloc);
}