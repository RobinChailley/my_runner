/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** game_engine.c
*/

#include "my.h"

void 		game_engine_core(all_t *all)
{
	all->clock.time = sfClock_getElapsedTime(all->clock.clocks);
	all->clock.seconds = all->clock.time.microseconds / 1000000.0;
	jump_gestion(all);
	if (all->clock.seconds > 0.005)
		all->n_clock++;
	if (all->n_clock % 1 == 0)
		first_clock_game_engine(all);
	if (all->n_clock % 8 == 0)
		move_rect(all, PLAYER);
	if (all->n_clock % 15 == 0)
		move_rect(all, BONUS);
	if (all->n_clock % 80 == 0) {
		create_shot(all);
		all->n_clock = 0;
	}
}

void 		game_engine(all_t *all)
{
	event_management(all);
	my_getcharstar(all->score, all->text[0].str);
	sfText_setString(all->text[0].text, all->text[0].str);
	if (all->game == 1) {
		game_engine_core(all);
		all->text[0].position.x = 0;
		all->text[0].position.y = 0;
		sfText_setPosition(all->text[0].text, all->text[0].position);
	} else if (all->pause == 1) {
		all->text[0].position.x = 862;
		all->text[0].position.y = 494;
		sfText_setPosition(all->text[0].text, all->text[0].position);
	}
	display(*all);
	display_text(*all);
	sfRenderWindow_display(all->window.window);

}

void 		first_clock_game_engine(all_t *all)
{
	collide_with_pic_up(all);
	collide_with_end(all);
	collide_with_shot(all);
	collide_with_bonus(all);
	move_rect(all, BG);
	gravity(all);
	set_position(all);
	check_killed(all);
	check_win(all);
}

void 		move_rect_core(all_t *all, int i)
{
	if (all->object[i].rect.left < all->object[i].size_max)
		all->object[i].rect.left += all->object[i].offset;
	else if (all->object[i].rect.left >= all->object[i].size_max)
		all->object[i].rect.left = 0;
	sfSprite_setTextureRect(all->object[i].sprite, all->object[i].rect);
}

void 		move_rect(all_t *all, type_t type)
{
	for (int i = 0; i < all->nb_object; i++) {
		if (all->object[i].type == type) {
			move_rect_core(all, i);
		}
	}
}