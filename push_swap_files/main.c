#include "push_swap.h"

void	print_lst_num(void *num)
{
	printf("%i\n", *((int *)num));
}

int	free_and_ret(t_lst **stack_a, t_lst **stack_b, int ret)
{
	lstclear(stack_a, free);
	lstclear(stack_b, free);
	return (ret);
}

int	main(int argc, char **argv)
{
	t_lst	*stack_a;
	t_lst	*stack_b;
	int		len;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (1);
	if (save_input(argc, argv, &stack_a) == 1)
		return (free_and_ret(&stack_a, &stack_b, 1));
	if (change_nums(stack_a) == 1)
		return (free_and_ret(&stack_a, &stack_b, 1));
	len = lstsize(stack_a);
	if (len > 6)
		algo_3(&stack_a, &stack_b, len);
	else
		algo_2(&stack_a, &stack_b);
	lstclear(&stack_a, free);
	lstclear(&stack_b, free);
	// while (1){}
	return (0);
}
