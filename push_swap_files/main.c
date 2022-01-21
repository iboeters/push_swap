#include "push_swap.h"

// to do:
// [v] less than 4 nums
// [v] check push_swap from save_input on

// ARG="0 6 2 4"
// ./push_swap $ARG
// ./push_swap $ARG | ./checker $ARG
// ./push_swap $ARG | wc -l

// wc = word count
// wc -c <filename> prints the byte count
// wc -l <filename> prints the line count
// wc -m <filename> prints the character count
// wc -w <filename> prints the word count
// wc -L <filename> prints the length of the longest line (GNU extension)

void	print_lst_num(void *num)
{
	printf("%i\n", *((int *)num));
}

int free_and_ret(t_lst **stack_a, t_lst **stack_b, int ret)
{
	lstclear(stack_a, free);
	lstclear(stack_b, free);
	return (ret);
}

int	main(int argc, char **argv)
{
	t_lst	*stack_a;
	t_lst	*stack_b;
	int len;

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
	{
		if (algo_1(&stack_a, &stack_b) == 1)
			return (free_and_ret(&stack_a, &stack_b, 1));
	}
	else if (algo_2(&stack_a, &stack_b) == 1)
		return (free_and_ret(&stack_a, &stack_b, 1));
	lstclear(&stack_a, free);
	lstclear(&stack_b, free);
	// while (1){}
	return (0);
}
