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
    malloc_t *old_malloc;

    return malloc(size);
    // printf("LES AMIS\n");
    // //pthread_mutex_lock(&malloc_mutex);
    // if (ptr == NULL)
    //     return (malloc(size));
    // if (ptr != NULL && size == 0) {
    //     free(ptr);
    //     return (NULL);
    // }
    // new_malloc = malloc(size);
    // if (new_malloc == NULL)
    //     return (NULL);
    // old_malloc = ptr - sizeof(malloc_t);
    // new_malloc = memcpy(new_malloc, ptr, MIN(size, old_malloc->size));
    // free(ptr);
    // //pthread_mutex_unlock(&malloc_mutex);
    // return (new_malloc);
}