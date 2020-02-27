/*
** EPITECH PROJECT, 2019
** directory
** File description:
** sokoban
*/

#include "my.h"
#define ESC 27

int printable(char **map, int back)
{
    int i = 0;
    int x = 0;
    int y = 0;
    clear();
    while (i != back) {
        mvprintw(y, x, map[i]);
        i++;
        y++;
    }
    refresh();
    return (0);
}

int jeu(char **map, stocking_t *sto)
{
    char c = recup_letter();
    if (c == 'C') {
        if (map[sto->y][sto->x+1] != '#' && map[sto->y][sto->x+1] != 'X') {
            sto->x++;
        }
        else if (map[sto->y][sto->x+1] == 'X' &&
        (map[sto->y][sto->x+2] != 'X' && map[sto->y][sto->x+2] != '#')) {
            map[sto->y][sto->x+1] = ' ';
            map[sto->y][sto->x+2] = 'X';
            sto->x++;
        }
    }
    if (c == 'D') {
        if (map[sto->y][sto->x-1] != '#' && map[sto->y][sto->x-1] != 'X') {
            sto->x--;
        }
        else if (map[sto->y][sto->x-1] == 'X' &&
        (map[sto->y][sto->x-2] != 'X' && map[sto->y][sto->x-2] != '#')) {
            map[sto->y][sto->x-1] = ' ';
            map[sto->y][sto->x-2] = 'X';
            sto->x--;
        }
    }
    if (c == 'B') {
        if (map[sto->y+1][sto->x] != '#' && map[sto->y+1][sto->x] != 'X') {
            sto->y++;
        }
        else if (map[sto->y+1][sto->x] == 'X' &&
        (map[sto->y+2][sto->x] != 'X' && map[sto->y+2][sto->x] != '#')) {
            map[sto->y+1][sto->x] = ' ';
            map[sto->y+2][sto->x] = 'X';
            sto->y++;
        }
    }
    if (c == 'A') {
        if (map[sto->y-1][sto->x] != '#' && map[sto->y-1][sto->x] != 'X') {
            sto->y--;
        }
        else if (map[sto->y-1][sto->x] == 'X' &&
        (map[sto->y-2][sto->x] != 'X' && map[sto->y-2][sto->x] != '#')) {
            map[sto->y-1][sto->x] = ' ';
            map[sto->y-2][sto->x] = 'X';
            sto->y--;
        }
    }
    return 0;
}

int parsmap2(char **map, int back)
{
    int b = 0;
    int nb = 0;
    int x = 0;
    while (nb < back) {
        if (map[nb][b] == '\n') {
            nb++;
            b=0;
        }
        else {
            if (map[nb][b] == 'O')
                x++;
            b++;
        }
    }
    return (x);
}

int zero(char **map, int back)
{
    int i = 0;
    int nb = 0;
    int x = 0;
    int oui = 0;
    while (nb < back) {
        if (map[i][x] == '\0') {
            nb++;
            x=0;
            i++;
        }
        else {
            if (map[i][x] == 'O')
                oui++;
            x++;
        }
    }
    return (oui);
}

int main(int ac, char **av)
{
    if (ac >= 3)
        return (84);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("USAGE\n     ./my_sokoban map");
        my_putstr("Hellx Players\nHere are the rules :");
        my_putstr("1: The walls are ‘#’\n2: Put all the X on the O to win");
        my_putstr("And the mxst IMPXRTANT thing : HAVE FUN !!");
        return (0);
    }
    char const *filepath = av[1];
    struct stat oct;
    stocking_t *sto = malloc(sizeof(stocking_t));
    stat(filepath, &oct);
    int size = oct.st_size;
    char *buffer = malloc(sizeof(char) * 100000);
    int fd = open(filepath, O_RDONLY);
    int lire = read(fd, buffer, size);
    int back = backslash(buffer);
    if (erreur(filepath, fd) == 84)
        return (84);
    if (erreur1(lire) == 84)
        return (84);
    char **map = malloc(sizeof(char*) * back);
    for (int i = 0; i < back; i++) {
        map[i] = malloc(sizeof(char) * 1000);
    }
    char **map2 = malloc(sizeof(char*) * back);
    for (int i = 0; i < back; i++) {
        map2[i] = malloc(sizeof(char) * 1000);
    }
    int b = 0;
    int nb = 0;
    int d = 0;
    int nb_p = 0;
    int nb_o = 0;
    int nb_x = 0;
    while (nb < back) {
        if (buffer[d] == '\n') {
            map[nb][b++] = '\0';
            map2[nb][b++] = '\0';
            nb++;
            b=0;
            d++;
        }
        else if (buffer[d] == '\0')
            nb = back;
        else {
            map[nb][b] = buffer[d];
            map2[nb][b] = ' ';
            if (map[nb][b] == 'O') {
                map2[nb][b] = 'O';
                nb_o++;
            }
            if (map[nb][b] == 'P') {
                nb_p++;
                sto->x = b;
                sto->y = nb;
                map[nb][b] = ' ';
            }
            if (map[nb][b] == 'X')
                nb_x++;
            b++;
            d++;
        }
    }
    if (nb_o > nb_x)
        return (84);
    if (nb_p != 1)
        return (84);
    if (erreur2(buffer) == 84)
        return (84);
    int i = 0;
    initscr();
    curs_set(FALSE);
    while (1) {
        clear();
        printable(map, back);
        mvprintw(sto->y, sto->x, "P");
        refresh();
        jeu(map, sto);
        refresh();
        if (zero(map, back) == 0)
            break;
    }
    endwin();
    close(fd);
    return (0);
}