/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotates.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/03 20:22:46 by iboeters      #+#    #+#                 */
/*   Updated: 2021/05/17 15:08:28 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate(t_lst **stack)
{
	t_lst	*first;

	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	(first->prev)->next = first;
}

void	rr(t_lst **stack_a, t_lst **stack_b, int len_a, int len_b)
{
	if (len_a >= 2)
		rotate(stack_a);
	if (len_b >= 2)
		rotate(stack_b);
}

void	reverse_rotate(t_lst **stack)
{
	t_lst	*first;
	t_lst	*last;

	last = (*stack)->prev;
	(last->prev)->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rrr(t_lst **stack_a, t_lst **stack_b, int len_a, int len_b)
{
	if (len_a >= 2)
		reverse_rotate(stack_a);
	if (len_b >= 2)
		reverse_rotate(stack_b);
}

void	rotates(char *instruction, t_lst **stack_a, t_lst **stack_b)
{
	int	len_a;
	int	len_b;

	len_a = lstsize(*stack_a);
	len_b = lstsize(*stack_b);
	if (instruction[1] == 'a' && len_a >= 2)
		rotate(stack_a);
	else if (instruction[1] == 'b' && len_b >= 2)
		rotate(stack_b);
	else if (instruction[1] == 'r' && instruction[1] == '\0')
		rr(stack_a, stack_b, len_a, len_b);
	else if (instruction[2] == 'a' && len_a >= 2)
		reverse_rotate(stack_a);
	else if (instruction[2] == 'b' && len_b >= 2)
		reverse_rotate(stack_b);
	else
		rrr(stack_a, stack_b, len_a, len_b);
}
