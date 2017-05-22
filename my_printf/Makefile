##
## Makefile for Makefile in /home/Vatoth/PSU_2016_navy
##
## Made by Quentin Sonnefraud
## Login   <Vatoth@epitech.net>
##
## Started on  Tue Jan 31 14:48:48 2017 Quentin Sonnefraud
## Last update Sun Mar 19 16:37:50 2017 loto
##

SRC     = my_putchar.c \
          my_strlen.c \
          my_printable.c \
          my_putstr.c \
          my_put_nbr.c \
          my_put_long.c \
          my_printf.c \
          my_base.c \
          my_put_pointers.c \
          my_put_unsigned.c \
          my_revstr.c

CFLAGS	+= -I.././include -Wall -Wextra

OBJ	= $(SRC:.c=.o)

NAME	= libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
