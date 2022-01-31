/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 14:54:13 by iboeters      #+#    #+#                 */
/*   Updated: 2022/01/26 15:14:30 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	return_value(int error)
{
	if (error == 1)
	{
		write(STDERR_FILENO, "Error\n", ft_strlen("Error\n"));
		return (1);
	}
	return (0);
}

static int	atoi_ret(const char *str, int i, unsigned int r, int *error)
{
	int	j;

	j = 0;
	if (str[i] != '\0' || ft_strlen(str) == 0)
	{
		*error = 1;
		return (-1);
	}
	while (str[j] == ' ' || (str[j] >= 9 && str[j] <= 13))
		j++;
	if (str[j] == '\0')
	{
		*error = 1;
		return (-1);
	}
	return (r);
}

static int	atoi_check(const char *str, int *error)
{
	unsigned int	r;
	int				i;
	int				sign;

	r = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		if ((sign == 1 && (sign * r) > (unsigned)INT_MAX)
			|| (sign == -1 && (sign * r) < (unsigned)INT_MIN))
		{
			*error = 1;
			return (-1);
		}
		i++;
	}
	return (sign * atoi_ret(str, i, r, error));
}

static int	add_back(t_lst **stack_a, int **num, char *argv, int *error)
{
	t_lst	*new_list;

	*num = (int *)malloc(sizeof(int) * 1);
	if (!*num)
		return (1);
	**num = atoi_check(argv, error);
	new_list = lstnew(*num);
	if (!new_list)
	{
		if (*num)
			free(*num);
		return (1);
	}
	lstadd_back(stack_a, new_list);
	return (0);
}

int	save_input(int argc, char **argv, t_lst **stack_a)
{
	int		error;
	t_lst	*tmp_addr;
	t_lst	*last;
	int		i;
	int		*num;

	error = 0;
	i = 1;
	while (error == 0 && argv[i])
	{
		if (add_back(stack_a, &num, argv[i], &error))
			return (return_value(1));
		last = lstlast(*stack_a);
		tmp_addr = last;
		last = last->prev;
		while (last != tmp_addr)
		{
			if (*(int *)last->content == *num)
				return (return_value(1));
			last = last->prev;
		}
		i++;
	}
	return (return_value(error));
}
