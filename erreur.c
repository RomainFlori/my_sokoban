/*
** EPITECH PROJECT, 2019
** directory
** File description:
** erreur
*/

#include "my.h"

int erreur(char const *filepath, int fd)
{
    if (fd == -1) {
        write(1, "FAILURE\n", 8);
        return (84);
    }
}

int erreur1(int nubr)
{
    if (nubr == -1) {
        write(1, "read failed\n", 12);
        return (84);
    }
    else
        return (0);
}

int erreur2(char *buffer)
{
    int d = 0;
    while (buffer[d] != '\n') {
        if (buffer[d] != '#') {
            return (84);
        }
        d++;
    }
    return (0);
}