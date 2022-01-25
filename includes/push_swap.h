/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 14:51:22 by iboeters      #+#    #+#                 */
/*   Updated: 2022/01/25 16:57:51 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../includes/get_next_line.h"
# include "../includes/checker.h"
# include <limits.h>
# include <stdlib.h>

int		save_input(int argc, char **argv, t_lst **stack_a);
void	rotates(char *instruction, t_lst **stack_a, t_lst **stack_b, int print);
void	swaps(char *instruction, t_lst **stack_a, t_lst **stack_b, int print);
void	pushes(char *instruction, t_lst **stack_a, t_lst **stack_b, int print);
void	reverse_rotate(t_lst **stack, char ab, int print);
void	rotate(t_lst **stack, char ab, int print);
void	swap(t_lst **stack, char ab, int print);
int		change_nums(t_lst *stack_a);
int		pre_sorting(t_lst **stack_a, t_lst **stack_b, int len);
void	algo_2(t_lst **stack_a, t_lst **stack_b);
void	push_num(t_lst **stack_1, t_lst **stack_2, char ab, int print);
int		sorted(t_lst *stack);
void	algo_3(t_lst **stack_a, t_lst **stack_b, int len);
void	check_push(t_lst *stack_a, int *i, int len_tot, float size);

#endif
