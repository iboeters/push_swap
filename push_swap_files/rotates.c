#include "push_swap.h"

void	rotate(t_lst **stack, char ab, int print)
{
	t_lst	*first;

	if (print)
		printf("r%c\n", ab);
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	(first->prev)->next = first;
}

void	rr(t_lst **stack_a, t_lst **stack_b, int len_a, int len_b, int print)
{
	if (print)
		printf("rr\n");
	if (len_a >= 2)
		rotate(stack_a, 'a', 0);
	if (len_b >= 2)
		rotate(stack_b, 'b', 0);
}

void	reverse_rotate(t_lst **stack, char ab, int print)
{
	t_lst	*first;
	t_lst	*last;

	if (print)
		printf("rr%c\n", ab);
	last = (*stack)->prev;
	(last->prev)->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rrr(t_lst **stack_a, t_lst **stack_b, int len_a, int len_b, int print)
{
	if (print)
		printf("rrr\n");
	if (len_a >= 2)
		reverse_rotate(stack_a, 'a', 0);
	if (len_b >= 2)
		reverse_rotate(stack_b, 'b', 0);
}

void	rotates(char *instruction, t_lst **stack_a, t_lst **stack_b, int print)
{
	int	len_a;
	int	len_b;

	len_a = lstsize(*stack_a);
	len_b = lstsize(*stack_b);
	// printf("len_a=%d|len_b=%d\n", len_a, len_b);
	if (instruction[1] == 'a' && len_a >= 2)
		rotate(stack_a, 'a', print);
	else if (instruction[1] == 'b' && len_b >= 2)
		rotate(stack_b, 'b', print);
	else if (instruction[1] == 'r' && instruction[1] == '\0')
		rr(stack_a, stack_b, len_a, len_b, print);
	else if (instruction[2] == 'a' && len_a >= 2)
		reverse_rotate(stack_a, 'a', print);
	else if (instruction[2] == 'b' && len_b >= 2)
		reverse_rotate(stack_b, 'b', print);
	else
		rrr(stack_a, stack_b, len_a, len_b, print);
}
