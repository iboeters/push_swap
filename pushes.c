/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushes.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/03 20:22:37 by iboeters      #+#    #+#                 */
/*   Updated: 2021/05/03 21:42:59 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < b->size + 1)
	{
		b->arr[i] = b->arr[i - 1];
		i++;
	}
	b->arr[0] = a->arr[0];
	while (j < a->size)
	{
		a->arr[j] = a->arr[j + 1];
		j++;
	}
	a->size--;
	b->size++;
}

void	pb(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < a->size + 1)
	{
		a->arr[i] = a->arr[i - 1];
		i++;
	}
	a->arr[0] = b->arr[0];
	while (j < b->size)
	{
		b->arr[j] = b->arr[j + 1];
		j++;
	}
	a->size++;
	b->size--;
}

void pushes(char *instruction, t_stack *a, t_stack *b)
{
	if (instruction[1] == 'a' && a->size >= 1)
		pa(a, b);
	else if (instruction[1] == 'b' && b->size >= 1)
		pb(a, b);
}
