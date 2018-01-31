/*
** EPITECH PROJECT, 2017
** my_runner.c
** File description:
** main.c
*/

#include "my.h"

void 		init_all(all_t *all)
{
	create_object(all->all_texture.ciel, (sfIntRect){0, 0, 1920, 1080},
	(sfVector2f){0, 0}, 1, 1920, BG, all);
	create_object(all->all_texture.arbre, (sfIntRect){0, 0, 1920, 1080},
	(sfVector2f){0, 0}, 2, 1920, BG, all);
	create_object(all->all_texture.perso, (sfIntRect){0, 0, 42, 50},
	(sfVector2f){200, 600}, 42, 256, PLAYER, all);
	create_object(all->all_texture.sol, (sfIntRect){0, 0, 1920, 1080},
	(sfVector2f){0, 0}, 4, 1920, BG, all);
	create_object(all->all_texture.pause, (sfIntRect){0, 0,  960, 510},
	(sfVector2f){480, 255}, 0, 0, PAUSE, all);
	create_text(50, "0", all, (sfVector2f){862, 494}, (sfColor){84, 41, 10,
	255});

}

void 		event_management(all_t *all)
{
	while (sfRenderWindow_pollEvent(all->window.window,
	&all->window.event)) {
		if (all->window.event.type == sfEvtClosed)
			sfRenderWindow_close(all->window.window);
		if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue) {
			if (all->game == 1 && all->is_jumping == 0)
				sfMusic_play(all->jump_sound);
			all->is_jumping = 1;
		}
		if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
			all->game = 0;
			all->pause = 1;
			all->object[4].display = 1;
		}
		if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue) {
			all->game = 1;
			all->pause = 0;
			all->object[4].display = 0;
		}
	}
}

int 		main(int ac, char **av)
{
	all_t all;
	int ret = parsing (av, ac);

	if (ret != 0)
		return (ret);
	all = create_all(av[1]);
	if (my_strncmpr("error", all.map, 5) == 1) {
		destroy_all(&all);
		return (84);
	}
	sfMusic_play(all.main_sound);
	main_menu(&all);
	map_reader(&all, av[1]);
	while (sfRenderWindow_isOpen(all.window.window)) {
		game_engine(&all);
	}
	destroy_all(&all);
	return (0);
}