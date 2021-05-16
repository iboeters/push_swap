/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/01 17:42:36 by iboeters      #+#    #+#                 */
/*   Updated: 2021/05/16 23:07:38 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_sorted(t_list *stack_a, t_list *stack_b)
{
	int	prev;

	if (ft_lstsize(stack_b) > 0)
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
	t_list	*input;
	t_list	*stack_a;
	t_list	*stack_b;

	input = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (1);
	if (save_input(argc, argv, &stack_a, &input) == 1)
		return (1);
	instructions(&input, &stack_a, &stack_b);
	// printf("stack_a:\n");
	// ft_lstiter(stack_a, print_lst_num);
	// printf("stack_b:\n");
	// ft_lstiter(stack_b, print_lst_num);
	check_sorted(stack_a, stack_b);
	ft_lstclear(&input, free);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	// while (1){} //check leaks
	return (0);
}

/* to do:
** [V] error with duplicate arguments
** [V] empty string ""
** [V] change everything to linked list
** [V] pa <> pb
*/
