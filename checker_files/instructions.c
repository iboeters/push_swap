#include "checker.h"

int	ft_strcmp(const char *str, const char *str2)
{
	int	i;

	i = 0;
	while (str[i] == str2[i] && str[i] != '\0' && str2[i] != '\0')
	{
		i++;
	}
	if (str[i] == '\0' && str2[i] == '\0')
		return (0);
	return (str[i] - str2[i]);
}

int	valid_instructions(t_lst *input)
{
	while (input)
	{
		if (ft_strcmp(input->content, "sa") == 0
			|| ft_strcmp(input->content, "sb") == 0
			|| ft_strcmp(input->content, "ss") == 0
			|| ft_strcmp(input->content, "pa") == 0
			|| ft_strcmp(input->content, "pb") == 0
			|| ft_strcmp(input->content, "ra") == 0
			|| ft_strcmp(input->content, "rb") == 0
			|| ft_strcmp(input->content, "rr") == 0
			|| ft_strcmp(input->content, "rra") == 0
			|| ft_strcmp(input->content, "rrb") == 0
			|| ft_strcmp(input->content, "rrr") == 0)
			input = input->next;
		else
			return (1);
	}
	return (0);
}

int	instructions(t_lst *input, t_lst **stack_a, t_lst **stack_b)
{
	if (valid_instructions(input) == 1)
	{
		write(STDERR_FILENO, "Error\n", ft_strlen("Error\n"));
		return (1);
	}
	while (input)
	{
		// printf("action= [%s]\n", (char *)input->content);
		if (*((char *)(input->content)) == 's')
			swaps(input->content, stack_a, stack_b, 0);
		else if (*((char *)(input->content)) == 'p')
			pushes(input->content, stack_a, stack_b, 0);
		else if (*((char *)(input->content)) == 'r')
			rotates(input->content, stack_a, stack_b, 0);
		// printf("stack_a:\n");
		// lstiter(*stack_a, print_lst_num);
		// printf("stack_b:\n");
		// lstiter(*stack_b, print_lst_num);
		input = input->next;
	}
	return (0);
}
