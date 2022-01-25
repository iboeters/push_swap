/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 14:31:54 by iboeters      #+#    #+#                 */
/*   Updated: 2022/01/25 16:58:04 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../includes/get_next_line.h"
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
void	lstadd_back(t_lst **lst, t_lst *new);
void	lstadd_front(t_lst **lst, t_lst *new);
void	lstclear(t_lst **lst, void (*del)(void*));
void	lstiter(t_lst *lst, void (*f)(void *));
t_lst	*lstlast(t_lst *lst);
t_lst	*lstnew(void *content);
int		lstsize(t_lst *lst);
int		save_instructions(t_lst **input);

#endif
