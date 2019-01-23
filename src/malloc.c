/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "./malloc.h"

bool add_page(int size, void *mem)
{
	int	mult = 1;

	while (PAGE * mult < size)
		++mult;
	if (((int *) (mem))[0] == FREE) {
		((int*) (mem))[1] += PAGE * mult;
		if (sbrk(PAGE * mult) == (void *) -1)
			return (false);
	}
	else {
		((int *) (mem))[2] = NOT_LAST;
		((int *) (mem + ((int *) (mem))[1] + HEADER))[0] = FREE;
		((int *) (mem + ((int *) (mem))[1] + HEADER))[1] = (PAGE * mult) - HEADER;
		((int *) (mem + ((int *) (mem))[1] + HEADER))[2] = LAST;
	}
	return (true);
}

void *malloc(size_t size)
{
	void *res = NULL;
	void *my_start = NULL;

	my_start = start(NULL, false);
	if (my_start == NULL || get_end() == 0) {
	    //affect the var my_start to a new chunck
	start(my_start, true);
	}
	if (my_start == NULL)
		return (NULL);
	//affect the var res to a new header with size and my_start params)
	return (res);
}
