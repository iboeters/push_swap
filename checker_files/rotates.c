/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotates.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/03 20:22:46 by iboeters      #+#    #+#                 */
/*   Updated: 2021/05/16 22:52:39 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate(t_list **stack)
{
	t_list	*tmp_addr;

	tmp_addr = *stack;
	*stack = (*stack)->next;
	tmp_addr->next = NULL;
	ft_lstadd_back(stack, tmp_addr);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) >= 2)
		rotate(stack_a);
	if (ft_lstsize(*stack_b) >= 2)
		rotate(stack_b);
}

void	reverse_rotate(t_list **stack)
{
	int		len;
	int		i;
	t_list	*first;
	t_list	*last;

	i = 0;
	first = *stack;
	last = ft_lstlast(*stack);
	len = ft_lstsize(*stack);
	while (i < len - 2 && *stack)
	{
		*stack = (*stack)->next;
		i++;
	}
	(*stack)->next = NULL;
	*stack = last;
	(*stack)->next = first;
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) >= 2)
		reverse_rotate(stack_a);
	if (ft_lstsize(*stack_b) >= 2)
		reverse_rotate(stack_b);
}

void	rotates(char *instruction, t_list **stack_a, t_list **stack_b)
{
	if (instruction[1] == 'a' && ft_lstsize(*stack_a) >= 2)
		rotate(stack_a);
	else if (instruction[1] == 'b' && ft_lstsize(*stack_b) >= 2)
		rotate(stack_b);
	else if (instruction[1] == 'r' && instruction[1] == '\0')
		rr(stack_a, stack_b);
	else if (instruction[2] == 'a' && ft_lstsize(*stack_a) >= 2)
		reverse_rotate(stack_a);
	else if (instruction[2] == 'b' && ft_lstsize(*stack_b) >= 2)
		reverse_rotate(stack_b);
	else
		rrr(stack_a, stack_b);
}
