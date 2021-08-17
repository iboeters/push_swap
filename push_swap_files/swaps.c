#include "push_swap.h"

void	swap(t_lst **stack, char ab, int print)
{
	t_lst	*prev_1;
	t_lst	*prev_2;
	t_lst	*next_1;
	t_lst	*next_2;

	if (print)
		printf("s%c\n", ab);
	prev_1 = (*stack)->prev;
	prev_2 = *stack;
	next_1 = (*stack)->next;
	next_2 = (*stack)->next->next;
	*stack = (*stack)->next;
	(*stack)->next = prev_2;
	(*stack)->next->next = next_2;
	if (next_2 != NULL)
	{
		(*stack)->prev = prev_1;
		(*stack)->next->prev = *stack;
		next_2->prev = prev_2;
	}
}

void	ss(t_lst **stack_a, t_lst **stack_b, int print)
{
	if (print)
		printf("ss\n");
	if (lstsize(*stack_a) >= 2)
		swap(stack_a, 'a', 0);
	if (lstsize(*stack_b) >= 2)
		swap(stack_b, 'b', 0);
}

void	swaps(char *instruction, t_lst **stack_a, t_lst **stack_b, int print)
{
	if (instruction[1] == 'a' && lstsize(*stack_a) >= 2)
		swap(stack_a, 'a', print);
	else if (instruction[1] == 'b' && lstsize(*stack_b) >= 2)
		swap(stack_b, 'b', print);
	else if (instruction[1] == 's')
		ss(stack_a, stack_b, print);
}
