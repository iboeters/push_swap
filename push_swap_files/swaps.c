/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swaps.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/03 20:20:46 by iboeters      #+#    #+#                 */
/*   Updated: 2021/05/18 21:01:08 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_lst **stack)
{
	t_lst	*prev_1;
	t_lst	*prev_2;
	t_lst	*next_1;
	t_lst	*next_2;

	prev_1 = (*stack)->prev;
	prev_2 = *stack;
	next_1 = (*stack)->next;
	next_2 = (*stack)->next->next;
	*stack = (*stack)->next;
	(*stack)->next = prev_2;
	(*stack)->next->next = next_2;
	if (next_2 != NULL)
	{
		(*stack)->prev = prev_1;
		(*stack)->next->prev = *stack;
		next_2->prev = prev_2;
	}
}

void	ss(t_lst **stack_a, t_lst **stack_b)
{
	if (lstsize(*stack_a) >= 2)
		swap(stack_a);
	if (lstsize(*stack_b) >= 2)
		swap(stack_b);
}

void	swaps(char *instruction, t_lst **stack_a, t_lst **stack_b)
{
	if (instruction[1] == 'a' && lstsize(*stack_a) >= 2)
		swap(stack_a);
	else if (instruction[1] == 'b' && lstsize(*stack_b) >= 2)
		swap(stack_b);
	else if (instruction[1] == 's')
		ss(stack_a, stack_b);
}
