/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 14:35:18 by iboeters      #+#    #+#                 */
/*   Updated: 2022/01/25 14:35:20 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (0);
}
