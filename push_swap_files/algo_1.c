/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algo_1.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/18 21:10:20 by iboeters      #+#    #+#                 */
/*   Updated: 2021/07/04 22:03:26 by iris          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		low_closest(int low_index, int high_index, int len)
{
	int path_low;
	int	path_high;
	
	path_low = low_index;
	if (len - low_index < path_low)
		path_low = len - low_index;
	path_high = high_index;
	if (len - high_index < path_high)
		path_high = len - high_index;
	// printf("path_low=%d|path_high=%d\n", path_low, path_high);
	if (path_low <= path_high)
		return (1);
	return (0);
}

void	push_first(t_lst **stack_a, t_lst **stack_b, int first_index, int *second_index, int len)
{
	int i;

	i = 0;
	if (first_index >= len / 2)
		{
			while (i < len - first_index)
			{
				reverse_rotate(stack_a, 'a', 1);
				(*second_index) = (*second_index) + 1 % len;
				i++;
			}
			push(stack_b, stack_a, 'b', 1);
			(*second_index)--;
		}
		else if (first_index < len / 2)
		{
			while (i < first_index)
			{
				(*second_index)--;
				if ((*second_index) == -1)
					(*second_index) = len - 1;
				rotate(stack_a, 'a', 1);
				i++;
			}
			push(stack_b, stack_a, 'b', 1);
			(*second_index)--;
		}
		// printf("*second_index=%d\n", (*second_index));
}

void	push_second(t_lst **stack_a, t_lst **stack_b, int second_index, int len)
{
	int i;

	i = 0;
	if (second_index >= len / 2)
		{
			while (i < len - second_index)
			{
				reverse_rotate(stack_a, 'a', 1);
				i++;
			}
			push(stack_b, stack_a, 'b', 1);
		}
		else if (second_index < len / 2)
		{
			while (i < second_index)
			{
				rotate(stack_a, 'a', 1);
				i++;
			}
			push(stack_b, stack_a, 'b', 1);
		}
}

void	push_low_high(t_lst **stack_a, t_lst **stack_b, int low_index, int high_index, int len)
{
	// printf("%i|%i|%i\n", len, low_index, high_index);
	if (low_index == 0 && high_index == len - 1)
		return ;
	if (low_closest(low_index, high_index, len))
	{
		push_first(stack_a, stack_b, low_index, &high_index, len);
		len--;
		push_second(stack_a, stack_b, high_index, len);
	}
	else
	{
		push_first(stack_a, stack_b, high_index, &low_index, len);
		len--;
		push_second(stack_a, stack_b, low_index, len);
	}
	return ;
}

int	lowest_highest(t_lst **stack_a, t_lst **stack_b, int len)
{
	int	low_index;
	int	high_index;
	int	i;
	t_lst	*tmp;

	i = 0;
	tmp = *stack_a;
	while (*stack_a)
	{
		if (*(int *)(*stack_a)->content == 0)
			low_index = i;
		if (*(int *)(*stack_a)->content == len - 1)
			high_index = i;
		*stack_a = (*stack_a)->next;
		i++;
	}
	*stack_a = tmp;
	// printf("[%i][%i]len=[%i]\n", low_index, high_index, len);
	push_low_high(stack_a, stack_b, low_index, high_index, len);
	return (0);
}

int	algo_1(t_lst **stack_a, t_lst **stack_b)
{
	int	len;

	len = lstsize(*stack_a);
	lowest_highest(stack_a, stack_b, len);
	len = lstsize(*stack_a);
	algo_1_solver(stack_a, stack_b, len);
	return (0);
}
