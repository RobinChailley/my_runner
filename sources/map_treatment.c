/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** check.c
*/

#include "my.h"

int 		len_line(char *map)
{
	int i = 0;
	while (map[i] != '\n') {
		i++;
	}
	return (i);
}

int 		**char_star_to_int_2d(char *map)
{
	int **map2d = malloc(sizeof(int *) * 20);
	int x = 0;

	for (int i = 0; i < 20; i++) {
		map2d[i] = malloc(sizeof(int) * len_line(map));
	}
	for (int j = 0; j < 20 && map[x+1] != '\0'; j++) {
		for (int i = 0; i < len_line(map) && map[x+1] != '\0'; i++) {
			if (map[x] == '\n')
				x++;
			map2d[j][i] = map[x];
			x++;
		}
	}
	return (map2d);
}

void 		map_reader(all_t *all, char *av)
{
	char *map = get_file(av);
	int **map2d = NULL;

	map2d = char_star_to_int_2d(map);
	for (int j = 0; j < 20; j++) {
		for (int i = 0; i < len_line(map); i++) {
			create_all_map(map2d, i, j, all);
		}
	}
}