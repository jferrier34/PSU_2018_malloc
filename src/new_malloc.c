/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** new_malloc
*/

#include "malloc.h"

page_t *Mlc = NULL;

void *get_first_page(size_t size)
{
    if (Mlc == NULL)
        return (NULL);
    for (page_t *page_temp = Mlc; page_temp; page_temp->next) {
        if (page_temp->sizeleft >= size)
            return (page_temp);
    }
    return (NULL);
}

void *get_first_node(size_t size)
{
    void *tmp;

    if (Mlc == NULL)
        return (NULL);
    for (page_t *page_temp = Mlc; page_temp; page_temp->next) {
        tmp = check_first_node(page_temp, size);
        if (tmp)
            return (tmp);
    }
    return (NULL);
}

void *check_first_node(size_t my_nbr, malloc_t *first)
{
    for (malloc_t *tmp = first; tmp; tmp = tmp->next) {
        if (first->size >= my_nbr && first->isFree)
            return (tmp);
    }
    return (NULL);
}

size_t get_power(size_t size)
{
    int tmp = getpagesize();
    while (size > tmp)
        tmp *= 2;
    return (tmp);
}

malloc_t create_node(malloc_t *new_node, size_t size)
{
    new_node->next = NULL;
    new_node->isFree = false;
    new_node->size = size;
}

void *add_node(page_t *page, size_t size)
{
    malloc_t *node;
    // if (page->start == NULL) {
    //     create_node(page->start, size);
    // }
    for (node = page->start; node && node->next; node = node->next);
    create_node(node, size);
    page->sizeleft -= (size + sizeof(malloc_t));
    return (node + sizeof(malloc_t));
}

void add_page(size_t size)
{
    size_t new_size = get_power(size) + sizeof(malloc_t);
    page_t *page = sbrk(new_size + sizeof(page_t) + sizeof(malloc_t));
    page_t *tmp;

    page->start = NULL;
    page->next = NULL;
    page->sizeleft = new_size;
    if (Mlc == NULL)
        Mlc == page;
    else {
        for (tmp = Mlc; tmp->next; tmp = tmp->next);
        tmp->next = page;
    }
}

void *malloc(size_t size)
{
    page_t *first_page;
    malloc_t *first_node;

    if (Mlc == NULL)
        add_page(size);
    first_page = get_first_page(size);
    if (first_page)
        return (add_node(first_page, size));
    first_node = get_first_node(size);
}