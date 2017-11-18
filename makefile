# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thvocans <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/23 19:03:58 by thvocans          #+#    #+#              #
#    Updated: 2017/11/18 17:04:25 by thvocans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all fclean clean re libmlx.a libclean libfclean mlxclean libft.a relib

NAME = exe

FLAGS = -Wall -Wextra -Werror
#FLAGS = -Wall -Wextra -Werror -lmlx -L./sierra -framework OpenGL -framework Appkit

C_FOLDER = ./
H_FOLDER = ./
LIB_FOLD = ./libft
GLIB_FOLD = ./sierra
#GLIB_FOLD = ./el_capitan

LIB = $(LIB_FOLD)/libft.a

GLIB = $(GLIB_FOLD)/libmlx.a

SRC = main keyboard mouse mandelbrot julia

C_FILE = $(addsuffix .c,$(addprefix $(C_FOLDER),$(SRC)))

O_FILE = $(addsuffix .o,$(SRC))

all: $(NAME)

$(NAME): $(GLIB) $(LIB) $(O_FILE)
	@gcc $(FLAGS) $(LIB) $(GLIB) -framework OpenGL -framework Appkit -o $@ $(O_FILE)
	@echo "\033[32mexecutable OK\033[0m"

./%.o: ./%.c ./fractol.h
	@gcc -c $< $(FLAGS) -I$(LIB_FOLD) -o $@
	@echo "\033[32m$@\033[0m"

libft.a: $(LIB)

libmlx.a : $(GLIB)

$(LIB):
	@$(MAKE) -C libft

$(GLIB):
	@$(MAKE) -C $(GLIB_FOLD)

libclean:
	@$(MAKE) -C libft clean

mlxclean:
	@$(MAKE) -C $(GLIB_FOLD) clean

clean: libclean
	@/bin/rm -f $(O_FILE)
	@echo "\033[32mrm .o files\033[0m"

libfclean:
	@$(MAKE) -C libft fclean

fclean: clean libfclean
	@/bin/rm -f $(NAME)
	@echo "\033[32mrm $(NAME)\033[0m"

relib: libfclean libft.a

re: fclean all
