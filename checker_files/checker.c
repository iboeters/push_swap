/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/01 17:42:36 by iboeters      #+#    #+#                 */
/*   Updated: 2021/06/24 13:54:26 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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

	if (lstsize(stack_b) > 0)
		write (1, "KO\n", 3);
	else
	{
		prev = *(int *)(stack_a->content);
		stack_a = stack_a->next;
		while (stack_a)
		{
			if (*(int *)(stack_a->content) < prev)
			{
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
	if (instructions(&input, &stack_a, &stack_b) == 1)
		return (ret_and_free(&stack_a, &stack_b, &input));
	if (stack_a)
	{
		// printf("stack_a:\n");
		// lstiter(stack_a, print_lst_num);
	}
	if (stack_b)
	{
		// printf("stack_b:\n");
		// lstiter(stack_b, print_lst_num);
	}
	// printf("---backwards---\n");
	if (stack_a)
	{
		t_lst *tmp;

		tmp = stack_a;
		stack_a = stack_a->prev;
		// printf("stack_a:\n");
		// printf("%i\n", *(int *)stack_a->content);
		while (stack_a != tmp)
		{
			stack_a = stack_a->prev;
			// printf("%i\n", *(int *)stack_a->content);
		}
		stack_a = tmp;
	}
	if (stack_b)
	{
		t_lst *tmp;

		tmp = stack_b;
		stack_b = stack_b->prev;
		// printf("stack_b:\n");
		// printf("%i\n", *(int *)stack_b->content);
		while (stack_b != tmp)
		{
			stack_b = stack_b->prev;
			// printf("%i\n", *(int *)stack_b->content);
		}
		stack_b = tmp;
	}
	check_sorted(stack_a, stack_b);
	lstclear(&input, free);
	lstclear(&stack_a, free);
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
