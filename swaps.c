/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swaps.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/03 20:20:46 by iboeters      #+#    #+#                 */
/*   Updated: 2021/05/16 17:25:42 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_list **stack_a)
{
	t_list	*first;
	t_list	*third;

	first = *stack_a;
	*stack_a = (*stack_a)->next;
	third = (*stack_a)->next;
	(*stack_a)->next = first;
	((*stack_a)->next)->next = third;
}

void	sb(t_list **stack_b)
{
	t_list	*first;
	t_list	*third;

	first = *stack_b;
	*stack_b = (*stack_b)->next;
	third = (*stack_b)->next;
	(*stack_b)->next = first;
	((*stack_b)->next)->next = third;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) >= 2)
		sa(stack_a);
	if (ft_lstsize(*stack_b) >= 2)
		sb(stack_b);
}

void	swaps(char *instruction, t_list **stack_a, t_list **stack_b)
{
	if (instruction[1] == 'a' && ft_lstsize(*stack_a) >= 2)
		sa(stack_a);
	else if (instruction[1] == 'b' && ft_lstsize(*stack_b) >= 2)
		sb(stack_b);
	else if (instruction[1] == 's')
		ss(stack_a, stack_b);
}
