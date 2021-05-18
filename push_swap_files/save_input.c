/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/01 19:29:52 by iboeters      #+#    #+#                 */
/*   Updated: 2021/05/18 21:00:50 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	atoi_ret(const char *str, int i, int sign, unsigned int r, int *error)
{
	if (str[i] != '\0' || ft_strlen(str) == 0)
	{
		*error = 1;
		return (-1);
	}
	return ((int)sign * r);
}

int	atoi_check(const char *str, int *error)
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
	return (atoi_ret(str, i, sign, r, error));
}

int	save_input(int argc, char **argv, t_lst **stack_a)
{
	int	error;
	t_lst	*tmp_addr;
	t_lst	*last;
	int	i;
	int *num;

	error = 0;
	i = 1;
	while (error == 0 && argv[i])
	{
		num = (int *)malloc(sizeof(int) * 1);
		*num = atoi_check(argv[i], &error);
		lstadd_back(stack_a, lstnew(num));
		last = lstlast(*stack_a);
		tmp_addr = last;
		last = last->prev;
		while (last != tmp_addr)
		{
			if (*(int *)last->content == *num)
			{
				printf("\033[31mError: duplicate arguments number:|%i|\033[0m\n", *num);
				return (1);
			}
			last = last->prev;
		}
		i++;
	}
	if (error == 1)
	{
		printf("\033[31mError: invalid argument(s)\033[0m\n");
		return (1);
	}
	printf("\033[32mvalid argument(s)\033[0m\n");
	return (0);
}