# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: iboeters <iboeters@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/02 19:43:17 by iboeters      #+#    #+#                  #
#    Updated: 2021/05/04 18:03:17 by iboeters      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap

NAME2 = checker

SRC1 =	main.c

SRC2 =	./get_next_line/get_next_line.c\
		./get_next_line/get_next_line_utils.c\
		checker.c\
		save_input.c
		# instructions.c\
		# pushes.c\
		# swaps.c\
		# rotates.c

OBJ1 = $(SRC1:.c=.o)

OBJ2 = $(SRC2:.c=.o)

INC1 = -I ./libft/libft.h

INC2 = -I ./libft/libft.h -I ./get_next_line/get_next_line.h

FLAGS = -Wall -Wextra -Werror

ifdef DEBUG
FLAGS += -fsanitize=address -fno-omit-frame-pointer -g
endif

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ1)
	@make -C ./libft
	@make bonus -C ./libft
	@cp ./libft/libft.a .
	gcc $(FLAGS) $(INC1) ${OBJ1} libft.a -o ${NAME1}

$(NAME2): $(OBJ2)
	gcc $(FLAGS) $(INC2) ${OBJ2} libft.a -o ${NAME2}

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
