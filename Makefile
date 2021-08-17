NAME1 = push_swap

NAME2 = checker

SRC1 =	./get_next_line/get_next_line.c\
		./get_next_line/get_next_line_utils.c\
		./push_swap_files/save_input.c\
		./push_swap_files/lst_funs.c\
		./push_swap_files/pushes.c\
		./push_swap_files/rotates.c\
		./push_swap_files/swaps.c\
		./push_swap_files/main.c\
		./push_swap_files/algo_1.c\
		./push_swap_files/algo_1_solver.c\
		./push_swap_files/change_nums.c\
		./push_swap_files/uno.c

SRC2 =	./get_next_line/get_next_line.c\
		./get_next_line/get_next_line_utils.c\
		./push_swap_files/swaps.c\
		./push_swap_files/pushes.c\
		./push_swap_files/rotates.c\
		./push_swap_files/lst_funs.c\
		./push_swap_files/save_input.c\
		./checker_files/instructions.c\
		./checker_files/checker.c\
		./checker_files/save_instructions.c

OBJ1 = $(SRC1:.c=.o)

OBJ2 = $(SRC2:.c=.o)

INC1 = -I ./libft/libft.h -I ./get_next_line/get_next_line.h -I ./checker_files/checker.h 

INC2 = -I ./libft/libft.h -I ./get_next_line/get_next_line.h -I ./checker_files/checker.h

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
