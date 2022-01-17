#include "push_swap.h"

// 3		3		1		1		2		2
// 2		1		2		3		1		3
// 1		2		3		2		3		1
// sa, rra	ra		-		rra sa	sa		rra

// reverse rotate: onderste bovenaan

// pushen naar b -> alle content * -1 doen??

int sorted(t_lst *stack)
{
	int	prev;

	prev = *(int *)(stack)->content;
	stack = stack->next;
	while (stack)
	{
		// printf("check ing: [%d] & [%d]\n", *(int *)(stack)->content, prev);
		if (prev > *(int *)(stack)->content)
			return (0);
		prev = *(int *)(stack)->content;
		stack = stack->next;
	}
	return (1);
}

void solve_three(t_lst **stack, char ab, int len)
{
	int first;
	int second;
	int third;

	if (len == 2 && !sorted(*stack)){
		swap(stack, ab, 1);
		return ;
	}
	else if (len == 2 && sorted(*stack))
		return ;
	else
	{
		first = *(int *)(*stack)->content;
		second = *(int *)((*stack)->next)->content;
		third = *(int *)((*stack)->next->next)->content;
		// printf("%d|%d|%d\n", first, second, third);
		if (first > second && second > third)
		{
			swap(stack, ab, 1);
			reverse_rotate(stack, ab, 1);
		}
		else if (first > second && second < third && third < first)
			rotate(stack, ab, 1);
		else if (first < second && second > third && third > first)
		{
			reverse_rotate(stack, ab, 1);
			swap(stack, ab, 1);
		}
		else if (first > second && second < third && third > first)
			swap(stack, ab, 1);
		else if (first < second && second > third && third < first)
			reverse_rotate(stack, ab, 1);
	}
}

void	half(t_lst **stack_a, t_lst **stack_b, int len)
{
	int i;
	int pushed;

	i = 0;
	pushed = 0;
	while (i < len && pushed < len / 2)
	{
		if (*(int *)(*stack_a)->content < len / 2)
		{
			push(stack_b, stack_a, 'b', 1);
			pushed++;
		}
		else
		{
			rotate(stack_a, 'a', 1);
			i++;
		}
	}

}

int algo_2(t_lst **stack_a, t_lst **stack_b)
{
    int len;
	int i;

	i = 0;
	if (sorted(*stack_a)) // if already sorted-> return
	{
		// printf("sorted\n");
		return (0);
	}
    len = lstsize(*stack_a);
	// printf("len = %d| half = %d\n", len, len / 2);
    if (len <= 3)
        solve_three(stack_a, 'a', len);
	else if (len <= 6)
	{
		half(stack_a, stack_b, len);
		solve_three(stack_a, 'a', lstsize(*stack_a));
		solve_three(stack_b, 'b', lstsize(*stack_b));
		while (i < len / 2)
		{
			push(stack_a, stack_b, 'a', 1);
			i++;
		}
	}
	lstiter(*stack_a, print_lst_num);	
    return(0);
}
