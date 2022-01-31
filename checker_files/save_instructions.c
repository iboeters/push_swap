/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_instructions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 14:34:45 by iboeters      #+#    #+#                 */
/*   Updated: 2022/01/26 14:23:07 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	error_return(void)
{
	write(STDERR_FILENO, "Error\n", ft_strlen("Error\n"));
	return (1);
}

static void	free_str(char *str)
{
	if (str)
		free(str);
}

int	save_instructions(t_lst **input)
{
	int		ret;
	char	*str;
	t_lst	*new_list;

	ret = 1;
	while (ret >= 1)
	{
		ret = get_next_line(STDIN_FILENO, &str);
		if (ret != 1)
		{
			free_str(str);
			break ;
		}
		new_list = lstnew(str);
		if (!new_list)
		{
			free_str(str);
			return (error_return());
		}
		lstadd_back(input, new_list);
	}
	if (ret == -1)
		return (error_return());
	return (0);
}
