/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** collide.c
*/

#include "my.h"

void 		collide_with_end(all_t *all)
{
	for (int i = 0; i < all->nb_object; i++) {
		if (all->object[i].type == END &&
		all->object[i].position.x < all->object[2].position.x)
			all->win = 1;
	}
}

void 		collide_with_shot(all_t *all)
{
	for (int i = 0; i < all->nb_object; i++) {
		if ((all->object[2].position.x + 50 > all->object[i].position.x
		&& all->object[2].position.x < all->object[i].position.x + 20)
		&& all->object[i].type == SHOT) {
			if (all->object[2].position.y + 50 >
			all->object[i].position.y && all->object[2].position.y
			< all->object[i].position.y + 10)
				all->killed = 1;
		}
	}
}

void 		collide_with_pic_up(all_t *all)
{
	for (int i = 0; i < all->nb_object; i++) {
		if ((all->object[2].position.x + 50 > all->object[i].position.x
		&& all->object[2].position.x < all->object[i].position.x + 50)
		&& ( all->object[i].type == PIC)) {
			if (all->object[2].position.y + 50 >
			all->object[i].position.y && all->object[2].position.y
			< all->object[i].position.y + 50)
				all->killed = 1;
		}
	}
}

void 		do_bonus(all_t *all, int i)
{
			if (all->object[2].position.y + 50 >
			all->object[i].position.y &&
			all->object[2].position.y < all->object[i].position.y
			+ 30) {
				all->object[i].display = 0;
				if (all->object[i].touched == 0) {
					all->score++;
					sfMusic_play(all->coin_sound);
				}
				all->object[i].touched = 1;
			}
}

void 		collide_with_bonus(all_t *all)
{
	for (int i = 0; i < all->nb_object; i++) {
		if ((all->object[2].position.x + 50 > all->object[i].position.x
		&& all->object[2].position.x < all->object[i].position.x + 50)
		&& ( all->object[i].type == BONUS)) {
			do_bonus(all, i);
		}
	}
}
