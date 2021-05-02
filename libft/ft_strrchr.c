/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 14:01:56 by iboeters       #+#    #+#                */
/*   Updated: 2019/11/25 12:43:09 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	a;
	int		len;

	str = (char *)s;
	a = c;
	len = ft_strlen(s);
	while (str[len] != a)
	{
		if (len == 0)
			return (0);
		len--;
	}
	return (&str[len]);
}
