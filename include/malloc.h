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

#define FREE 0
#define FULL 1
#define EMPTY 0
#define TAKEN 1
#define LAST 0
#define NOT_LAST 1
#define HEADER 12
#define PAGE 4096

typedef struct malloc_s {
    struct malloc_s *data;
    int size;
    bool isfree;
} malloc_t;

/*
** lib.c
*/
void my_putchar(char c);
void my_putstr(const char *src);
void my_putnbr(int nb);

/*
** malloc.c
*/
void *malloc(size_t size);
bool add_page(int size, void *mem);


/*
** free.c
*/
void *free_my_ptr(void *ptr);
void add_ptr(void *mem);
void add_block(void);
void move_break(void *mem);
void free(void *ptr);

/*
** intern_functions.c
*/

void *start(void *new, bool mode);
int get_end(void);

# endif /* malloc.h */
