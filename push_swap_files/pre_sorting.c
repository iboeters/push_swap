#include "push_swap.h"

void	push_half(t_lst **stack_a, t_lst **stack_b, int len)
{
	int	i;
    int new_len;

	i = 0;
	while (i < len)
	{
		if (*(int *)(*stack_a)->content < len / 8)
			push(stack_b, stack_a, 'b', 1);
		else
			rotate(stack_a, 'a', 1);
		i++;
	}
    new_len = lstsize(*stack_a);
    i = 0;
	while (i < new_len)
	{
		if (*(int *)(*stack_a)->content < len / 6)
			push(stack_b, stack_a, 'b', 1);
		else
			rotate(stack_a, 'a', 1);
		i++;
	}
    new_len = lstsize(*stack_a);
    i = 0;
	while (i < new_len)
	{
		if (*(int *)(*stack_a)->content < len / 4)
			push(stack_b, stack_a, 'b', 1);
		else
			rotate(stack_a, 'a', 1);
		i++;
	}
    new_len = lstsize(*stack_a);
    i = 0;
	while (i < new_len)
	{
		if (*(int *)(*stack_a)->content < len / 2)
			push(stack_b, stack_a, 'b', 1);
		else
			rotate(stack_a, 'a', 1);
		i++;
	}
}
int pre_sorting(t_lst **stack_a, t_lst **stack_b, int len)
{
    push_half(stack_a, stack_b, len);
    return (0);
}