/*
** EPITECH PROJECT, 2018
** my_runner_2017
** File description:
** create2.c
*/

#include "my.h"

all_texture_t	create_all_textures1(void)
{
	all_texture_t all_texture;
	all_texture.caisse = sfTexture_createFromFile("images/caisse.png",
	NULL);
	all_texture.pic1 = sfTexture_createFromFile("images/pic1.png",
	NULL);
	all_texture.pic2 = sfTexture_createFromFile("images/pic2.png",
	NULL);
	all_texture.pic3 = sfTexture_createFromFile("images/pic3.png",
	NULL);
	all_texture.lanceur = sfTexture_createFromFile("images/lanceur.png",
	NULL);
	all_texture.end = sfTexture_createFromFile("images/end.png",
	NULL);
	all_texture.ciel = sfTexture_createFromFile("images/ciel.png",
	NULL);
	all_texture.sol = sfTexture_createFromFile("images/sol.png",
	NULL);
	all_texture.arbre = sfTexture_createFromFile("images/arbre.png",
	NULL);
	return (all_texture);
}

all_texture_t	create_all_textures(void)
{
	all_texture_t all_texture = create_all_textures1();
	all_texture.pause = sfTexture_createFromFile("images/pause.png",
	NULL);
	all_texture.perso = sfTexture_createFromFile(
	"images/perso_spritesheet.png", NULL);
	all_texture.coin = sfTexture_createFromFile(
	"images/coin_spritesheet.png", NULL);
	all_texture.victoire = sfTexture_createFromFile(
	"images/victoire.png", NULL);
	all_texture.defaite = sfTexture_createFromFile("images/defaite.png",
	NULL);
	all_texture.shot = sfTexture_createFromFile("images/nuage.png",
	NULL);
	all_texture.mm1 = sfTexture_createFromFile(
	"images/menu_princip/mp1.png", NULL);
	all_texture.mm2 = sfTexture_createFromFile(
	"images/menu_princip/mp2.png", NULL);
	return (all_texture);
}

window_t	create_window(void)
{
	window_t window;
	sfVideoMode mode = {1920, 1080, 32};
	window.window = sfRenderWindow_create(mode, "My_Runner",
	sfResize | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(window.window, 120);
	return (window);
}