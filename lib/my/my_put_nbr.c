/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** my_put_nbr.c
*/

void my_putchar(char c);

int my_putstr(char *str);

int my_put_nbr(int nb);

int my_put_nbr(int nb)
{
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else
        my_putchar(48 + nb);
    return (0);
}

