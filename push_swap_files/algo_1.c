/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algo_1.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/18 21:10:20 by iboeters      #+#    #+#                 */
/*   Updated: 2021/05/18 21:49:59 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	place_low_high(t_lst **stack_a, int low_index, int high_index, int len)
{
	return ;
}

int	lowest_highest(t_lst **stack_a)
{
	int	low;
	int	high;
	int	low_index;
	int	high_index;
	int	len;
	t_lst	*tmp;

	low = *(int *)(*stack_a)->content;
	high = *(int *)(*stack_a)->content;
	low_index = 0;
	high_index = 0;
	len = 0;
	tmp = *stack_a;
	while (*stack_a)
	{
		if (*(int *)(*stack_a)->content < low)
		{
			low_index = len;
			low = *(int *)(*stack_a)->content;
		}
		if (*(int *)(*stack_a)->content > high)
		{
			high_index = len;
			high = *(int *)(*stack_a)->content;
		}
		*stack_a = (*stack_a)->next;
		len++;
	}
	printf("[%i]%i|[%i]%i|len=%i\n", low_index, low, high_index, high, len);
	place_low_high(stack_a, low_index, high_index, len);
	*stack_a = tmp;
	return (0);
}

int	algo_1(t_lst **output, t_lst **stack_a, t_lst **stack_b)
{
	lowest_highest(stack_a);
	return (0);
}
