/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 12:46:27 by iboeters      #+#    #+#                 */
/*   Updated: 2022/01/25 14:37:37 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*str;
	char		*str2;

	str = (char *)src;
	str2 = (char *)dst;
	if ((str == NULL) && (str2 == NULL))
		return (dst);
	while (n > 0)
	{
		str2[n - 1] = str[n - 1];
		n--;
	}
	return (dst);
}
