/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/02 18:59:30 by iboeters      #+#    #+#                 */
/*   Updated: 2021/05/04 18:46:26 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

typedef struct			s_stack{
	int					*arr;
	int					size;
}						t_stack;

int	save_input(int argc, char **argv, t_list **stack_a, t_list **input);
void rotates(char *instruction, t_list *stack_a, t_list *stack_b);
void swaps(char *instruction, t_list *stack_a, t_list *stack_b);
void pushes(char *instruction, t_list *stack_a, t_list *stack_b);
int	instructions(t_list **input, t_list *stack_a, t_list *stack_b);
void	print_lst_num(void *num);

#endif
