/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/01 19:29:52 by iboeters      #+#    #+#                 */
/*   Updated: 2021/05/16 23:08:00 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	atoi_ret(const char *str, int i, int sign, unsigned int r, int *error)
{
	if (str[i] != '\0' || ft_strlen(str) == 0)
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
		if ((sign == 1 && (sign * r) > (unsigned)INT_MAX)
			|| (sign == -1 && (sign * r) < (unsigned)INT_MIN))
		{
			*error = 1;
			return (-1);
		}
		i++;
	}
	return (atoi_ret(str, i, sign, r, error));
}

void	print_lst_str(void *str)
{
	printf("%s\n", (char *)str);
}

void	print_lst_num(void *num)
{
	printf("%i\n", *((int *)num));
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
	// printf("input:\n");
	// ft_lstiter(*input, print_lst_str);
}

int	save_input(int argc, char **argv, t_list **stack_a, t_list **input)
{
	int	error;
	t_list	*tmp_addr;
	t_list	*neww;
	int	i;
	int *num;

	error = 0;
	i = 1;
	while (error == 0 && argv[i])
	{
		num = (int *)malloc(sizeof(int) * 1);
		*num = atoi_check(argv[i], &error);
		ft_lstadd_back(stack_a, ft_lstnew(num));
		tmp_addr = *stack_a;
		while ((*stack_a)->next != NULL)
		{
			if (*(int *)(*stack_a)->content == *num)
			{
				printf("\033[31mError: duplicate arguments|%i|\033[0m\n", *num);
				return (1);
			}
			*stack_a = (*stack_a)->next;
		}
		*stack_a = tmp_addr;
		i++;
	}
	if (error == 1)
	{
		printf("\033[31mError: invalid input\033[0m\n");
		return (1);
	}
	printf("\033[32mvalid input\033[0m\n");
	save_instructions(input);
	return (0);
}
