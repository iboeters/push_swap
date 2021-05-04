/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/01 17:42:36 by iboeters      #+#    #+#                 */
/*   Updated: 2021/05/04 18:49:25 by iboeters      ########   odam.nl         */
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
	t_list	*input;
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc <= 1)
		return (1);
	if (save_input(argc, argv, &stack_a, &input) == 1)
		return (1);
	printf("stack_a:\n");
	ft_lstiter(stack_a, print_lst_num);
	// instructions(&input, &stack_a, &stack_b);
	printf("\n");
	// print_stack(a, 'a');
	// printf("\n");
	// print_stack(b, 'b');
	ft_lstclear(&input, free);
	ft_lstclear(&stack_a, free);
	// while (1){} //check leaks
	return (0);
}

/* to do:
** [V] error with duplicate arguments
** [V] empty string ""
** [ ] change everything to linked list
** [ ] pa <> pb
*/
