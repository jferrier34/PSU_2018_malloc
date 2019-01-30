/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** utils
*/

#include "malloc.h"
#include <stdio.h>

void show_alloc_mem()
{
    printf("break : %ld\n", (long)sbrk(0));
    for (page_t *tmp = Mlc; tmp; tmp = tmp->next) {
        printf("Page, taille : %ld\n", tmp->sizeleft);
        for (malloc_t *temp = (malloc_t*)(tmp + 1); temp; temp = temp->next) {
            printf("\t%zu - %zu : %lu bytes\n", temp, ((char*)(temp + 1) + temp->size), temp->size + sizeof(malloc_t));
        }
    }
}