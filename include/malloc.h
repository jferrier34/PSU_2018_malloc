/*
** EPITECH PROJECT, 2019
** malloc.h
** File description:
** malloc.h
*/

#ifndef _MALLOC_H_
    #define _MALLOC_H_

    #include <stdbool.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <pthread.h>
    #pragma pack(push, 1)
    /*
    **  structure of malloc
    */
    typedef struct malloc_s {
        struct malloc_s *next;
        size_t size;
        bool isFree;
    } malloc_t;

    typedef struct pages_s {
        struct pages_s *next;
        malloc_t *start;
        size_t sizeleft;
    } page_t;

    extern pthread_mutex_t malloc_mutex;
    extern page_t *Mlc;

    /*
    **  malloc.c
    */
    void *check_first(size_t my_nbr);
    void *malloc(size_t size);

#endif /* malloc.h */
