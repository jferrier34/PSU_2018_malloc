/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** args
*/

#include "malloc.h"

bool check_args(size_t size)
{
    pthread_mutex_lock(&malloc_mutex);
    if (size >= 9223372036854775807) {
        pthread_mutex_unlock(&malloc_mutex);
        return (false);
    }
    if (Mlc == NULL)
        add_page(size);
    return (true);
}