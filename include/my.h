/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <math.h>
#include <sys/stat.h>
#define SIZE_BLOCK 4096

typedef struct text_s
{
	sfFont *font;
	sfText *text;
	char *str;
	sfVector2f position;
}	text_t;

typedef struct window_s
{
	sfEvent event;
	sfRenderWindow *window;
	sfVideoMode mode;
}	window_t;

typedef struct clock_ss
{
	sfTime time;
	sfClock *clocks;
	float seconds;
}	clock_tt;

typedef enum type_s
{
	OBSTACLES, PLAYER, BG, ENEMY, END, PIC, SHOT, BONUS, PAUSE, MM
}	type_t;

typedef struct object_s
{
	type_t type;
	int nb_shot;
	sfSprite *sprite;
	sfTexture *texture;
	sfIntRect rect;
	int offset;
	int size_max;
	float x_graph;
	sfVector2f position;
	int display;
	int touched;
}	object_t;

typedef struct all_texture_s
{
	sfTexture *caisse;
	sfTexture *pic1;
	sfTexture *pic2;
	sfTexture *pic3;
	sfTexture *lanceur;
	sfTexture *coin;
	sfTexture *end;
	sfTexture *ciel;
	sfTexture *sol;
	sfTexture *arbre;
	sfTexture *perso;
	sfTexture *pause;
	sfTexture *victoire;
	sfTexture *defaite;
	sfTexture *shot;
	sfTexture *mm1;
	sfTexture *mm2;
}	all_texture_t;

typedef struct all_s
{
	object_t *object;
	text_t *text;
	all_texture_t all_texture;
	clock_tt clock;
	sfMusic *main_sound;
	sfMusic *jump_sound;
	sfMusic *coin_sound;
	window_t window;
	int is_jumping;
	int nb_object;
	int nb_text;
	char *map;
	int up_down;
	float vertical_move;
	int killed;
	int win;
	int game;
	int score;
	int pause;
	int n_clock;
	int mm;
	int main_menu;
}	all_t;


void 		my_putchar(char c);
void 		my_putstr(char *str);
int 		my_strlen(char *str);
char 		*my_strcat(char *s1, char *s2);
char 		*get_file(char *path);
void		reverse_str(char *str);
void 		my_getcharstar(int nb, char *str);
int 		my_strncmpr(char *s1, char *s2, int n);


window_t	create_window(void);
void	 	create_object(sfTexture *txtr, sfIntRect rect, sfVector2f position,
		int offset, int size_max, type_t type, all_t *all);
all_t		create_all(char *av);
void 		create_shot(all_t *all);
all_texture_t	create_all_textures();
void 		create_text(int size, char *str, all_t *all,
sfVector2f position, sfColor color);
void 		recreate_all(char *av, all_t *all);

void 		init_all(all_t *all);
void 		event_management(all_t *all);

void 		collide_with_end(all_t *all);
void 		collide_with_shot(all_t *all);
void 		collide_with_pic_up(all_t *all);
void 		collide_with_pic_left(all_t *all);
void 		collide_with_bonus(all_t *all);

void 		check_killed(all_t *all);
void 		check_win(all_t *all);

int 		**char_star_to_int_2d(char *map);
int 		len_line(char *map);
void 		create_all_map(int **map2d, int i, int j, all_t *all);
void 		map_reader(all_t *all, char *av);

void 		jump(all_t *all);
void 		jump_gestion(all_t *all);
void 		gravity(all_t *all);
int 		nothing_below(all_t *all);
int 		nothing_up(all_t *all);

void 		set_position(all_t *all);
void 		game_engine(all_t *all);
void 		first_clock_game_engine(all_t *all);
void 		move_rect(all_t *all, type_t type);
void 		move_rect_core(all_t *all, int i);
void 		display(all_t all);
void 		display_text(all_t all);

void 		do_bonus(all_t *all, int i);

int 		parsing(char **av, int ac);

void 		map_reader(all_t *all, char *av);

void 		destroy_all_textures(all_t *all);
void 		destroy_all(all_t *all);

void 		main_menu(all_t *all);
void 		settings_menu(all_t *all);
void 		event_settings_menu(all_t *all, int *choice);

#endif /* MY_H_ */