/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_instructions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/18 11:33:08 by iboeters      #+#    #+#                 */
/*   Updated: 2021/05/18 11:38:27 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_lst_str(void *str)
{
	printf("%s\n", (char *)str);
}

int	save_instructions(t_lst **input)
{
	int		ret;
	char	*str;

	ret = 1;
	while (ret >= 1)
	{
		ret = get_next_line(0, &str);
		if (ret != 1)
		{
			if (str)
				free(str);
			break ;
		}
		lstadd_back(input, lstnew(str));
	}
	if (ret == -1)
	{
		printf("Error: reading instructions\n");
		return (1);
	}
	printf("input:\n");
	lstiter(*input, print_lst_str);
	return (0);
}
