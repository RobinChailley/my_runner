/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** main_menu.c
*/

#include "my.h"

void 		display_menu(all_t *all, sfSprite *sprite_menu)
{
	switch (all->mm) {
	case 1:
		sfSprite_setTexture(sprite_menu, all->all_texture.mm1, sfTrue);
		sfRenderWindow_drawSprite(all->window.window, sprite_menu,
		NULL);
		break;
	case 2:
		sfSprite_setTexture(sprite_menu, all->all_texture.mm2, sfTrue);
		sfRenderWindow_drawSprite(all->window.window, sprite_menu,
		NULL);
		break;
	}
	sfRenderWindow_display(all->window.window);
}

void 		choice_main_menu(all_t *all)
{
	switch(all->mm) {
	case 1:
		all->main_menu = 0;
		all->game = 1;
		sfRenderWindow_clear(all->window.window, sfBlack);
		break;
	case 2:
		sfRenderWindow_close(all->window.window);
		all->main_menu = 0;
		break;
	}
}

void 		event_main_menu(all_t *all)
{
	while (sfRenderWindow_pollEvent(all->window.window,
	&all->window.event)) {
		if (all->window.event.type == sfEvtClosed) {
			sfRenderWindow_close(all->window.window);
			all->main_menu = 0;
			all->game = 0;
		}
		if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue &&
		all->mm < 2)
			all->mm++;
		if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue &&
		all-> mm > 1)
			all->mm--;
		if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue) {
			choice_main_menu(all);
		}
	}
}

void 		main_menu(all_t *all)
{
	sfSprite *sprite_menu = sfSprite_create();
	while (all->main_menu == 1) {
		event_main_menu(all);
		display_menu(all, sprite_menu);
	}
}