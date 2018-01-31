/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** destroy.c
*/

#include "my.h"

void 		destroy_all_textures1(all_t *all)
{
	sfTexture_destroy(all->all_texture.caisse);
	sfTexture_destroy(all->all_texture.pic1);
	sfTexture_destroy(all->all_texture.pic2);
	sfTexture_destroy(all->all_texture.pic3);
	sfTexture_destroy(all->all_texture.lanceur);
	sfTexture_destroy(all->all_texture.coin);
	sfTexture_destroy(all->all_texture.end);
	sfTexture_destroy(all->all_texture.ciel);
}

void 		destroy_all_textures2(all_t *all)
{
	sfTexture_destroy(all->all_texture.sol);
	sfTexture_destroy(all->all_texture.arbre);
	sfTexture_destroy(all->all_texture.perso);
	sfTexture_destroy(all->all_texture.pause);
	sfTexture_destroy(all->all_texture.victoire);
	sfTexture_destroy(all->all_texture.defaite);
	sfTexture_destroy(all->all_texture.shot);
}

void 		destroy_all(all_t *all)
{
	for (int i = 0; i < all->nb_object; i++) {
		sfSprite_destroy(all->object[i].sprite);
	}
	destroy_all_textures1(all);
	destroy_all_textures2(all);
	sfMusic_destroy(all->main_sound);
	sfMusic_destroy(all->jump_sound);
	sfMusic_destroy(all->coin_sound);
}