/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 14:29:24 by iboeters      #+#    #+#                 */
/*   Updated: 2022/01/25 14:35:02 by iboeters      ########   odam.nl         */
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

void	check_sorted(t_lst *stack_a, t_lst *stack_b)
{
	int	prev;

	if (lstsize(stack_b) > 0)
		write(STDOUT_FILENO, "KO\n", ft_strlen("KO\n"));
	else
	{
		prev = *(int *)(stack_a->content);
		stack_a = stack_a->next;
		while (stack_a)
		{
			if (*(int *)(stack_a->content) < prev)
			{
				write(STDOUT_FILENO, "KO\n", ft_strlen("KO\n"));
				return ;
			}
			prev = *(int *)(stack_a->content);
			stack_a = stack_a->next;
		}
		write(STDOUT_FILENO, "OK\n", ft_strlen("KO\n"));
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
	return (0);
}
