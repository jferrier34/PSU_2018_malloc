/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc
*/

#include <unistd.h>
#include "./malloc.h"

void *free_my_ptr(void *ptr)
{
    void *mem = NULL;
    int end = 0;
    int cpt = 0;

    if ((mem = start(NULL, false)) == NULL || (end = get_end()) == -1)
        return (NULL);
    while (cpt <= end) {
        if (mem == ptr) {
            ((int *) (mem - HEADER))[0] = 0;
            return (mem - HEADER);
        }
        ++mem;
        ++cpt;
    }
    return (NULL);
}

void add_ptr(void *mem)
{
    int next_header = 0;

    next_header = ((int *) (mem + ((int *) (mem))[1] + HEADER))[1];
    if (((int *) (mem + ((int *) (mem))[1] + HEADER))[2] == LAST)
        ((int *) (mem))[2] = LAST;
    ((int *) (mem)) [1] += next_header + HEADER;
}

void add_block(void)
{
    void *mem = NULL;

    if ((mem = start(NULL, false)) == NULL)
        return;
    while (1) {
        if (((int *) (mem))[2] != LAST &&
            ((int *) (mem))[0] == FREE &&
            ((int *) (mem + ((int *) (mem))[1] + HEADER))[0] == FREE) {
                add_ptr(mem);
                mem = start(NULL, false);
            }
            else if (((int *) (mem))[2] != LAST)
                mem += ((int *) (mem))[1] + HEADER;
            else
                return;
    }
}


void		move_break(void *mem)
{
	void	*tpm = mem;
	void	*new_last = mem;
	int	give_back = 0;

	while (((int *) (tpm))[2] != LAST) {
		tpm += ((int *) (tpm))[1] + HEADER;
		if (((int *) (tpm))[2] != LAST)
			new_last = tpm;
	}
	give_back = ((int *) (tpm))[1] + HEADER;
	give_back *= -1;
	if (sbrk(give_back) == (void *) -1)
		return;
	if (get_end() != 0 && new_last != NULL) {
		((int *) (new_last))[2] = LAST;
	}
	return;
}


void free(void *ptr)
{
    void *mem = NULL;

    if ((mem = free_my_ptr(ptr)) == NULL)
        return;
    add_block();
    if ((mem = start(NULL, false)) == NULL)
        return;
    move_break(mem);
}

