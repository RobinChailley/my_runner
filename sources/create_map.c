/*
** EPITECH PROJECT, 2018
** my_runner_2017
** File description:
** create_map.c
*/

#include "my.h"

void 		create_all_obstacles_map2(int **map2d, int i, int j, all_t *all)
{
	switch(map2d[j][i]) {
	case 'f':
		create_object(all->all_texture.pic2, (sfIntRect)
		{0, 0, 50, 50},	(sfVector2f){i*50, j*50+30}, 0, 0, PIC,
		all);
		break;
	case 'g':
		create_object(all->all_texture.pic3, (sfIntRect)
		{0, 0, 50, 50}, (sfVector2f){i*50, j*50+30}, 0, 0, PIC,
		all);
		break;
	}
}

void 		create_all_other_sprites(int **map2d, int i, int j, all_t *all)
{
	switch (map2d[j][i]) {
	case 'd':
		create_object(all->all_texture.lanceur, (sfIntRect)
		{0, 0, 50, 50}, (sfVector2f){i*50, j*50+30}, 0, 0, ENEMY, all);
		break;
	case 'e':
		create_object(all->all_texture.coin,
		(sfIntRect){0, 0, 50, 50}, (sfVector2f){i*50, j*50+30}, 50,
		500, BONUS, all);
		break;
	case 'z':
		create_object(all->all_texture.end, (sfIntRect)
		{0, 0, 50, 1080}, (sfVector2f){i*50, j*50+30}, 0, 0, END, all);
		break;
	}
}

void 		create_all_obstacles_map1(int **map2d, int i, int j, all_t *all)
{
	switch (map2d[j][i]) {
	case 'b':
		create_object(all->all_texture.caisse, (sfIntRect)
		{0, 0, 50, 50},	(sfVector2f){i*50, j*50+30}, 0, 0, OBSTACLES,
		all);
		break;
	case 'a':
		create_object(all->all_texture.pic1, (sfIntRect)
		{0, 0, 50, 50}, (sfVector2f){i*50, j*50+30}, 0, 0, PIC,
		all);
		break;
	}
}

void 		create_all_map(int **map2d, int i, int j, all_t *all)
{
	create_all_obstacles_map1(map2d, i, j, all);
	create_all_obstacles_map2(map2d, i, j, all);
	create_all_other_sprites(map2d, i ,j, all);
}