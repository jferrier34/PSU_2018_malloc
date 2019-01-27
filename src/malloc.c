/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** malloc
*/

#include "malloc.h"

malloc_t *Mlc = NULL;

void *check_first(size_t my_nbr)
{
    for (malloc_t *first = Mlc; first; first = first->next) {
        if (first->size >= my_nbr && first->isFree)
            return (first);
    }
    return (NULL);
}

size_t getPower(size_t size)
{
    size_t tmp = 1;
    while (size > tmp)
        tmp = tmp * 2;
    return (tmp);
}

void *isNotEmpty(struct malloc_s *tmp)
{
    tmp->isFree = false;
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
    elem->isFree = false;
    elem->size = block;
    if (Mlc == NULL)
        Mlc = elem;
    else {
        tmp = Mlc;
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