/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** create.c
*/

#include "my.h"

void 		create_text(int size, char *str, all_t *all,
sfVector2f position, sfColor color)
{
	text_t txt;
	txt.font = sfFont_createFromFile("images/font.ttf");
	txt.text = sfText_create();
	txt.str = malloc(sizeof(char) * 10000);
	txt.position.x = position.x;
	txt.position.y = position.y;
	sfText_setFont(txt.text, txt.font);
	sfText_setString(txt.text, str);
	sfText_setCharacterSize(txt.text, size);
	sfText_setPosition(txt.text, txt.position);
	sfText_setColor(txt.text, color);
	all->text[all->nb_text] = txt;
	all->nb_text++;
}

void	 	create_object(sfTexture *textr, sfIntRect rect,
sfVector2f position, int offset, int size_max, type_t type, all_t *all)
{
	object_t obj;
	obj.sprite = sfSprite_create();
	obj.texture = textr;
	obj.rect = rect;
	obj.position = position;
	obj.x_graph = 0;
	obj.offset = offset;
	obj.size_max = size_max;
	obj.type = type;
	obj.nb_shot = 3;
	obj.display = 1;
	if (obj.type == PAUSE)
		obj.display = 0;
	obj.touched = 0;
	sfSprite_setTexture(obj.sprite, obj.texture, sfTrue);
	sfSprite_setTextureRect(obj.sprite, obj.rect);
	sfSprite_setPosition(obj.sprite, obj.position);
	all->object[all->nb_object] = obj;
	all->nb_object++;
}

all_t		create_all1(char *av)
{
	all_t all;
	all.all_texture = create_all_textures();
	all.window = create_window();
	all.clock.clocks = sfClock_create();
	all.nb_object = 0;
	all.is_jumping = 0;
	all.map = get_file(av);
	all.object = malloc(sizeof(object_t) *  10000);
	all.up_down = -1;
	all.killed = 0;
	all.win = 0;
	all.game = 0;
	all.vertical_move = 0;
	all.pause = 0;
	all.nb_text = 0;
	return (all);
}

all_t 		create_all(char *av)
{
	all_t all = create_all1(av);
	all.text = malloc(sizeof(text_t) * 10000);
	all.score = 0;
	all.main_sound = sfMusic_createFromFile("son/main.ogg");
	all.jump_sound = sfMusic_createFromFile("son/jump.ogg");
	all.coin_sound = sfMusic_createFromFile("son/coin.ogg");
	all.n_clock = 0;
	all.mm = 1;
	all.main_menu = 1;
	init_all(&all);
	return (all);
}

void		create_shot(all_t *all)
{
	for (int i = 0; i < all->nb_object; i++) {
		if (all->object[i].type == ENEMY &&
		all->object[i].position.x < 1920 &&
		all->object[i].nb_shot != 0) {
			create_object(all->all_texture.shot,
			(sfIntRect){0, 0, 20, 10},
			(sfVector2f){all->object[i].position.x+10,
			all->object[i].position.y+23}, 0, 0, SHOT, all);
			all->object[i].nb_shot -= 1;
		}
	}
}
