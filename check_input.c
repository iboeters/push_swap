/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/01 19:29:52 by iboeters      #+#    #+#                 */
/*   Updated: 2021/05/02 19:45:35 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	atoi_ret(char c, int sign, unsigned int r, int *error)
{
	if (c != '\0')
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
		if ((sign == 1 && r > (unsigned)INT_MAX)
			|| (sign == -1 && r > (unsigned)INT_MAX + 1))
		{
			*error = 1;
			return (-1);
		}
		i++;
	}
	return (atoi_ret(str[i], sign, r, error));
}

int	check_input(int argc, char **argv)
{
	int	error;
	int	i;

	error = 0;
	i = 1;
	while (error == 0 && argv[i])
	{
		printf("%i\n", atoi_check(argv[i], &error));
		i++;
	}
	if (error == 1)
	{
		printf("\033[31minvalid input\n\033[0m");
		return (1);
	}
	printf("\033[32mvalid input\n\033[0m");
	return (0);
}
