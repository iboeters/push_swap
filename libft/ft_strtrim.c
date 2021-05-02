/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 15:13:59 by iboeters       #+#    #+#                */
/*   Updated: 2019/11/21 10:10:54 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_start(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	size_t	point1;

	i = 0;
	point1 = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				point1++;
				break ;
			}
			j++;
			if (set[j] == '\0')
				return (point1);
		}
		i++;
	}
	return (point1);
}

static size_t	find_end(const char *s1, const char *set)
{
	int		i;
	size_t	j;
	size_t	point2;

	i = ft_strlen(s1) - 1;
	point2 = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				point2--;
				break ;
			}
			j++;
			if (set[j] == '\0')
				return (point2);
		}
		i--;
	}
	return (point2);
}

char			*ft_strtrim(const char *s1, const char *set)
{
	size_t	point1;
	size_t	point2;
	char	*trim;

	if (!s1 || !set)
		return (0);
	point1 = find_start(s1, set);
	if (point1 == ft_strlen(s1))
	{
		point2 = 0;
		trim = ft_strdup("");
		return (trim);
	}
	else
		point2 = find_end(s1, set);
	trim = (char*)malloc(sizeof(char) * (point2 - point1 + 2));
	if (!trim)
		return (0);
	ft_memcpy(trim, s1 + point1, point2 - point1 + 1);
	trim[point2 - point1 + 1] = '\0';
	return (trim);
}
