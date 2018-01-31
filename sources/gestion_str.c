/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** gestion_str.c
*/

#include "my.h"

void	reverse_str(char *str)
{
	int i = 0;
	int j = 0;
	char c;

	for (i = 0, j = my_strlen(str)-1; i<j; i++, j--) {
		c = str[i];
		str[i] = str[j];
		str[j] = c;
	}
}

void 	my_getcharstar(int nb, char *str)
{
	int i = 0;
	int sign = nb;

	if (sign < 0)
		nb = -nb;
	do {
		str[i++] = nb % 10 + '0';
	} while ((nb /= 10) > 0);
	if (sign < 0)
		str[i++] = '-';
	str[i] = '\0';
	reverse_str(str);
}

int 		my_strlen(char *str)
{
	int i = 0;
	if (str != NULL) {
		while (str[i] != '\0') {
			i++;
		}
	}
	return (i);
}

char 		*my_strcat(char *s1, char *s2)
{
	int i = 0;
	int a = 0;
	char *new = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
	if (s1 != NULL) {
		while(s1[i] != '\0') {
			new[i] = s1[i];
			i++;
		}
	}
	if (s2 != NULL) {
		while (s2[a] != '\0') {
			new[i] = s2[a];
			i++;
			a++;
		}
	}
	return (new);
}
