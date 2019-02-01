/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** new_malloc
*/

#include "malloc.h"

page_t *Mlc = NULL;
pthread_mutex_t malloc_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t calloc_mutex = PTHREAD_MUTEX_INITIALIZER;

static void *get_first_page(size_t size)
{
    if (Mlc == NULL)
        return (NULL);
    for (page_t *page_temp = Mlc; page_temp; page_temp = page_temp->next) {
        if (page_temp->sizeleft >= (size + sizeof(malloc_t)))
            return (page_temp);
    }
    return (NULL);
}

static size_t get_power(size_t size)
{
    int tmp = getpagesize() * 32;

    while ((int)size > tmp)
        tmp += getpagesize();
    return ((size_t)tmp);
}

void add_page(size_t size)
{
    size_t new_size = get_power(size + sizeof(page_t) + sizeof(malloc_t));
    page_t *page = sbrk(new_size);
    page_t *tmp;
    malloc_t *temp = (malloc_t*)(page + 1);

    create_node(temp, size);
    page->next = NULL;
    page->sizeleft = new_size - sizeof(page_t) - sizeof(malloc_t);
    if (Mlc == NULL)
        Mlc = page;
    else {
        for (tmp = Mlc; tmp->next; tmp = tmp->next);
        tmp->next = page;
    }
}

void *calloc(size_t nmemb, size_t size)
{
    void *st_temp;

    if (nmemb == 0 || size == 0)
        return (NULL);
    st_temp = malloc(nmemb * size);
    if (st_temp == NULL)
        return (NULL);
    pthread_mutex_lock(&calloc_mutex);
    st_temp = memset(st_temp, 0, nmemb * size);
    pthread_mutex_unlock(&calloc_mutex);
    return (st_temp);
}

void *malloc(size_t size)
{
    page_t *first_page;
    malloc_t *first_node;
    void *tmp;

    pthread_mutex_lock(&malloc_mutex);
    if (!check_args(size)) {
        pthread_mutex_unlock(&malloc_mutex);
        return (NULL);
    }
    while (true) {
        first_page = get_first_page(size);
        if (first_page) {
            tmp = add_node(first_page, size);
            pthread_mutex_unlock(&malloc_mutex);
            return (tmp);
        }
        first_node = get_first_node(size);
        if (first_node) {
            pthread_mutex_unlock(&malloc_mutex);
            return (first_node);
        }
        add_page(size);
    }
}