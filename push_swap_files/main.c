/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/02 19:11:10 by iboeters      #+#    #+#                 */
/*   Updated: 2021/05/18 21:15:36 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst_num(void *num)
{
	printf("%i\n", *((int *)num));
}

int	main(int argc, char **argv)
{
	t_lst	*stack_a;
	t_lst	*stack_b;
	t_lst	*output;

	stack_a = NULL;
	stack_b = NULL;
	output = NULL;
	if (argc <= 1)
		return (1);
	if (save_input(argc, argv, &stack_a) == 1)
		return (1);
	if (algo_1(&output, &stack_a, &stack_b) == 1)
		return (1);
	if (stack_a)
	{
		printf("stack_a:\n");
		lstiter(stack_a, print_lst_num);
	}
	if (stack_b)
	{
		printf("stack_b:\n");
		lstiter(stack_b, print_lst_num);
	}
	return (0);
}
