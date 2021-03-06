/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 14:33:51 by iboeters      #+#    #+#                 */
/*   Updated: 2022/01/25 16:56:23 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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
	return (str[i] - str2[i]);
}

int	valid_instructions(t_lst *input)
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
			return (1);
	}
	return (0);
}

int	instructions(t_lst *input, t_lst **stack_a, t_lst **stack_b)
{
	if (valid_instructions(input) == 1)
	{
		write(STDERR_FILENO, "Error\n", ft_strlen("Error\n"));
		return (1);
	}
	while (input)
	{
		if (*((char *)(input->content)) == 's')
			swaps(input->content, stack_a, stack_b, 0);
		else if (*((char *)(input->content)) == 'p')
			pushes(input->content, stack_a, stack_b, 0);
		else if (*((char *)(input->content)) == 'r')
			rotates(input->content, stack_a, stack_b, 0);
		input = input->next;
	}
	return (0);
}
