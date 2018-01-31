/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** jump.c
*/

#include "my.h"

void 		jump(all_t *all)
{
	if (all->up_down == -1) {
		if (all->object[2].x_graph < 1.8)
			all->object[2].x_graph += 0.05;
		if (all->object[2].x_graph > 1.8) {
			all->up_down = 1;
			all->object[2].x_graph = 1.8;
		}
	} else if (all->up_down == 1) {
		if (nothing_below(all) == 0) {
			if (all->object[2].x_graph > 0)
				all->object[2].x_graph -= 0.05;
			else
				all->vertical_move = 10;
		} else {
			all->up_down = -1;
			all->is_jumping = 0;
			all->object[2].x_graph = 0;
			all->vertical_move = 0;
		}
	}
}

void 		jump_gestion(all_t *all)
{
	if (all->is_jumping == 1) {
		jump(all);
		all->object[2].position.y += all->vertical_move;
		all->vertical_move = (-3 * (pow(all->object[2].x_graph, 2))
		+ 10) * (all->up_down);
	}
}

void 		gravity(all_t *all)
{
	if (nothing_below(all) == 0 && all->is_jumping == 0) {
		all->object[2].position.y += 6;
	}
}

void 		set_position(all_t *all)
{
	for (int i = 0; i < all->nb_object; i++) {
		if (all->object[i].type == OBSTACLES || all->object[i].type
		== ENEMY || all->object[i].type == END || all->object[i].type
		== PIC || all->object[i].type == BONUS)
			all->object[i].position.x -= 4;
		if (all->object[i].type == SHOT)
			all->object[i].position.x -= 8;
		sfSprite_setPosition(all->object[i].sprite,
		all->object[i].position);
	}
}