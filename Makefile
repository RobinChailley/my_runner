##
## EPITECH PROJECT, 2017
## Makefile
## File descritpion:
## Makefile
##

CC	=	gcc -g

CFLAGS	=       -Wextra -W -Wall -Wparentheses -Wsign-compare -Wpointer-sign -Wuninitialized -Wunused-but-set-variable -g3 -I ./include

LDFLAGS =	-lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio
#LDFLAGS =	-lc_graph_prog

RM 	= 	rm -f

SRC	=	main.c	\
		sources/lib.c	\
		sources/create.c	\
		sources/check.c	\
		sources/collide.c	\
		sources/game_engine.c 	\
		sources/map_treatment.c	\
		sources/jump.c 	\
		sources/parsing.c	\
		sources/destroy.c 	\
		sources/main_menu.c 	\
		sources/create2.c	\
		sources/display.c 	\
		sources/gestion_str.c 	\
		sources/create_map.c 	\

OBJS	=	$(SRC:.c=.o)

NAME	= 	my_runner

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS) -lm

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
