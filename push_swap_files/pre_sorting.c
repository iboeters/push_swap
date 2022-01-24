#include "push_swap.h"

static void	next_action(t_lst **stack_a, t_lst **stack_b, int i, int len, int len_tot, int group, int n)
{
	if (i == 0)
	{
		if ((*(int *)(*stack_a)->content < len_tot / 2)
		&& (*(int *)(*stack_a)->content >= (len_tot / 2 - (float)(1 + group) * (float)((float)len_tot / (n * 2)))))
		{
			pushes("pb", stack_a, stack_b, 1);
			rotates("rb", stack_a, stack_b, 1);
		}
		else if ((*(int *)(*stack_a)->content < (len_tot / 2 + (float)(1 + group) * (float)((float)len_tot / (n * 2))))
		&& (*(int *)(*stack_a)->content >= len_tot / 2))
			pushes("pb", stack_a, stack_b, 1);
	}
	else if (i > len / 2)
		rotates("rra", stack_a, stack_b, 1);
	else
		rotates("ra", stack_a, stack_b, 1);
}

static int	check_backwards(t_lst *stack, char ab, int len, int len_tot, int n, int group)
{
	int current;
	char not_ab;
	int i;

	current = 0;
	i = len - 1;
	while (stack)
	{
		current = *(int *)(stack)->content;
		if (((current < len_tot / 2)
		&& (current >= (len_tot / 2 - (float)(1 + group) * (float)((float)len_tot / (n * 2)))))
		|| ((current < (len_tot / 2 + (float)(1 + group) * (float)((float)len_tot / (n * 2))))
		&& (current >= len_tot / 2)))
			return (i);
		stack = stack->prev;
		i--;
	}
	return (0);
}

static int	check_push(t_lst *stack, int *i, int group, char ab, int len_tot, int n)
{
	int current;
	int start_over;
	t_lst	begin;
	int back_i;
	int save_i = 0;
	int len = lstsize(stack);

	begin = *stack;
	current = 0;
	start_over = 0;
	back_i = 0;
	while (stack)
	{
		current = *(int *)(stack)->content;
		if (stack->next == NULL)
		{
			start_over = 1;
			stack = &begin;
		}
		if (((current < len_tot / 2)
		&& (current >= (len_tot / 2 - (float)(1 + group) * (float)((float)len_tot / (n * 2)))))
		|| ((current < (len_tot / 2 + (float)(1 + group) * (float)((float)len_tot / (n * 2))))
		&& (current >= len_tot / 2)))
		{
			save_i = *i;
			while (*i > 0)
			{
				stack = stack->prev;
				(*i)--;
			}
			*i = save_i;
			back_i = check_backwards(stack, ab, len, len_tot, n, group);
			if (len - back_i < *i)
				*i = back_i;
			return (1);
		}
		stack = stack->next;
		(*i)++;
		if (start_over == 1)
		{
			start_over = 0;
			*i = 0;
		}
	}
	return (0);
}

void	sort_a_bit(t_lst **stack_a, t_lst **stack_b, int len, int n)
{
	int i;
	int group;
	int k;

	i = 0;
	group = 0;
	k = 0;
	while (lstsize(*stack_a) > 2/3 * len)
	{
		i = 0;
		check_push(*stack_a, &i, group, 'a', len, n);
		next_action(stack_a, stack_b, i, lstsize(*stack_a), len, group, n);
		if (lstsize(*stack_a) <= (float)len - (float)(group + 1) * (float)len / n + 1)
			group++;
		k++;
	}
}

static void push_half(t_lst **stack_a, t_lst **stack_b, int len)
{
	int i;
	
	i = 0;
	while (i < len)
	{
		if (*(int *)(*stack_a)->content < (len / 2))
			push(stack_b, stack_a, 'b', 1);
		else
			rotate(stack_a, 'a', 1);
		i++;
	}
}

static void	push_back(t_lst **stack_a, t_lst **stack_b, int len)
{
	int i;

	i = 0;
	while (i < len / 2)
	{
		push(stack_a, stack_b, 'a', 1);
		i++;
	}
	if (len % 2 == 1)
		push(stack_a, stack_b, 'a', 1);
}

int pre_sorting(t_lst **stack_a, t_lst **stack_b, int len)
{
	int groups;

	if (len >= 0 && len < 50)
		groups = 2;
	else if (len >= 50 && len < 75)
		groups = 3;
	else if (len >= 75 && len < 100)
		groups = 4;
	else if (len >= 100 && len < 200)
		groups = 5;
	else if (len >= 200)
		groups = 10;
	sort_a_bit(stack_a, stack_b, len, groups);
	return (0);
}
