/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** realloc
*/

#include "realloc.h"

#include <stdio.h>

void *realloc(void *ptr, size_t size)
{
    pthread_mutex_lock(&malloc_mutex);
    pthread_mutex_unlock(&malloc_mutex);
    printf("La il use realloc\n");
    return (malloc(size));
}
