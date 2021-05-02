/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 13:53:34 by iboeters       #+#    #+#                */
/*   Updated: 2019/11/25 13:44:49 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str = (unsigned char*)src;
	str2 = (unsigned char*)dst;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
		{
			str2[i] = str[i];
			return (&str2[i + 1]);
		}
		else
			str2[i] = str[i];
		i++;
	}
	return (0);
}
