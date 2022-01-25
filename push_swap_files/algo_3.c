/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algo_3.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 14:39:53 by iboeters      #+#    #+#                 */
/*   Updated: 2022/01/25 14:39:54 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_next(int i, t_lst *stack_b)
{
	int	j;
	int	current;

	j = 0;
	while (stack_b)
	{
		current = *(int *)(stack_b)->content;
		if (current == i)
			return (j);
		j++;
		stack_b = (stack_b)->next;
	}
	return (0);
}

void	algo_3(t_lst **stack_a, t_lst **stack_b, int len)
{
	int	num;
	int	i;

	i = 0;
	num = len - 1;
	if (sorted(*stack_a))
		return ;
	pre_sorting(stack_a, stack_b, len);
	while (num > -1)
	{
		i = get_next(num, *stack_b);
		if (i == 0)
		{
			pushes("pa", stack_a, stack_b, 1);
			num--;
		}
		else if (i > lstsize(*stack_b) / 2)
			rotates("rrb", stack_a, stack_b, 1);
		else
			rotates("rb", stack_a, stack_b, 1);
	}
	return ;
}
