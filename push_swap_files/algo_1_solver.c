/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algo_1_solver.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/19 14:48:42 by iboeters      #+#    #+#                 */
/*   Updated: 2021/06/28 18:55:09 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_front(t_lst *lowest, t_lst *highest, t_lst *stack_a)
{
	int	prev;

	if (lowest == stack_a) // if so, sorted_back is enough
		return (1);
	lowest = lowest->prev;
	prev = *(int *)(lowest->content);
	lowest = lowest->prev;
	while (lowest != (stack_a->prev)->prev)
	{
		if (*(int *)(lowest->content) > prev && lowest != highest &&
		prev != *(int *)(highest->content))
			return (0);
		prev = *(int *)(lowest->content);
		lowest = lowest->prev;
	}
	return (1);
}

int	is_sorted_back(t_lst *lowest)
{
	int	prev;

	prev = *(int *)(lowest->content);
	lowest = lowest->next;
	while (lowest)
	{
		if (*(int *)(lowest->content) < prev)
			return (0);
		prev = *(int *)(lowest->content);
		lowest = lowest->next;
	}
	return (1);
}

void	swap_it(t_lst **stack_a, int i, int len)
{
	int	j;

	j = 0;
	if (i >= len / 2)
	{
		while (j < len - i)
		{
			reverse_rotate(stack_a, 'a', 1);
			j++;
		}
		// printf("swapping:|%d&%d|\n", *(int *)(*stack_a)->content, *(int *)((*stack_a)->next)->content);
		swap(stack_a, 'a', 1);
	}
	else
	{
		while (j < i)
	    {
	    	rotate(stack_a, 'a', 1);
	    	j++;
	    }
		// printf("swapping:|%d&%d|\n", *(int *)(*stack_a)->content, *(int *)((*stack_a)->next)->content);
		swap(stack_a, 'a', 1);
	}
}

int	check_swap(t_lst *stack_a, int *i, int low_num, int high_num)
{
	int current;
	int next;
	t_lst	begin;

	begin = *stack_a;
	while (stack_a)
	{
		// printf("low_num=%d|high_num=%d\n", low_num, high_num);
		current = *(int *)(stack_a)->content;
		if (stack_a->next == NULL)
		{
			stack_a = &begin;
			next = *(int *)(stack_a)->content;
		}
		else
			next = *(int *)((stack_a)->next)->content; // hier segfault ie
		// printf("%d,%d\n", current, next);
		if (current > next &&
		current != low_num && current != high_num &&
		next != low_num && next != high_num)
			return (1);
		stack_a = stack_a->next;
		(*i)++;
	}
	return (0);
}

void	uno(t_lst **stack_a, t_lst *lowest, t_lst *highest, int *i, int len)
{
	// printf("stack_a:\n");
	// lstiter(*stack_a, print_lst_num);
	if (is_sorted_front(lowest, highest, *stack_a) && is_sorted_back(lowest))
		return ;
	if (check_swap(*stack_a, i, *(int *)(lowest->content),
	*(int *)(highest->content)))
	{
		swap_it(stack_a, *i, len);
	}
	*i = 0;
	uno(stack_a, lowest, highest, i, len);
}

void	rotate_right(t_lst **stack_a, t_lst *lowest, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (lowest)
	{
		lowest = lowest->next;
		i++;
	}
	i = len - i;
	if (i >= len / 2)
	{
		while (j < len - i)
		{
			reverse_rotate(stack_a, 'a', 1);
			j++;
		}
	}
	else
	{
		while (j < i)
	    {
	    	rotate(stack_a, 'a', 1);
	    	j++;
	    }
	}
}

void	algo_1_solver(t_lst **stack_a, t_lst **stack_b, int len)
{
	t_lst *lowest;
	t_lst *highest;
	int	i;

	i = 0;
	len += 2;
	if (*stack_b && *(int *)((*stack_b)->content) > *(int *)(((*stack_b)->next)->content))
		swap(stack_b, 'b', 1);
	if (*stack_b)
	{
		push(stack_a, stack_b, 'a', 1);
		push(stack_a, stack_b, 'a', 1);
		rotate(stack_a, 'a', 1);
	}
	lowest = *stack_a;
	highest = (*stack_a)->prev;
	// printf("lowest=%d, highest=%d\n", *(int *)lowest->content, *(int *)highest->content);
	// printf("stack_a:\n");
	// lstiter(*stack_a, print_lst_num);
	uno(stack_a, lowest, highest, &i, len);
	rotate_right(stack_a, lowest, len);
	return ;
}

// begin list is lost by looping over list. fix this. swaps 9 couple of times though.
// discussion lars:
// swaps are too expensive -> algorithm wont work
// first sort the whole stack beforehand
// sort on groups of 3/5/10
// figure out best way to sort 3 & figure out the best way to sort 10
// push 10 lowest to b -> sort these
// push next 10 lowest to b -> sort these
// push next 10 lowest to b -> sort these

// different groups: <3 >3 >5 >50 >100 >500??
// for the 500 cases, use the 4 spots to put numbers:
// 1= upper stack_a (sa)
// 2= low stack_a (rra)
// 3= upper stack_b (pb)
// 4= low stack_b (pb & rrb)
// push 10 numbers per spot-> solve these -> push next 10 numbers
// kind of like bucket sort algorithm
