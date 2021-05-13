/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/01 17:42:36 by iboeters      #+#    #+#                 */
/*   Updated: 2021/05/13 17:57:05 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	printf("stack_a:\n");
	ft_lstiter(stack_a, print_lst_num);
	// instructions(&input, &stack_a, &stack_b);
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
