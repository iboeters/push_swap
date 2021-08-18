#include "push_swap.h"

void	print_lst_num(void *num)
{
	printf("%i\n", *((int *)num));
}

int	main(int argc, char **argv)
{
	t_lst	*stack_a;
	t_lst	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (1);
	if (save_input(argc, argv, &stack_a) == 1)
		return (1); //freeen
	if (change_nums(stack_a) == 1)
		return (1); //freeen
	if (algo_1(&stack_a, &stack_b) == 1)
		return (1); //freeen
	lstclear(&stack_a, free);
	lstclear(&stack_b, free);
	return (0);
}

// to do:
// [ ] less than 4 nums
