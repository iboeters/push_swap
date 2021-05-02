/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 15:09:17 by iboeters       #+#    #+#                */
/*   Updated: 2020/03/28 15:10:42 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*str;
	char		*str2;
	size_t		i;

	i = 0;
	str = (char *)src;
	str2 = (char *)dst;
	if ((str == NULL) && (str2 == NULL))
		return (dst);
	if (dst < src)
	{
		while (i < len)
		{
			str2[i] = str[i];
			i++;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
