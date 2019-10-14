##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

SRC	=	src/my_ls.c			\
		src/my_ls_tri.c			\
		src/my_ls_show.c		\
		src/my_ls_options.c		\
		src/my_over_nine.c		\
		src/my_colors.c			\
		src/my_next_file.c		\
		src/macroes.c			\
		src/lasts.c			\
		src/functions.c			\
		lib/my_putchar.c		\
		lib/my_putstr.c			\
		lib/my_put_nbr.c		\
		lib/my_put_nbr_base.c		\
		lib/my_put_nbr_long.c		\
		lib/my_put_nbr_unsigned.c	\
		lib/my_revstr.c			\
		lib/my_strlen.c			\
		lib/no_printable.c		\
		lib/my_printf.c			\
		lib/my_strdup.c			\
		lib/my_putsr_error.c		\
		lib/my_strcmp.c


OBJS	= $(SRC:.c=.o)

NAME	= my_ls

CC	= gcc -o

CFLAGS	= -Werror -Wextra -Wall -lmy -g3

RM	= rm -f

$(NAME): $(OBJS)
	$(CC) $(NAME) $(OBJS) $(LDFLAGS)

all:	$(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) vgcore.*

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re
