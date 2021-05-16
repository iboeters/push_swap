/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/03 12:37:40 by iboeters      #+#    #+#                 */
/*   Updated: 2021/05/16 23:08:21 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(const char *str, const char *str2)
{
	int	i;

	i = 0;
	while (str[i] == str2[i] && str[i] != '\0' && str2[i] != '\0')
	{
		i++;
	}
	if (str[i] == '\0' && str2[i] == '\0')
		return (0);
	return (1);
}

int	valid_instructions(t_list *input)
{
	while (input)
	{
		if (ft_strcmp(input->content, "sa") == 0
			|| ft_strcmp(input->content, "sb") == 0
			|| ft_strcmp(input->content, "ss") == 0
			|| ft_strcmp(input->content, "pa") == 0
			|| ft_strcmp(input->content, "pb") == 0
			|| ft_strcmp(input->content, "ra") == 0
			|| ft_strcmp(input->content, "rb") == 0
			|| ft_strcmp(input->content, "rr") == 0
			|| ft_strcmp(input->content, "rra") == 0
			|| ft_strcmp(input->content, "rrb") == 0
			|| ft_strcmp(input->content, "rrr") == 0)
			input = input->next;
		else
			return (-1);
	}
	return (0);
}

int	instructions(t_list **input, t_list **stack_a, t_list **stack_b)
{
	if (valid_instructions(*input) == -1)
	{
		printf("\033[31mError: invalid instruction(s)\033[0m\n");
		return (-1);
	}
	while (*input)
	{
		if (*((char *)((*input)->content)) == 's')
			swaps((*input)->content, stack_a, stack_b);
		else if (*((char *)((*input)->content)) == 'p')
			pushes((*input)->content, stack_a, stack_b);
		else if (*((char *)((*input)->content)) == 'r')
			rotates((*input)->content, stack_a, stack_b);
		*input = (*input)->next;
	}
	return (0);
}
