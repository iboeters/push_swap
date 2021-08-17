#include "push_swap.h"

int	is_sorted_front(t_lst *lowest, t_lst *highest, t_lst *stack, char ab)
{
	int	prev;

	if (lowest == stack) // if so, sorted_back is enough
		return (1);
	lowest = lowest->prev;
	prev = *(int *)(lowest->content);
	lowest = lowest->prev;
	while (lowest != (stack->prev)->prev)
	{
		if (ab == 'a' && *(int *)(lowest->content) > prev && lowest != highest &&
		prev != *(int *)(highest->content))
			return (0);
		else if (ab == 'b' && *(int *)(lowest->content) < prev && lowest != highest &&
		prev != *(int *)(highest->content))
			return (0);
		prev = *(int *)(lowest->content);
		lowest = lowest->prev;
	}
	return (1);
}

int	is_sorted_back(t_lst *lowest, char ab)
{
	int	prev;

	prev = *(int *)(lowest->content);
	lowest = lowest->next;
	while (lowest)
	{
		if (ab == 'a' && *(int *)(lowest->content) < prev)
			return (0);
		else if (ab == 'b' && *(int *)(lowest->content) > prev)
			return (0);
		prev = *(int *)(lowest->content);
		lowest = lowest->next;
	}
	return (1);
}

void	rotate_right(t_lst **stack_a, t_lst *lowest, int len, char ab)
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
			reverse_rotate(stack_a, ab, 1);
			j++;
		}
	}
	else
	{
		while (j < i)
	    {
	    	rotate(stack_a, ab, 1);
	    	j++;
	    }
	}
}

void	push_back(t_lst **stack_a, t_lst **stack_b)
{
	int	len;
	int	i;

	len = lstsize(*stack_b);
	i = 0;
	while (i < len)
	{
		push(stack_a, stack_b, 'a', 1);
		i++;
	}
}

void	algo_1_solver(t_lst **stack_a, t_lst **stack_b, int len)
{
	t_lst *low_a;
	t_lst *high_a;
	t_lst	*low_b;
	t_lst	*high_b;
	int	i;
	int j;

	i = 0;
	j = 0;
	len += 2;
	low_a = *stack_a;
	high_a = (*stack_a)->prev;
	low_b = (*stack_b)->prev;
	high_b = *stack_b;
	// printf("low_a=%d, high_a=%d\n", *(int *)low_a->content, *(int *)high_a->content);
	// printf("stack_a:\n");
	// lstiter(*stack_a, print_lst_num);
	uno(stack_a, stack_b, low_a, high_a, low_b, high_b, &i, &j, len);
	rotate_right(stack_a, low_a, len, 'a');
	rotate_right(stack_b, high_b, len, 'b');
	push_back(stack_a, stack_b);
	// printf("stack_a:\n");
	// lstiter(*stack_a, print_lst_num);
	// printf("stack_b:\n");
	// lstiter(*stack_b, print_lst_num);
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
