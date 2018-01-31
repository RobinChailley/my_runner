/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** display.c
*/

#include "my.h"

void 		display(all_t all)
{
	sfRenderWindow_clear(all.window.window, sfBlack);
	for (int i = 0; i < all.nb_object; i++) {
		if (all.object[i].display == 1)
			sfRenderWindow_drawSprite(all.window.window,
			all.object[i].sprite, NULL);
	}
	for (int i = 0; i < all.nb_object; i++) {
		if (all.object[i].type == PLAYER)
			sfRenderWindow_drawSprite(all.window.window,
			all.object[i].sprite, NULL);
	}
	if (all.pause == 1)
		sfRenderWindow_drawSprite(all.window.window,
		all.object[4].sprite, NULL);
}

void 		display_text(all_t all)
{
	for (int i = 0; i < all.nb_text; i++) {
		sfRenderWindow_drawText(all.window.window,
		all.text[0].text, NULL);
	}
}