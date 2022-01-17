#include "push_swap.h"

int		next_action(int i, int len)
{
	if (i > len / 2)
	{
		return (REV_ROT);
	}
	else if (i != 0)
		return (ROT);
	return (SWAP);
}

int	not_seq(int current, int next, char ab)
{
	if (ab == 'a' && current > next)
		return (1);
	else if (ab == 'b' && current < next)
	{
		// printf("current=%d|next =%d\n", current, next);
		return (1);
	}
	return (0);
}

int	check_backwards(t_lst *stack, int low_num, int high_num, char ab, int len)
{
	int current;
	int prev;
	char not_ab;
	int i;

	current = 0;
	prev = 0;
	i = len - 1;
	// printf("len=%d, i = %d\n", len, i);
	while (stack)
	{
		current = *(int *)(stack)->content;
		prev = *(int *)((stack)->prev)->content;
		if (not_seq(prev, current, ab) &&
		current != low_num && current != high_num &&
		prev != low_num && prev != high_num)
		{
			// printf("[%d]|[%d]|[%d]\n", current, prev, i);
			return (i);
		}
		stack = stack->prev;
		i--;
	}
}

int	check_swap(t_lst *stack, int *i, int low_num, int high_num, char ab)
{
	int current;
	int next;
	int start_over;
	t_lst	begin;
	int back_i;

	begin = *stack;
	current = 0;
	next = 0;
	start_over = 0;
	back_i = 0;
	int save_i = 0;
	int len = lstsize(stack);
	while (stack)
	{
		current = *(int *)(stack)->content;
		if (stack->next == NULL)
		{
			start_over = 1;
			stack = &begin;
			next = *(int *)(stack)->content;
		}
		else
			next = *(int *)((stack)->next)->content; // hier segfault ie
		if (not_seq(current, next, ab) &&
		current != low_num && current != high_num &&
		next != low_num && next != high_num)
		{
			save_i = *i;
			while (*i > 0)
			{
				stack = stack->prev;
				(*i)--;
			}
			*i = save_i;
			back_i = check_backwards(stack, low_num, high_num, ab, len);
			// printf("*i[%d]back_i[%d]\n", *i, back_i);
			// printf("res1[%d]res2[%d]\n", len - back_i, *i);
			if (len - back_i < *i)
				*i = back_i;
			// printf("[%d]|[%d]\n", current, next);
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

void	do_action(int action, t_lst **stack, char ab)
{
	if (action == ROT)
		rotate(stack, ab, 1);
	else if (action == REV_ROT)
		reverse_rotate(stack, ab, 1);
	else if (action == SWAP)
		swap(stack, ab, 1);
}

void	uno(t_lst **stack_a, t_lst **stack_b, t_lst *low_a, t_lst *high_a, t_lst *low_b, t_lst *high_b, int *i, int *j)
{
	int	sort_a;
	int	sort_b;
	int	action_a;
	int	action_b;

	sort_a = 0;
	sort_b = 0;
	action_a = 0;
	action_b = 0;

	while (!sort_a || !sort_b)
	{
		*i = 0;
        *j = 0;
		if (is_sorted_front(low_a, high_a, *stack_a, 'a') && is_sorted_back(low_a, 'a'))
			sort_a = 1;
		if (is_sorted_front(high_b, low_b, *stack_b, 'b') && is_sorted_back(high_b, 'b'))
			sort_b = 1;
		// printf("sort_a=%d | sort_b=%d\n", sort_a, sort_b);
		if (!sort_a)
		{
			check_swap(*stack_a, i, *(int *)low_a->content, *(int *)high_a->content, 'a');
			action_a = next_action(*i, lstsize(*stack_a));
		}
		if (!sort_b)
		{
			check_swap(*stack_b, j, *(int *)(low_b->content), *(int *)(high_b->content), 'b');
			action_b = next_action(*j, lstsize(*stack_b));
		}
		// printf("i=%d| action_a=%d | j=%d | action_b=%d\n", *i, action_a, *j, action_b);
		if (action_a == action_b && !sort_a && !sort_b)
		{
			if (action_a == ROT)
				rr(stack_a, stack_b, lstsize(*stack_a), lstsize(*stack_b), 1);
			else if (action_a == REV_ROT)
				rrr(stack_a, stack_b, lstsize(*stack_a), lstsize(*stack_b), 1);
			else if (action_a == SWAP)
				ss(stack_a, stack_b, 1);
		}
		else
		{
			if (!sort_a)
				do_action(action_a, stack_a, 'a');
			if (!sort_b)
				do_action(action_b, stack_b, 'b');
		}
	}
	return ;
}
