/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** lib.c
*/

#include "my.h"

void 		my_putchar(char c)
{
	write(1, &c, 1);
}

void 		my_putstr(char *str)
{
	int i = 0;
	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
}

char 		*get_file(char *path)
{
	int fd;
	int ret;
	char *buffer = NULL;
	char *file = NULL;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return ("error");
	buffer = malloc(sizeof(char) * SIZE_BLOCK + 1);
	while ((ret = read(fd, buffer, SIZE_BLOCK)) != 0) {
		if (ret == -1)
			return ("error");
		buffer[ret] = '\0';
		file = my_strcat(file, buffer);
	}
	free(buffer);
	return (file);
}

int 		my_getnbr(char const *str)
{
	int sign;
	int res;
	sign = 1;
	res = 0;

	while (*str == '-' || *str == '+') {
		if (*str == '-') {
			sign = sign * -1;
			str = str + 1;
		}
		while (*str >= '0' && *str <= '9') {
			res = (res * 10) + (*str - '0');
			str = str + 1;
		}
		res = res * sign;
		return (res);
	}
	return (0);
}

int 	my_strncmpr(char *s1, char *s2, int n)
{
	for (int i = 0; i < n; i++) {
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}