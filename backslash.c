/*
** EPITECH PROJECT, 2019
** directory
** File description:
** backslash
*/

int backslash(char *buffer)
{
    int i = 1;
    int n = 0;
    while (buffer[i] != '\0') {
        i++;
        if (buffer[i] == '\n') {
            i++;
            n++;
        }
    }
    n++;
    return (n);
}