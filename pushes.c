/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushes.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/03 20:22:37 by iboeters      #+#    #+#                 */
/*   Updated: 2021/05/16 23:12:53 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_addr;

	tmp_addr = (*stack_b)->next;
	ft_lstadd_front(stack_a, *stack_b);
	*stack_b = tmp_addr;
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_addr;

	tmp_addr = (*stack_a)->next;
	ft_lstadd_front(stack_b, *stack_a);
	*stack_a = tmp_addr;
}

void	pushes(char *instruction, t_list **stack_a, t_list **stack_b)
{
	if (instruction[1] == 'a' && ft_lstsize(*stack_b) >= 1)
		pa(stack_a, stack_b);
	else if (instruction[1] == 'b' && ft_lstsize(*stack_a) >= 1)
		pb(stack_a, stack_b);
}
