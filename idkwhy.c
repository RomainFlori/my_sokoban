/*
** EPITECH PROJECT, 2019
** directory
** File description:
** idkwhy
*/

#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include "my.h"

int non_block_read_mode(struct termios * caps)
{
    caps->c_lflag &= ~ICANON;
    caps->c_cc[VMIN] = 1;
    caps->c_cc[VTIME] = 0;
    if (tcsetattr(0, 0, caps) == -1) {
        return (1);
    }
}

int recup_letter(void)
{
    struct termios caps;
    char buffer[1];

    tcgetattr(0, &caps);
    non_block_read_mode(&caps);
    while (read(0, buffer, 1) > 0){
        return (buffer[0]);
    }
    return (0);
}