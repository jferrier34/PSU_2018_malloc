/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** new_malloc
*/

#include "malloc.h"

page_t *Mlc = NULL;
pthread_mutex_t malloc_mutex = PTHREAD_MUTEX_INITIALIZER;

void *get_first_page(size_t size)
{
    if (Mlc == NULL)
        return (NULL);
    for (page_t *page_temp = Mlc; page_temp; page_temp = page_temp->next) {
        if (page_temp->sizeleft >= size)
            return (page_temp);
    }
    return (NULL);
}

size_t get_power(size_t size)
{
    int tmp = getpagesize();

    while ((int)size > tmp)
        tmp *= 2;
    return ((size_t)tmp);
}

void add_page(size_t size)
{
    size_t new_size = get_power(size) + sizeof(malloc_t);
    page_t *page = sbrk(new_size + sizeof(page_t));
    page_t *tmp;

    page->next = NULL;
    page->sizeleft = new_size;
    if (Mlc == NULL)
        Mlc = page;
    else {
        for (tmp = Mlc; tmp->next; tmp = tmp->next);
        tmp->next = page;
    }
}

void *malloc(size_t size)
{
    page_t *first_page;
    malloc_t *first_node;
    void *tmp;

    write(1, 'l', 1);
    //pthread_mutex_lock(&malloc_mutex);
    if (Mlc == NULL)
        add_page(size);
    first_page = get_first_page(size);
    if (first_page) {
        tmp = add_node(first_page, size);
        //pthread_mutex_unlock(&malloc_mutex);
        return (tmp);
    }
    first_node = get_first_node(size);
    if (first_node) {
        //pthread_mutex_unlock(&malloc_mutex);
        return (first_node);
    }
    add_page(size);
    return (malloc(size));
}