/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/01 19:29:52 by iboeters      #+#    #+#                 */
/*   Updated: 2021/05/03 20:11:14 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	atoi_ret(char c, int sign, unsigned int r, int *error)
{
	if (c != '\0')
	{
		*error = 1;
		return (-1);
	}
	return ((int)sign * r);
}

int	atoi_check(const char *str, int *error)
{
	unsigned int	r;
	int				i;
	int				sign;

	r = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		if ((sign == 1 && r > (unsigned)INT_MAX)
			|| (sign == -1 && r > (unsigned)INT_MAX + 1))
		{
			*error = 1;
			return (-1);
		}
		i++;
	}
	return (atoi_ret(str[i], sign, r, error));
}

void	print_lst_item(void *str)
{
	printf("%s\n", str);
}

void	save_instructions(t_list **input)
{
	int		ret;
	char	*str;

	ret = 1;
	while (ret >= 1)
	{
		ret = get_next_line(0, &str);
		if (ret != 1)
			break ;
		ft_lstadd_back(input, ft_lstnew(str));
	}
	printf("list content:\n");
	ft_lstiter(*input, print_lst_item);
}

int	save_input(int argc, char **argv, t_stack *stack, t_list **input)
{
	int	error;
	int	i;

	error = 0;
	i = 1;
	while (error == 0 && argv[i])
	{
		(*stack).arr[i - 1] = atoi_check(argv[i], &error);
		i++;
	}
	if (error == 1)
	{
		printf("\033[31mError: invalid input\033[0m\n");
		return (1);
	}
	(*stack).size = i - 1;
	printf("\033[32mvalid input\033[0m\n");
	save_instructions(input);
	return (0);
}
