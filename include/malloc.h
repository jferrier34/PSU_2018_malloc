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

    //#define PAGE 4096

/*
**  structure of malloc
*/
    typedef struct malloc_s {
        struct malloc_s *next;
        //void *data;
        size_t size;
        int isFree;
    } malloc_t;

    malloc_t *Malloc;

/*
**  malloc.c
*/
    void *check_first(size_t my_nbr);
    void *malloc(size_t size);

#endif /* malloc.h */
