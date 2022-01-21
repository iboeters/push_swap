#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../checker_files/checker.h"
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

# define ROT		1
# define REV_ROT	2
# define SWAP		3
# define PUSH		4

int		save_input(int argc, char **argv, t_lst **stack_a);
void	rotates(char *instruction, t_lst **stack_a, t_lst **stack_b, int print);
void	swaps(char *instruction, t_lst **stack_a, t_lst **stack_b, int print);
void	pushes(char *instruction, t_lst **stack_a, t_lst **stack_b, int print);
void	reverse_rotate(t_lst **stack, char ab, int print);
void	rrr(t_lst **stack_a, t_lst **stack_b, int len_a, int len_b, int print);
void	rr(t_lst **stack_a, t_lst **stack_b, int len_a, int len_b, int print);
void	rotate(t_lst **stack, char ab, int print);
void	push(t_lst **stack_1, t_lst **stack_2, char ab, int print);
void	ss(t_lst **stack_a, t_lst **stack_b, int print);
void	swap(t_lst **stack, char ab, int print);
int		change_nums(t_lst *stack_a);
int		algo_1(t_lst **stack_a, t_lst **stack_b);
void	algo_1_solver(t_lst **stack_a, t_lst **stack_b, int len);
int		is_sorted_front(t_lst *lowest, t_lst *highest, t_lst *stack_a, char ab);
int		is_sorted_back(t_lst *lowest, char ab);
void	uno(t_lst **stack_a, t_lst **stack_b, t_lst *low_a, t_lst *high_a, t_lst *low_b, t_lst *high_b, int *i, int *j);
int		pre_sorting(t_lst **stack_a, t_lst **stack_b, int len);
int		algo_2(t_lst **stack_a, t_lst **stack_b);
void	push_num(t_lst **stack_1, t_lst **stack_2, char ab, int print);
int		sorted(t_lst *stack);

#endif
