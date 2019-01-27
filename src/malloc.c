/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** malloc
*/

#include "../include/malloc.h"


void *check_first(size_t my_nbr)
{
    malloc_t *check_first = Malloc;

    for (int i = 0; check_first; check_first = check_first->next)
        if (check_first->size >= my_nbr && check_first->isFree == 0)
            return (check_first);
    return (NULL);
}

size_t getPower(size_t size)
{
    size_t tmp = 2;
    while (size > tmp)
        tmp = tmp * 2;
    return (tmp);
}

void *isNotEmpty(struct malloc_s *tmp)
{
    tmp->isFree = 1;
    return (tmp + sizeof(malloc_t));
}

void *mallocable(size_t block)
{
    malloc_t *elem;
    malloc_t *tmp;
    void *to_return;

    elem = sbrk(block + sizeof(malloc_t));
    to_return = elem;
    elem->next = NULL;
    elem->isFree = 1;
    elem->size = block;
    if (Malloc == NULL)
        Malloc = elem;
    else {
        tmp = Malloc;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = elem;
    }
    return (to_return + sizeof(malloc_t));
}

void *malloc(size_t size)
{
    void *is_ok = check_first(size);
    size_t my_power;

    if (is_ok != NULL) {
        is_ok = isNotEmpty(is_ok);
        return (is_ok);
    } else {
        my_power = getPower(size);
        is_ok = mallocable(my_power);
        return (is_ok);
    }
}
