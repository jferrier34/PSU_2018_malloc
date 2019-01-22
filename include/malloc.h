/*
** EPITECH PROJECT, 2019
** malloc.h
** File description:
** malloc.h
*/

#ifndef _MALLOC_H_
#define _MALLOC_H_

#include <stdbool.h>

#define FREE 0
#define FULL 1
#define EMPTY 0
#define TAKEN 1
#define LAST 0
#define NOT_LAST 1
#define HEADER 12
#define PAGE 4096

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

# endif /* malloc.h */
