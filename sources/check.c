/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** check.c
*/

#include "my.h"

void 		check_killed(all_t *all)
{
	if (all->killed == 1) {
		all->game = 0;
		create_object(all->all_texture.defaite,
		(sfIntRect){0, 0, 488, 88}, (sfVector2f){(1920/2) - (488/2),
		(1080/2) - (88/2)}, 0, 0, BG, all);
	}
}

void 		check_win(all_t *all)
{
	if (all->win == 1 && all->killed != 1) {
		all->game = 0;
		create_object(all->all_texture.victoire,
		(sfIntRect){0, 0, 488, 88}, (sfVector2f){(1920/2) - (488/2),
		(1080/2) - (88/2)}, 0, 0, BG, all);
	}
}

int 		nothing_below(all_t *all)
{
	int something = 0;

	for (int i = 0; i < all->nb_object; i++) {
		if (all->object[2].position.x + 50 > all->object[i].position.x
		&& all->object[2].position.x < all->object[i].position.x + 50
		&& all->object[2].position.y > all->object[i].position.y - 50
		&& (all->object[i].type == OBSTACLES || all->object[i].type ==
		PIC || all->object[i].type == ENEMY))
			something = 1;
	}
	if (all->object[2].position.y  > 730)
		something = 1;
	return (something);
}