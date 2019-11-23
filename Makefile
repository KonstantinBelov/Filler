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

SRC = fillit.c get_next_line.c

OBJ = *.o

LIBFT = ./libft/*.c

HEADER = fillit.h

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
	norminette filler.c get_next_line.c /libft/* filler.h Makefile

play:
	/resources/filler_vm ./filler_vm -f /resources/maps/map02 \
	-p1 kbelov.fillit -p2 abanlin.filler
