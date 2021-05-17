/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushes.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/03 20:22:37 by iboeters      #+#    #+#                 */
/*   Updated: 2021/05/17 16:40:27 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push(t_lst **stack_1, t_lst **stack_2)
{
	t_lst	*last;
	t_lst	*tmp_addr;

	last = (*stack_2)->prev; //itself
	tmp_addr = (*stack_2)->next; //NULL; but is it?? :addfront
	lstadd_front(stack_1, *stack_2); //should go okay
	*stack_2 = tmp_addr; //NULL
	if (tmp_addr != NULL)
		(*stack_2)->prev = last; //itself
}

void	pushes(char *instruction, t_lst **stack_a, t_lst **stack_b)
{
	if (instruction[1] == 'a' && lstsize(*stack_b) >= 1)
		push(stack_a, stack_b);
	else if (instruction[1] == 'b' && lstsize(*stack_a) >= 1)
		push(stack_b, stack_a);
}
