#include "checker.h"

int	ret_and_free(t_lst **stack_a, t_lst **stack_b, t_lst **input)
{
	lstclear(input, free);
	lstclear(stack_a, free);
	lstclear(stack_b, free);
	return (1);
}

void	print_lst_num(void *num)
{
	printf("%i\n", *((int *)num));
}

void	check_sorted(t_lst *stack_a, t_lst *stack_b)
{
	int	prev;

	// printf("stack_a:\n");
	// lstiter(stack_a, print_lst_num);
	// printf("stack_b:\n");
	// lstiter(stack_b, print_lst_num);
	if (lstsize(stack_b) > 0)
	{
		printf("stack_b not empty\n");
		write (1, "KO\n", 3);
	}
	else
	{
		prev = *(int *)(stack_a->content);
		stack_a = stack_a->next;
		while (stack_a)
		{
			// printf("|%d|\n", prev);
			if (*(int *)(stack_a->content) < prev)
			{
				// printf("goes wrong here: [%d][%d]\n", prev, *(int *)(stack_a->content));
				write(1, "KO\n", 3);
				return ;
			}
			prev = *(int *)(stack_a->content);
			stack_a = stack_a->next;
		}
		write(1, "OK\n", 3);
	}
}

int	main(int argc, char **argv)
{
	t_lst	*stack_a;
	t_lst	*stack_b;
	t_lst	*input;

	stack_a = NULL;
	stack_b = NULL;
	input = NULL;
	if (argc <= 1)
		return (1);
	if (save_input(argc, argv, &stack_a) == 1)
		return (ret_and_free(&stack_a, &stack_b, &input));
	if (save_instructions(&input) == 1)
		return (ret_and_free(&stack_a, &stack_b, &input));
	if (instructions(input, &stack_a, &stack_b) == 1)
		return (ret_and_free(&stack_a, &stack_b, &input));
	check_sorted(stack_a, stack_b);
	if (input)
		lstclear(&input, free);
	if (stack_a)
		lstclear(&stack_a, free);
	if (stack_b)
		lstclear(&stack_b, free);
	// while (1){} //check leaks
	return (0);
}

/* to do:
** [V] error with duplicate arguments
** [V] empty string ""
** [V] change everything to linked list
** [V] pa <> pb
*/

// if (stack_a)
// {
// 	// printf("stack_a:\n");
// 	// lstiter(stack_a, print_lst_num);
// }
// if (stack_b)
// {
// 	// printf("stack_b:\n");
// 	// lstiter(stack_b, print_lst_num);
// }
// printf("---backwards---\n");
// if (stack_a)
// {
// 	t_lst *tmp;

// 	tmp = stack_a;
// 	stack_a = stack_a->prev;
// 	// printf("stack_a:\n");
// 	// printf("%i\n", *(int *)stack_a->content);
// 	while (stack_a != tmp)
// 	{
// 		stack_a = stack_a->prev;
// 		// printf("%i\n", *(int *)stack_a->content);
// 	}
// 	stack_a = tmp;
// }
// if (stack_b)
// {
// 	t_lst *tmp;

// 	tmp = stack_b;
// 	stack_b = stack_b->prev;
// 	// printf("stack_b:\n");
// 	// printf("%i\n", *(int *)stack_b->content);
// 	while (stack_b != tmp)
// 	{
// 		stack_b = stack_b->prev;
// 		// printf("%i\n", *(int *)stack_b->content);
// 	}
// 	stack_b = tmp;
// }