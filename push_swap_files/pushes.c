/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushes.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/03 20:22:37 by iboeters      #+#    #+#                 */
/*   Updated: 2021/06/24 14:16:04 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_lst **stack_1, t_lst **stack_2, char ab, int print)
{
	t_lst	*last;
	t_lst	*tmp_addr;

	if (print)
		printf("p%c\n", ab);
	last = (*stack_2)->prev;
	tmp_addr = (*stack_2)->next;
	lstadd_front(stack_1, *stack_2);
	*stack_2 = tmp_addr;
	if (tmp_addr != NULL)
		(*stack_2)->prev = last;
}

void	pushes(char *instruction, t_lst **stack_a, t_lst **stack_b, int print)
{
	if (instruction[1] == 'a' && lstsize(*stack_b) >= 1)
		push(stack_a, stack_b, 'a', print);
	else if (instruction[1] == 'b' && lstsize(*stack_a) >= 1)
		push(stack_b, stack_a, 'b', print);
}
