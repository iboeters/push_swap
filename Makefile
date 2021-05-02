# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: iboeters <iboeters@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/02 19:43:17 by iboeters      #+#    #+#                  #
#    Updated: 2021/05/02 19:43:20 by iboeters      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap

NAME2 = checker

SRC1 =	main.c

SRC2 =	checker.c\
		check_input.c

OBJ1 = $(SRC1:.c=.o)

OBJ2 = $(SRC2:.c=.o)

INC1 = ./libft/libft.h

INC2 = ./libft/libft.h

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ1)
	@make -C ./libft
	@cp ./libft/libft.a .
	gcc -Wall -Wextra -Werror -o ${NAME1} $(INC1) ${OBJ1} libft.a

$(NAME2): $(OBJ2)
	gcc -Wall -Wextra -Werror -o ${NAME2} $(INC2) ${OBJ2} libft.a

clean:
	@make clean -C ./libft
	rm -f $(OBJ1)
	rm -f $(OBJ2)

fclean:	clean
	rm -f libft/libft.a
	rm -f libft.a
	rm -f $(NAME1)
	rm -f $(NAME2)

bonus: all

re: fclean all
