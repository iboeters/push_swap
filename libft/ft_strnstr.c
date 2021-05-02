/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 14:40:33 by iboeters       #+#    #+#                */
/*   Updated: 2019/11/26 09:39:03 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	mem;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char*)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		mem = i;
		while (haystack[i] == needle[j] && haystack[i] != '\0' && i < len)
		{
			if (needle[j + 1] == '\0')
				return ((char*)haystack + i - j);
			i++;
			j++;
		}
		j = 0;
		i = mem + 1;
	}
	return (0);
}
