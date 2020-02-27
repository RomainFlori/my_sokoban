/*
** EPITECH PROJECT, 2019
** directory
** File description:
** my
*/

#include <termios.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct stocking {
    int x;
    int y;
}t_stocking;
typedef struct stocking stocking_t;

int erreur(char const *filepath, int fd);
int erreur1(int nubr);
void my_putchar(char c);
int my_putnbr(int nb);
int backslash(char *buffer);
int my_putstr(char const *str);
int non_block_read_mode(struct termios * caps);
int recup_letter(void);
int erreur2(char *buffer);