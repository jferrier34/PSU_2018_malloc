/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** free
*/

#include "free.h"

void free(void *ptr)
{
    //pthread_mutex_lock(&malloc_mutex);
    if (ptr == NULL) {
        //pthread_mutex_unlock(&malloc_mutex);
        return;
    }
    ptr -= sizeof(malloc_t);
    ((malloc_t*)ptr)->isFree = true;
    //pthread_mutex_unlock(&malloc_mutex);
}