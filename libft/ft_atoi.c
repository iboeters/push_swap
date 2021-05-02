/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 14:20:41 by iboeters      #+#    #+#                 */
/*   Updated: 2021/05/01 19:29:34 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long int	r;
	int					i;
	int					sign;
	unsigned long int	max_int;

	r = 0;
	i = 0;
	sign = 1;
	max_int = 922337203685477580;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (sign == 1 && ((r == max_int && str[i] > '7') || (r > max_int)))
			return (-1);
		if (sign == -1 && ((r == max_int && str[i] > '8') || (r > max_int)))
			return (0);
		r = r * 10 + str[i] - '0';
		i++;
	}
	return (sign * r);
}
