/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pre_sorting.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 11:08:54 by iboeters      #+#    #+#                 */
/*   Updated: 2022/01/27 16:51:39 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	next_action(t_lst **stack_a, t_lst **stack_b, int i)
{
	int	len;
	int	len_tot;

	len = lstsize(*stack_a);
	if (i > len / 2)
		rotates("rra", stack_a, stack_b, 1);
	else
		rotates("ra", stack_a, stack_b, 1);
}

static void	sort_a_bit(t_lst **stack_a, t_lst **stack_b, int len, int n)
{
	int		i;
	int		group;
	float	size;
	int		current;

	group = 0;
	while (lstsize(*stack_a))
	{
		i = 0;
		size = (float)(1 + group)*(float)((float)len / (n * 2));
		current = *(int *)(*stack_a)->content;
		check_push(*stack_a, &i, len, size);
		if (i == 0)
		{
			pushes("pb", stack_a, stack_b, 1);
			if ((current < len / 2) && (current >= (len / 2 - size)))
				rotates("rb", stack_a, stack_b, 1);
		}
		else
			next_action(stack_a, stack_b, i);
		if (lstsize(*stack_a)
			<= (float)len - (float)(group + 1)*(float)len / n + 1)
			group++;
	}
}

int	pre_sorting(t_lst **stack_a, t_lst **stack_b, int len)
{
	int	groups;

	if (len >= 0 && len < 50)
		groups = 2;
	else if (len >= 50 && len < 75)
		groups = 3;
	else if (len >= 75 && len < 100)
		groups = 4;
	else if (len >= 100 && len < 200)
		groups = 5;
	else if (len >= 200 && len < 300)
		groups = 7;
	else if (len >= 300 && len < 600)
		groups = 10;
	else if (len >= 600)
		groups = 12;
	sort_a_bit(stack_a, stack_b, len, groups);
	return (0);
}
