/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** realloc
*/

#include "realloc.h"

pthread_mutex_t realloc_mutex = PTHREAD_MUTEX_INITIALIZER;

void *realloc(void *ptr, size_t size)
{
    void *new_malloc;
    malloc_t *old_malloc;

    if (ptr == NULL) {
        return (malloc(size));
    }
    if (ptr != NULL && size == 0) {
        free(ptr);
        return (NULL);
    }
    pthread_mutex_lock(&realloc_mutex);
    new_malloc = malloc(size);
    if (new_malloc == NULL)
        return (NULL);
    old_malloc = ptr - sizeof(malloc_t);
    new_malloc = memcpy(new_malloc, ptr, MIN(size, old_malloc->size));
    free(ptr);
    pthread_mutex_unlock(&realloc_mutex);
    return (new_malloc);
}