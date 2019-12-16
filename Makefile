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

NAME = resources/players/kbelov.filler

FLAG = -Wall -Wextra -Werror

SRC = filler.c heat.c output.c get_next_line.c

OBJ = *.o

LIBFT = ./libft/*.c

HEADER = filler.h

all: $(NAME)

$(NAME):
	gcc $(FLAG) $(SRC) $(LIBFT) -o $(NAME)

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
	gcc $(FLAG) $(SRC) libft/libft.a -o filler_test

lldb: lib
	gcc -g $(FLAG) $(SRC) libft/libft.a -o filler_lldb

norme: 
	norminette filler.c output.c get_next_line.c /libft/* filler.h Makefile

play:
	./resources/filler_vm -f resources/maps/map00 \
	-p1 resources/players/kbelov.filler -p2 resources/players/superjeannot.filler

pbots:
	./resources/filler_vm -f resources/maps/map00 \
	-p1 resources/players/hcao.filler -p2 resources/players/abanlin.filler

cleanrepo:
	@/bin/rm -rf filler_lldb filler_lldb.dSYM filler_s filler_s.dSYM \
	a.out a.out.dSYM

fs:
	gcc -fsanitize=address -O1 -fno-omit-frame-pointer -g $(FLAG) $(SRC) \
	libft/libft.a -o filler_s

visu:
	./resources/filler_vm -f resources/maps/map00 \
	-p1 resources/players/kbelov.filler -p2 resources/players/superjeannot.filler \
	./visu

echo:
	echo "$$$ exec p1 : [players/kbelov.filler]
	Plateau 15 17:
		01234567890123456
	000 .................
	001 .................
	002 .................
	003 .................
	004 .................
	005 .................
	006 .................
	007 ..OOOO...........
	008 .OO..............
	009 .............x...
	010 ............xx...
	011 ............XXX..
	012 ..............X..
	013 .................
	014 .................
	Piece 5 1:
	*
	*
	.
	.
	." | ~/42_projects/filler/resources/players/kbelov.filler
