/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/01 17:42:36 by iboeters      #+#    #+#                 */
/*   Updated: 2021/05/03 20:55:00 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_stack(t_stack stack, char name)
{
	int	i;

	i = 0;
	printf("%c\n-\n", name);
	while (i < stack.size)
	{
		printf("%i\n", stack.arr[i]);
		i++;
	}
	return ;
}

void	free_stacks(t_stack a, t_stack b)
{
	if (a.arr)
	{
		free(a.arr);
		a.arr = NULL;
	}
	if (b.arr)
	{
		free(b.arr);
		b.arr = NULL;
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_list	*input;

	if (argc <= 1)
		return (1);
	a.arr = (int *)malloc((argc - 1) * sizeof(int));
	b.arr = (int *)malloc((argc - 1) * sizeof(int));
	b.size = 0;
	if (save_input(argc, argv, &a, &input) == 1)
		return (1);
	instructions(&input, &a, &b);
	printf("\n");
	print_stack(a, 'a');
	printf("\n");
	print_stack(b, 'b');
	ft_lstclear(&input, free);
	free_stacks(a, b);
	// while (1){} //check leaks
	return (0);
}

/* to do:
** [ ] error with duplicate instructions??
*/