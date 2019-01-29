/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** nodes
*/

#include "malloc.h"

malloc_t *check_first_node(malloc_t *first, size_t size)
{
    for (malloc_t *tmp = first; tmp; tmp = tmp->next) {
        if (first->size >= size && first->isFree)
            return (tmp);
    }
    return (NULL);
}

void *get_first_node(size_t size)
{
    malloc_t *tmp;

    if (Mlc == NULL)
        return (NULL);
    for (page_t *page_temp = Mlc; page_temp; page_temp = page_temp->next) {
        tmp = check_first_node((malloc_t*)(page_temp + sizeof(page_t)), size);
        if (tmp) {
            tmp->isFree = false;
            return (tmp + sizeof(malloc_t));
        }
    }
    return (NULL);
}

void create_node(malloc_t *new_node, size_t size)
{
    new_node->next = NULL;
    new_node->isFree = false;
    new_node->size = size;
}

void *add_node(page_t *page, size_t size)
{
    malloc_t *node = (malloc_t*)(page + sizeof(page_t));

    for (; node->next; node = node->next);
    create_node(node, size);
    page->sizeleft -= (size + sizeof(malloc_t));
    return (node + sizeof(malloc_t));
}