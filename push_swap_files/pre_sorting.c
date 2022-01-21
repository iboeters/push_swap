#include "push_swap.h"

// 0	0 - 12.5
// 1	12.5 - 25	/
// 2	25 - 37.5
// 3	37.5 - 50	/ + r ˆ
// 4	50 - 62.5	/
// 5 	62.5 - 75
// 6	75 - 82.5	/
// 7	82.5 - 100

// static void	do_action(int action, t_lst **stack_a, t_lst **stack_b, char ab)
// {
// 	if (action == ROT)
// 		rotate(stack_a, ab, 1);
// 	else if (action == REV_ROT)
// 		reverse_rotate(stack_a, ab, 1);
// 	else if (action == PUSH)
// 		push(stack_b, stack_a, 'b', 1);
// }

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
	// printf("len=%d, i = %d\n", len, i);
	while (stack)
	{
		// if (i == len - 1)
		// 	printf("|back|between [%d][%f] and [%f][%d]\n", len_tot / 2, (len_tot / 2 - (float)(1 + group) * (float)((float)len_tot / (n * 2))), (len_tot / 2 + (float)(1 + group) * (float)((float)len_tot / (n * 2))), len_tot / 2);
		current = *(int *)(stack)->content;
		if (((current < len_tot / 2)
		&& (current >= (len_tot / 2 - (float)(1 + group) * (float)((float)len_tot / (n * 2)))))
		|| ((current < (len_tot / 2 + (float)(1 + group) * (float)((float)len_tot / (n * 2))))
		&& (current >= len_tot / 2)))
		{
			// printf("|b|found:[%d] at [%d]\n", current, i);
			return (i);
		}
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
		// if (*i == 0)
		// 	printf("|front|between [%d][%f] and [%f][%d]\n", len_tot / 2, (len_tot / 2 - (float)(1 + group) * (float)((float)len_tot / (n * 2))), (len_tot / 2 + (float)(1 + group) * (float)((float)len_tot / (n * 2))), len_tot / 2);
		if (((current < len_tot / 2)
		&& (current >= (len_tot / 2 - (float)(1 + group) * (float)((float)len_tot / (n * 2)))))
		|| ((current < (len_tot / 2 + (float)(1 + group) * (float)((float)len_tot / (n * 2))))
		&& (current >= len_tot / 2)))
		{
			// printf("|f|found:[%d] at [%d]\n", current, *i);
			save_i = *i;
			while (*i > 0)
			{
				stack = stack->prev;
				(*i)--;
			}
			*i = save_i;
			back_i = check_backwards(stack, ab, len, len_tot, n, group);
			// printf("*i[%d]back_i[%d]\n", *i, back_i);
			// printf("res1[%d]res2[%d]\n", *i, len - back_i);
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

void	sort_a_bit_2(t_lst **stack_a, t_lst **stack_b, int len, int n)
{
	int i;
	int group;
	int k;

	i = 0;
	group = 0;
	k = 0;
	while (lstsize(*stack_a))
	{
		i = 0;
		check_push(*stack_a, &i, group, 'a', len, n);
		next_action(stack_a, stack_b, i, lstsize(*stack_a), len, group, n);
		// printf("lstsize=%d|%f\n", lstsize(*stack_a), len - (float)(group + 1) * (float)len / n);
		if (lstsize(*stack_a) <= (float)len - (float)(group + 1) * (float)len / n + 1)
			group++;
		k++;
		// if (k == 100)
		// 	exit(1);
	}
	// printf("stack_a:\n");
	// printf("stack_a (len = %d)\n", lstsize(*stack_a));
	// lstiter(*stack_a, print_lst_num);
	// printf("stack_b:\n");
	// printf("stack_b (len = %d)\n", lstsize(*stack_b));
	// lstiter(*stack_b, print_lst_num);
	// exit(1);
}

void	sort_a_bit(t_lst **stack_a, t_lst **stack_b, int len, int n)
{
	int i;
	int new_len;
	int j;
	int part;

	i = 0;
	while (i < n)
	{
		j = 0;
		new_len = lstsize(*stack_a);
		while (j < new_len)
		{
			if (*(int *)(*stack_a)->content < len / 2
			&& *(int *)(*stack_a)->content >= (len / 2 - (float)(1 + i) * (float)((float)len / (n * 2))))
			{
				push(stack_b, stack_a, 'b', 1);
				rotates("rb", stack_a, stack_b, 1);
			}
			else if (*(int *)(*stack_a)->content < (int)(len / 2 + (float)(1 + i) * (float)((float)len / (n * 2)))
			&& *(int *)(*stack_a)->content >= len / 2)
			{
				push(stack_b, stack_a, 'b', 1);
			}
			else
				rotate(stack_a, 'a', 1);
			j++;
		}
		i++;
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
	else if (len >= 50 && len < 100)
		groups = 4;
	else if (len >= 100 && len < 200)
		groups = 8;
	else if (len >= 200)
		groups = 18;
	if (len > 9)
	{
		sort_a_bit_2(stack_a, stack_b, len, groups);
		push_back(stack_a, stack_b, len);
	}
	else
		push_half(stack_a, stack_b, len);
	return (0);
}
