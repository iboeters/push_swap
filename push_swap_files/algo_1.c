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

void	push_first(t_lst **stack_1, t_lst **stack_2, int first_index, int *second_index, const int len, char ab)
{
	int i;
	char other;

	i = 0;
	if (ab == 'a')
		other = 'b';
	else
		other = 'a';
	if (first_index >= len / 2)
	{
		while (i < len - first_index)
		{
			reverse_rotate(stack_1, ab, 1);
			(*second_index) = (*second_index) + 1 % len;
			i++;
		}
		push(stack_2, stack_1, other, 1);
		(*second_index)--;
	}
	else if (first_index < len / 2)
	{
		while (i < first_index)
		{
			(*second_index)--;
			if ((*second_index) == -1)
				(*second_index) = len - 1;
			rotate(stack_1, ab, 1);
			i++;
		}
		push(stack_2, stack_1, other, 1);
		(*second_index)--;
	}
		// printf("*second_index=%d\n", (*second_index));
}

void	push_second(t_lst **stack_1, t_lst **stack_2, int second_index, const int len, char ab)
{
	int i;
	char other;

	i = 0;
	if (ab == 'a')
		other = 'b';
	else
		other = 'a';
	if (second_index >= len / 2)
	{
		while (i < len - second_index)
		{
			reverse_rotate(stack_1, ab, 1);
			i++;
		}
		push(stack_2, stack_1, other, 1);
	}
	else if (second_index < len / 2)
	{
		while (i < second_index)
		{
			rotate(stack_1, ab, 1);
			i++;
		}
		push(stack_2, stack_1, other, 1);
	}
}

int	push_low_high(t_lst **stack_1, t_lst **stack_2, int low_index, int high_index, int len, char ab)
{
	// printf("%i|%i|%i\n", len, low_index, high_index);
	if (ab == 'a' && low_index == 0 && high_index == len / 2 - 1)
		return (0);
	else if (ab == 'b' && low_index == len / 2 - 1 && high_index == 0)
		return (0);
	if (low_closest(low_index, high_index, len / 2))
	{
		push_first(stack_1, stack_2, low_index, &high_index, len / 2, ab);
		len--;
		push_second(stack_1, stack_2, high_index, len / 2, ab);
	}
	else
	{
		push_first(stack_1, stack_2, high_index, &low_index, len / 2, ab);
		len--;
		push_second(stack_1, stack_2, low_index, len / 2, ab);
	}
	return (1);
}

unsigned int	get_index(t_lst **stack_1, unsigned int num)
{
	unsigned int index;
	t_lst	*tmp;

	index = 0;
	tmp = *stack_1;
	while (*stack_1)
	{
		if (*(unsigned int *)(*stack_1)->content == num)
		{
			*stack_1 = tmp;
			return (index);
		}
		*stack_1 = (*stack_1)->next;
		index++;
	}
	*stack_1 = tmp;
	return (0);
}

void	push_half(t_lst **stack_a, t_lst **stack_b, const int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (*(int *)(*stack_a)->content < len / 2)
			push(stack_b, stack_a, 'b', 1);
		else
			rotate(stack_a, 'a', 1);
		i++;
	}
}

int	algo_1(t_lst **stack_a, t_lst **stack_b)
{
	int	len;
	int	ret;

	len = lstsize(*stack_a);
	push_half(stack_a, stack_b, len);
	ret = push_low_high(stack_a, stack_b, get_index(stack_a, len / 2),
	get_index(stack_a, len - 1), len, 'a');
	if (*stack_b && *(int *)((*stack_b)->content) > *(int *)(((*stack_b)->next)->content) && ret)
		swap(stack_b, 'b', 1);
	if (*stack_b && ret)
	{
		push(stack_a, stack_b, 'a', 1);
		push(stack_a, stack_b, 'a', 1);
		rotate(stack_a, 'a', 1);
	}
	ret = push_low_high(stack_b, stack_a, get_index(stack_b, 0),
	get_index(stack_b, len / 2 - 1), len, 'b');
	if (*stack_a && *(int *)((*stack_a)->content) < *(int *)(((*stack_a)->next)->content) && ret)
		swap(stack_a, 'a', 1);
	if (*stack_a && ret)
	{
		push(stack_b, stack_a, 'b', 1);
		push(stack_b, stack_a, 'b', 1);
		rotate(stack_b, 'b', 1);
	}
	// printf("stack_a:\n");
	// lstiter(*stack_a, print_lst_num);
	// printf("stack_b:\n");
	// lstiter(*stack_b, print_lst_num);
	// len = lstsize(*stack_a);
	algo_1_solver(stack_a, stack_b, len);
	return (0);
}
