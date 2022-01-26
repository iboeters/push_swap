/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 13:05:46 by iboeters      #+#    #+#                 */
/*   Updated: 2022/01/26 12:07:02 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ret_free(char *s1)
{
	if (s1)
		free(s1);
	return (0);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;
	size_t	i;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (ret_free(s1));
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		str[i] = s2[i - len1];
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

int	gnl_strchr(const char *s, int c)
{
	char	*str;
	char	a;
	int		i;

	str = (char *)s;
	a = c;
	i = 0;
	while (str[i] != a)
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

void	*gnl_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	i;
	char	*str2;

	i = 0;
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	str = (void *)malloc(count * size);
	if (!str)
		return (0);
	str2 = (char *)str;
	while (i < count * size)
	{
		str2[i] = '\0';
		i++;
	}
	return (str);
}

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	len2;

	i = 0;
	len2 = ft_strlen(s);
	if (!s)
		return (0);
	if (start > len2)
		return (gnl_calloc(1, sizeof(char)));
	if (start + len > len2)
		str = (char *)malloc(sizeof(char) * (len2 - start) + 2);
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
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
