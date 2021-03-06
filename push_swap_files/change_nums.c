/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   change_nums.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 14:39:59 by iboeters      #+#    #+#                 */
/*   Updated: 2022/01/26 14:52:05 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	change_stack(int *arr, t_lst *stack_a, const int len)
{
	unsigned int	i;
	unsigned int	length;

	length = (unsigned int)len;
	while (stack_a)
	{
		i = 0;
		while (i < length)
		{
			if (*(int *)(stack_a)->content == arr[i])
			{
				*(unsigned int *)stack_a->content = i;
				break ;
			}
			i++;
		}
		stack_a = (stack_a)->next;
	}
}

void	swap_num(int *arr, int j)
{
	int	tmp;

	tmp = arr[j];
	arr[j] = arr[j + 1];
	arr[j + 1] = tmp;
}

void	bubble_sort_arr(int *arr, int len)
{
	int	swapped;
	int	i;
	int	j;

	i = 0;
	j = 0;
	swapped = 1;
	while (swapped == 1 && len - i > 1)
	{
		swapped = 0;
		j = 0;
		while (j < len - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				swap_num(arr, j);
				swapped = 1;
			}
			j++;
		}
		i++;
	}
}

void	fill_arr(int *arr, t_lst *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		arr[i] = *(int *)stack_a->content;
		stack_a = stack_a->next;
		i++;
	}
}

int	change_nums(t_lst *stack_a)
{
	int	len;
	int	*arr;
	int	i;

	i = 0;
	len = lstsize(stack_a);
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (1);
	fill_arr(arr, stack_a);
	bubble_sort_arr(arr, len);
	change_stack(arr, stack_a, len);
	if (arr)
		free(arr);
	return (0);
}
