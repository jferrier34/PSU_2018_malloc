/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** free
*/

#include "free.h"

pthread_mutex_t free_mutex = PTHREAD_MUTEX_INITIALIZER;

void free(void *ptr)
{
    pthread_mutex_lock(&free_mutex);
    if (ptr == NULL) {
        pthread_mutex_unlock(&free_mutex);
        return;
    }
    ptr -= sizeof(malloc_t);
    ((malloc_t*)ptr)->isFree = true;
    pthread_mutex_unlock(&free_mutex);
}