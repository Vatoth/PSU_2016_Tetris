##
## Makefile for Makefile in /home/noahl/piscine/delivery/CPool_Day10/lib/my
##
## Made by Lothaire Noah
## Login   <noahl@epitech.net>
##
## Started on  Mon Oct 17 19:10:30 2016 Lothaire Noah
## Last update Wed Mar 22 10:56:44 2017 loto
## Started on  Tue Jan 31 14:48:48 2017 Quentin Sonnefraud
## Last update Fri Feb 24 16:42:23 2017 Vatoth
##

CC    	=    gcc

RM    	=    rm -rf

CFLAGS	+= -Wall -Wextra -lncurses -Werror

CPPFLAGS += -I./include

LDFLAGS =    $(CFLAGS)

SRCS    =  main.c	\
	   src/tools.c \
	   src_commande/list_parser.c \
	   src_commande/check_cmd.c \
	   src_commande/parsing_command.c \
	   src/linked_list.c \
	   src/check_directory.c \
	   src/check_all.c \
	   src/read_tetrimino.c \
	   src/my_str_to_wordtab.c \
	   src/tools2.c \
	   src/tetris.c \
	   src_commande/my_strcmp.c \
	   src_commande/check_av.c  \
	   src/check_tetrimino.c \
	   src_commande/comande.c \
	   src_commande/interpret_commande.c \
	   src_commande/print_commande_debug_mode.c \
	   src_commande/interpret_commande2.c	    \
	   ncurses/init_ncurses.c \
	   ncurses/ncurses_map.c  \
	   ncurses/game.c \
	   ncurses/turn_pieces.c \
	   ncurses/fall.c \
	   ncurses/next_piece.c


OBJS    =    $(SRCS:.c=.o)

LIBS	=    $(OBJS)

NAME    =    tetris

all:    $(NAME)

$(NAME):    $(OBJS)
	make -C my_printf/
	gcc -o $(NAME) $(OBJ) $(LIBS) $(LDFLAGS) -L my_printf/ -lmy

clean:
	make clean -C my_printf/
	$(RM) $(OBJS)

fclean:    clean
	make fclean -C my_printf/
	$(RM) $(NAME)

re:    fclean all

.PHONY: all clean fclean re
