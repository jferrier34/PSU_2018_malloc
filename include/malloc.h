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

    #define PAGE 4096

    typedef struct malloc_s {
        struct malloc_s *next;
        void *data;
        size_t size;
        bool isfree;
    } malloc_t;

    void *malloc(size_t size);

#endif /* malloc.h */
