/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** parsing.c
*/

#include "my.h"

int 		parsing(char **av, int ac)
{
	if (ac != 2) {
		my_putstr("./my_runner: bad arguments: 0 given but 1 is ");
		my_putstr("required\nretry with -h\n");
		return (84);
	}
	if (av[1][0] == '-' && av[1][1] == 'h') {
		my_putstr("Finite runner create with CSFML.\n\n");
		my_putstr("USAGE:\n\t./my_runner map.txt\n\n");
		my_putstr("OPTION:\n\t-h\t\tprint the usage and quit\n\n");
		my_putstr("USER INTERACTIONS\n\t-space key\tjump\n\t-escape");
		my_putstr(" key\tpause\n");
		return (1);
	} else
		return (0);
}
