NAME = push_swap

NAMEB = checker

SRC =	./get_next_line/get_next_line.c\
		./get_next_line/get_next_line_utils.c\
		./push_swap_files/save_input.c\
		./push_swap_files/lst_funs_2.c\
		./push_swap_files/pushes.c\
		./push_swap_files/rotates.c\
		./push_swap_files/swaps.c\
		./push_swap_files/main.c\
		./push_swap_files/change_nums.c\
		./push_swap_files/algo_2.c\
		./push_swap_files/pre_sorting.c\
		./push_swap_files/algo_3.c\
		./push_swap_files/check_push.c\
		./push_swap_files/lst_funs.c

SRCB =	./get_next_line/get_next_line.c\
		./get_next_line/get_next_line_utils.c\
		./push_swap_files/swaps.c\
		./push_swap_files/pushes.c\
		./push_swap_files/rotates.c\
		./push_swap_files/lst_funs.c\
		./push_swap_files/lst_funs_2.c\
		./push_swap_files/save_input.c\
		./checker_files/instructions.c\
		./checker_files/checker.c\
		./checker_files/save_instructions.c

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

INC = -I ./libft/libft.h -I ./includes/get_next_line.h -I ./includes/checker.h

INCB = -I ./libft/libft.h -I ./includes/get_next_line.h -I ./includes/checker.h

FLAGS = -Wall -Werror -Wextra

ifdef DEBUG
FLAGS += -fsanitize=address -fno-omit-frame-pointer -g
endif

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@make bonus -C ./libft
	@cp ./libft/libft.a .
	gcc $(FLAGS) $(INC) ${OBJ} libft.a -o ${NAME}

bonus: $(NAME) $(NAMEB)

$(NAMEB): $(OBJB)
	gcc $(FLAGS) $(INCB) ${OBJB} libft.a -o ${NAMEB}

clean:
	@make clean -C ./libft
	rm -f $(OBJ)
	rm -f $(OBJB)

fclean:	clean
	rm -f libft/libft.a
	rm -f libft.a
	rm -f $(NAME)
	rm -f $(NAMEB)

re: fclean all
