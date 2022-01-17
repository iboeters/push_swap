#include "checker.h"

// can be deleted if not used
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
		ret = get_next_line(STDIN_FILENO, &str);
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
		write(STDERR_FILENO, "Error\n", ft_strlen("Error\n"));
		if (str)
			free(str);
		return (1);
	}
	return (0);
}
