/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 09:36:14 by iboeters       #+#    #+#                */
/*   Updated: 2019/11/21 10:41:25 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			count_words(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			j++;
		while (s[i] != c && s[i] != 0)
			i++;
	}
	return (j);
}

static const char	*begin_word(char const *s, char c)
{
	while (*s == c)
		s++;
	return (s);
}

static int			len_word(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static void			ft_free(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char				**ft_split(char const *s, char c)
{
	char	**split;
	int		n_words;
	int		i;
	int		len;

	i = 0;
	if (s == 0)
		return (0);
	n_words = count_words(s, c);
	split = (char**)malloc((n_words + 1) * sizeof(char*));
	if (!split)
		return (0);
	while (i < n_words)
	{
		s = begin_word(s, c);
		len = len_word(s, c);
		split[i] = ft_substr(s, 0, len);
		if (!split[i])
			ft_free(split);
		s = s + len;
		i++;
	}
	split[i] = 0;
	return (split);
}
