/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/02 18:59:30 by iboeters      #+#    #+#                 */
/*   Updated: 2021/06/24 14:08:30 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../checker_files/checker.h"
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_lst
{
	void			*content;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

int		save_input(int argc, char **argv, t_lst **stack_a);
void	rotates(char *instruction, t_lst **stack_a, t_lst **stack_b, int print);
void	swaps(char *instruction, t_lst **stack_a, t_lst **stack_b, int print);
void	pushes(char *instruction, t_lst **stack_a, t_lst **stack_b, int print);
int		instructions(t_lst *input, t_lst **stack_a, t_lst **stack_b);
void	print_lst_num(void *num);
void	lstadd_back(t_lst **lst, t_lst *new);
void	lstadd_front(t_lst **lst, t_lst *new);
void	lstclear(t_lst **lst, void (*del)(void*));
void	lstiter(t_lst *lst, void (*f)(void *));
t_lst	*lstlast(t_lst *lst);
t_lst	*lstnew(void *content);
int		lstsize(t_lst *lst);
int		save_instructions(t_lst **input);
void	print_lst_str(void *str);

#endif
