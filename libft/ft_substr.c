/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 09:29:26 by iboeters       #+#    #+#                */
/*   Updated: 2020/01/15 17:05:21 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	len2;

	i = 0;
	if (!s)
		return (0);
	len2 = ft_strlen(s);
	if (start > len2)
		return (ft_strdup(""));
	if (start + len > len2)
		str = (char*)malloc(sizeof(char) * (len2 - start) + 1);
	else
		str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (i < len && s[i] != '\0')
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
