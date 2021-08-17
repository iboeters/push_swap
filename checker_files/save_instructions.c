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
		write(2, "Error\n", 7);
		if (str)
			free(str);
		return (1);
	}
	return (0);
}
