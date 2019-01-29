/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** realloc
*/

#ifndef _REALLOC_H_
    #define _REALLOC_H_

    #include "malloc.h"
    #include "free.h"
    //#include <string.h>
    #define MIN(a, b) (((a) < (b)) ? (a) : (b))

    /*
    **  realloc.c
    */
    void *realloc(void *ptr, size_t size);

#endif /* !REALLOC_H_ */
