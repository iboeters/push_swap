/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swaps.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/03 20:20:46 by iboeters      #+#    #+#                 */
/*   Updated: 2021/05/04 17:29:11 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_list *stack_a)
{
	int tmp;

	tmp = a->arr[0];
	a->arr[0] = a->arr[1];
	a->arr[1] = tmp;
}

void	sb(t_list *stack_b)
{
	int tmp;

	tmp = b->arr[0];
	b->arr[0] = b->arr[1];
	b->arr[1] = tmp;
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	if (a->size >= 2)
		sa(a);
	if (b->size >= 2)
		sb(b);
}

void	swaps(char *instruction, t_list *stack_a, t_list *stack_b)
{
	if (instruction[1] == 'a' && a->size >= 2)
		sa(a);
	else if (instruction[1] == 'b' && b->size >= 2)
		sb(b);
	else
		ss(a, b);
}
