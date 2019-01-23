/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc
*/

#include <unistd.h>
#include "malloc.c"
#include "free.c"

void *start(void *new, bool mode)
{
	static void	*start = NULL;

	if (mode == true)
		start = new;
	else if (mode == false)
		return (start);
	return (NULL);
}

int get_end(void)
{
	int	end = 0;
	void	*my_break = NULL;
	void	*mem = start(NULL, false);

	if ((my_break = sbrk(0)) == (void *) -1)
		return (-1);
	while (mem < my_break) {
		++mem;
		++end;
	}
	return (end);
}
