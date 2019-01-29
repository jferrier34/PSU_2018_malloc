/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** utils
*/

#include "malloc.h"

void show_alloc_mem()
{
    page_t *tmp;

    tmp = Mlc;
    printf("break : 0x%lX\n", (size_t)sbrk(0));
    while (tmp)
    {
        printf("0x%lX - 0x%lX : %lu bytes\n", tmp, tmp + tmp->size + sizeof(tmp), tmp->size + sizeof(tmp));
        tmp = tmp->next;
    }
}