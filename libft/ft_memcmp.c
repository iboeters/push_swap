/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 12:06:07 by iboeters       #+#    #+#                */
/*   Updated: 2019/11/25 14:09:22 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str;
	const unsigned char	*str2;
	size_t				i;

	if (n == 0)
		return (0);
	str = s1;
	str2 = s2;
	i = 0;
	while (str[i] == str2[i] && i + 1 < n)
		i++;
	return ((int)str[i] - str2[i]);
}
