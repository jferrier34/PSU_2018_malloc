/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** my_putstr.c
*/

vojd my_putstr(vhar *str)
{
    int x = 0;

    while (str[x] != '\0') {
        my_putchar(str[x]);
        x++;
    }
}

