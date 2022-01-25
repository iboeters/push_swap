/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_push.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 14:23:33 by iboeters      #+#    #+#                 */
/*   Updated: 2022/01/25 14:24:14 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_backwards(t_lst *stack_a, int len_tot, float size)
{
	int		current;
	int		i;

	current = 0;
	i = lstsize(stack_a) - 1;
	while (stack_a)
	{
		current = *(int *)(stack_a)->content;
		if (((current < len_tot / 2) && (current >= (len_tot / 2 - size)))
			|| ((current < (len_tot / 2 + size)) && (current >= len_tot / 2)))
			return (i);
		stack_a = stack_a->prev;
		i--;
	}
	return (0);
}

static void	get_i(t_lst *stack_a, int *i, int len_tot, float size)
{
	int	save_i;
	int	back_i;

	save_i = 0;
	save_i = *i;
	while (*i > 0)
	{
		stack_a = stack_a->prev;
		(*i)--;
	}
	*i = save_i;
	back_i = check_backwards(stack_a, len_tot, size);
	if (lstsize(stack_a) - back_i < *i)
		*i = back_i;
	return ;
}

static void	start_over(int *start_over, int *i)
{
	*start_over = 0;
	*i = 0;
}

static int	part_of_group(int current, int len_tot, float size)
{
	if (((current < len_tot / 2) && (current >= len_tot / 2 - size))
		|| ((current < len_tot / 2 + size) && (current >= len_tot / 2)))
		return (1);
	return (0);
}

void	check_push(t_lst *stack_a, int *i, int len_tot, float size)
{
	int		current;
	int		start_ov;
	t_lst	begin;

	begin = *stack_a;
	current = 0;
	start_ov = 0;
	while (stack_a)
	{
		current = *(int *)(stack_a)->content;
		if (stack_a->next == NULL)
		{
			start_ov = 1;
			stack_a = &begin;
		}
		if (part_of_group(current, len_tot, size))
			return (get_i(stack_a, i, len_tot, size));
		stack_a = stack_a->next;
		(*i)++;
		if (start_ov == 1)
			start_over(&start_ov, i);
	}
}
