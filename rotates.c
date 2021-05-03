/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotates.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/03 20:22:46 by iboeters      #+#    #+#                 */
/*   Updated: 2021/05/03 21:15:45 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_stack *a)
{
	int tmp;
	int	i;

	i = 0;
	tmp = a->arr[0];
	while (i < a->size - 1)
	{
		a->arr[i] = a->arr[i + 1];
		i++;
	}
	a->arr[i] = tmp;
}

void	rb(t_stack *b)
{
	int tmp;
	int	i;

	i = 0;
	tmp = b->arr[0];
	while (i < b->size - 1)
	{
		b->arr[i] = b->arr[i + 1];
		i++;
	}
	b->arr[i] = tmp;
}

void	rr(t_stack *a, t_stack *b)
{
	if (a->size >= 2)
		ra(a);
	if (b->size >= 2)
		rb(b);
}

void	rra(t_stack *a)
{
	int tmp;
	int i;

	i = a->size - 1;
	tmp = a->arr[i];
	while (i > 0)
	{
		a->arr[i] = a->arr[i - 1];
		i--;
	}
	a->arr[i] = tmp;
}

void	rrb(t_stack *b)
{
	int tmp;
	int i;

	i = b->size - 1;
	tmp = b->arr[i];
	while (i > 0)
	{
		b->arr[i] = b->arr[i - 1];
		i--;
	}
	b->arr[i] = tmp;
}

void	rrr(t_stack *a, t_stack *b)
{
	if (a->size >= 2)
		rra(a);
	if (b->size >= 2)
		rrb(b);
}

void rotates(char *instruction, t_stack *a, t_stack *b)
{
	if (instruction[1] == 'a' && a->size >= 2)
		ra(a);
	else if (instruction[1] == 'b' && b->size >= 2)
		rb(b);
	else if (instruction[1] == 'r' && instruction[1] == '\0')
		rr(a, b);
	else if (instruction[2] == 'a' && a->size >= 2)
		rra(a);
	else if (instruction[2] == 'b' && b->size >= 2)
		rrb(b);
	else
		rrr(a, b);
}
