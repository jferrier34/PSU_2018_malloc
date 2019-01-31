/*
** EPITECH PROJECT, 2019
** malloc.h
** File description:
** malloc.h
*/

#ifndef _MALLOC_H_
    #define _MALLOC_H_

    #include <stdbool.h>
    #include <unistd.h>
    #include <pthread.h>
    #include <string.h>

    #pragma pack(push, 1)

    /*
    **  structure of malloc
    */
    typedef struct malloc_s {
        struct malloc_s *next;
        size_t size;
        bool isFree;
        int magic;
    } malloc_t;

    typedef struct pages_s {
        struct pages_s *next;
        size_t sizeleft;
    } page_t;

    extern pthread_mutex_t malloc_mutex;
    extern page_t *Mlc;

    /*
    **  nodes.c
    */
    malloc_t *check_first_node(malloc_t *first, size_t size);
    void *get_first_node(size_t size);
    void create_node(malloc_t *new_node, size_t size);
    void *add_node(page_t *page, size_t size);
    void add_page(size_t size);
    void show_alloc_mem();

    /*
    **  malloc.c
    */
    void *malloc(size_t size);
    void *calloc(size_t nmemb, size_t size);
    bool check_args(size_t size);

#endif /* malloc.h */
