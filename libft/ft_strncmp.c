/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 14:00:46 by iboeters       #+#    #+#                */
/*   Updated: 2019/11/25 12:45:44 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str, const char *str2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (i + 1 < n && str[i] == str2[i] && str[i] != '\0' && str2[i] != '\0')
	{
		i++;
	}
	return ((unsigned char)str[i] - str2[i]);
}
