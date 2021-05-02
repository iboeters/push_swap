/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 12:11:28 by iboeters       #+#    #+#                */
/*   Updated: 2019/11/15 17:37:42 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_nbr(int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		while (n / 10 < 0)
		{
			n = n / 10;
			i++;
		}
		i++;
	}
	else
	{
		while (n / 10 > 0)
		{
			n = n / 10;
			i++;
		}
	}
	i++;
	return (i);
}

static int	ft_negative(char *str, int n)
{
	int		min_int;

	min_int = -2147483648;
	str[0] = '-';
	if (n == min_int)
	{
		str[1] = '2';
		n = 147483648;
	}
	else
		n = -n;
	return (n);
}

char		*ft_itoa(int n)
{
	int		stop;
	int		len;
	char	*str;

	stop = 0;
	len = len_nbr(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (n < 0)
		stop = 1;
	if (n == -2147483648)
		stop = 2;
	if (n < 0)
		n = ft_negative(str, n);
	str[len] = '\0';
	len--;
	while (len >= stop)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (str);
}
