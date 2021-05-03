/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/02 18:59:30 by iboeters      #+#    #+#                 */
/*   Updated: 2021/05/03 20:43:03 by iboeters      ########   odam.nl         */
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

int	save_input(int argc, char **argv, t_stack *stack, t_list **lst);
void rotates(char *instruction, t_stack *a, t_stack *b);
void swaps(char *instruction, t_stack *a, t_stack *b);
void pushes(char *instruction, t_stack *a, t_stack *b);
int	instructions(t_list **input, t_stack *a, t_stack *b);

#endif
