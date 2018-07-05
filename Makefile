##
## Makefile for Makefile in /home/sachs_a/delivery/c_graphical_programming/
##
## Made by Alexandre Sachs
## Login   <sachs_a@epitech.net>
##
## Started on  Fri Mar 31 20:18:01 2017 Alexandre Sachs
## Last update Sat Dec 30 18:38:42 2017 Sachs Alexandre
##

CC		= gcc

RM		= rm -rf

ARRC		= ar crs

MK		= make

SRC_BIN		= src/scroller.c				\
		  src/sequences/pokemon/pokemon.c		\
		  src/sequences/pokemon/sprite_list.c		\
		  src/sequences/pokemon/player.c		\
		  src/sequences/pokemon/constructors_human.c	\
		  src/sequences/pokemon/destruct_player.c	\
		  src/sequences/pokemon/constructors_pokemon.c	\
		  src/sequences/pokemon/constructors_pokemon2.c	\
		  src/sequences/shooting_stars.c		\
		  src/sequences/text.c				\
		  src/sequences/free_point.c			\
		  src/sequences/slider.c			\
		  src/sequences/thick.c				\
		  src/draw_square.c				\
		  src/clear_buffer.c				\
		  src/list.c					\
		  src/my_event.c				\
		  $(addprefix src/mask/, $(MASK_SRC))		\
		  $(addprefix src/sound/, $(SOUND_SRC))

MASK_SRC	= mask.c					\
		  constructor.c					\
		  revert_color.c

SOUND_SRC	= sound_init.c

SRC_LIB		= src/main.c					\
		  src/my_event.c				\
		  src/my_put_pixel.c

OBJ_BIN		= $(SRC_BIN:.c=.o)

OBJ_LIB		= $(SRC_LIB:.c=.o)

CFLAGS		+= -I ./include/
CFLAGS		+= -W -Wall -Wextra -Werror

LDFLAGS		+= -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm -L./lib/my -lmy

NAME_BIN	= ./scroller

NAME_LIB	= ./lib/my/libmy.a

$(NAME_BIN):	$(OBJ_LIB) $(OBJ_BIN)
		$(ARRC) $(NAME_LIB) $(OBJ_LIB)
		$(CC) -o $(NAME_BIN) $(OBJ_BIN) $(LDFLAGS)

all:		$(NAME_BIN)

clean:
		$(RM) $(OBJ_BIN)
		$(RM) $(OBJ_LIB)

fclean:		clean
		$(RM) $(NAME_BIN)
		$(RM) $(NAME_LIB)

re:		fclean all

.PHONY:		all clean fclean re
