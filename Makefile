# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbelov <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/30 14:25:08 by kbelov            #+#    #+#              #
#    Updated: 2019/11/18 22:19:17 by kbelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = kbelov.filler

FLAG = -Wall -Wextra -Werror

SRC = ft_printf.c format.c parse.c output.c output_d.c output_oxx.c output_f.c

OBJ = *.o

LIBFT = ./libft/*.c

HEADER = ft_printf.h

all: $(NAME)

$(NAME):
	gcc -c $(FLAG) $(SRC) $(LIBFT)
	ar rcs $(NAME) $(OBJ)

lib:
	@make -C libft

clean:
	@/bin/rm -rf $(OBJ)
	@make -C libft/ clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@make -C libft/ fclean

re: fclean all

test: lib
	gcc $(FLAG) $(SRC) main.c libft/libft.a -o ft_printf_makefile

lldb: lib
	gcc -g $(FLAG) $(SRC) main.c libft/libft.a -o ft_printf_lldb

norme: 
	norminette ft_printf.c format.c parse.c output.c output_d.c \
		output_oxx.c output_f.c ft_printf.h Makefile
