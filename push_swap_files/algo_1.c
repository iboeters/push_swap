#include "push_swap.h"

int		low_closest(int low_index, int high_index, int len)
{
	int path_low;
	int	path_high;

	path_low = low_index;
	if (len - low_index < path_low)
		path_low = len - low_index;
	path_high = high_index;
	if (len - high_index < path_high)
		path_high = len - high_index;
	// printf("path_low=%d|path_high=%d\n", path_low, path_high);
	if (path_low <= path_high)
		return (1);
	return (0);
}

void	push_first(t_lst **stack_1, t_lst **stack_2, int first_index, const int len, char ab)
{
	int i;
	int j;
	char other;

	i = 0;
	j = 0;
	if (ab == 'a')
		other = 'b';
	else
		other = 'a';
	if (first_index > len / 2)
	{
		while (i < len - first_index)
		{
			reverse_rotate(stack_1, ab, 1);
			// printf("1.i[%d]lf[%d]-----------\n", i, len - first_index);
			// lstiter(*stack_1, print_lst_num);
			// printf("-----------\n");
			// lstiter(*stack_2, print_lst_num);
			// printf("-----------\n\n");
			i++;
		}
		push(stack_2, stack_1, other, 1);
		while (j < i - 1)
		{
			rotate(stack_1, ab, 1);
			// printf("2.j[%d]i[%d]-----------\n", j, i);
			// printf("a-----------\n");
			// lstiter(*stack_1, print_lst_num);
			// printf("-----------\n");
			// lstiter(*stack_2, print_lst_num);
			// printf("-----------\n\n");
			j++;
		}
	}
	else if (first_index <= len / 2)
	{
		while (i < first_index)
		{
			rotate(stack_1, ab, 1);
			// printf("3.i[%d]f[%d]-----------\n", i, first_index);
			// lstiter(*stack_1, print_lst_num);
			// printf("-----------\n");
			// lstiter(*stack_2, print_lst_num);
			// printf("-----------\n\n");
			i++;
		}
		push(stack_2, stack_1, other, 1);
		while (j < i)
		{
			reverse_rotate(stack_1, ab, 1);
			// printf("4.j[%d]i[%d]-----------\n", j, i);
			// lstiter(*stack_1, print_lst_num);
			// printf("-----------\n");
			// lstiter(*stack_2, print_lst_num);
			// printf("-----------\n\n");
			j++;
		}
	}
}

void	push_second(t_lst **stack_1, t_lst **stack_2, int second_index, const int len, char ab)
{
	int i;
	int j;
	char other;

	i = 0;
	j = 0;
	if (ab == 'a')
		other = 'b';
	else
		other = 'a';
	// printf("len=%d, len/2=%d, second_ind=%d\n", len, len/2, second_index);
	if (second_index > len / 2) // 3 >= 2
	{
		while (i < len - second_index) // 0 < (3 - 2)
		{
			reverse_rotate(stack_1, ab, 1);
			// printf("5.i[%d]ls[%d]-----------\n", i, len - second_index);
			// lstiter(*stack_1, print_lst_num);
			// printf("-----------\n");
			// lstiter(*stack_2, print_lst_num);
			// printf("-----------\n\n");
			i++;
		}
		push(stack_2, stack_1, other, 1);
		while (j < i - 1) //soms wel, soms niet -1
		{
			rotate(stack_1, ab, 1);
 			// printf("6.j[%d]i[%d]-----------\n", j, i);
			// lstiter(*stack_1, print_lst_num);
			// printf("-----------\n");
			// lstiter(*stack_2, print_lst_num);
			// printf("-----------\n\n");
			j++;
		}
	}
	else if (second_index <= len / 2)
	{
		while (i < second_index)
		{
			rotate(stack_1, ab, 1);
			// printf("7.i[%d]s[%d]-----------\n", i, second_index);
			// lstiter(*stack_1, print_lst_num);
			// printf("-----------\n");
			// lstiter(*stack_2, print_lst_num);
			// printf("-----------\n\n");
			i++;
		}
		push(stack_2, stack_1, other, 1);
		while (j < i)
		{
			reverse_rotate(stack_1, ab, 1);
			// printf("8.j[%d]i[%d]-----------\n", j, i);
			// lstiter(*stack_1, print_lst_num);
			// printf("-----------\n");
			// lstiter(*stack_2, print_lst_num);
			// printf("-----------\n\n");
			j++;
		}
	}
}

unsigned int	get_index(t_lst **stack_1, unsigned int num)
{
	unsigned int index;
	t_lst	*tmp;

	index = 0;
	tmp = *stack_1;
	while (*stack_1)
	{
		if (*(unsigned int *)(*stack_1)->content == num)
		{
			*stack_1 = tmp;
			return (index);
		}
		*stack_1 = (*stack_1)->next;
		index++;
	}
	*stack_1 = tmp;
	return (0);
}

int	push_low_high_b(t_lst **stack_1, t_lst **stack_2, int len_tot, int len, char ab)
{
	int low_index;
	int high_index;

	// printf("%i|%i|%i\n", len, low_index, high_index);
	low_index = get_index(stack_1, 0);
	high_index = get_index(stack_1, len_tot / 2 - 1);
	if (low_index == len - 1 && high_index == 0)
		return (0);
	if (low_closest(low_index, high_index, len))
	{
		push_first(stack_1, stack_2, low_index, len, ab);
		high_index = get_index(stack_1, len_tot / 2 - 1);
		len--;
		push_second(stack_1, stack_2, high_index, len, ab);
	}
	else
	{
		push_first(stack_1, stack_2, high_index, len, ab);
		low_index = get_index(stack_1, 0);
		len--;
		push_second(stack_1, stack_2, low_index, len, ab);
	}
	return (1);
}

int	push_low_high_a(t_lst **stack_1, t_lst **stack_2, int len_tot, int len, char ab)
{
	int low_index;
	int high_index;

	low_index = get_index(stack_1, len_tot / 2);
	high_index = get_index(stack_1, len_tot - 1);
	// printf("%i|%i|%i\n", len, low_index, high_index);
	if (low_index == 0 && high_index == len - 1)
		return (0);
	if (low_closest(low_index, high_index, len))
	{
		push_first(stack_1, stack_2, low_index, len, ab);
		high_index = get_index(stack_1, len_tot - 1);
		len--;
		push_second(stack_1, stack_2, high_index, len, ab);
	}
	else
	{
		push_first(stack_1, stack_2, high_index, len, ab);
		low_index = get_index(stack_1, len_tot / 2);
		len--;
		push_second(stack_1, stack_2, low_index, len, ab);
	}
	return (1);
}


int	algo_1(t_lst **stack_a, t_lst **stack_b)
{
	int	len;
	int len_tot;
	int	ret;

	len_tot = lstsize(*stack_a);
	if (sorted(*stack_a)) // if already sorted-> return
		return (0);
	pre_sorting(stack_a, stack_b, len_tot);
	ret = push_low_high_a(stack_a, stack_b, len_tot, lstsize(*stack_a), 'a');
	if (*stack_b && *(int *)((*stack_b)->content) > *(int *)(((*stack_b)->next)->content) && ret)
		swap(stack_b, 'b', 1);
	if (*stack_b && ret)
	{
		push(stack_a, stack_b, 'a', 1);
		push(stack_a, stack_b, 'a', 1);
		rotate(stack_a, 'a', 1);
	}
	// printf("-----------\n");
	// lstiter(*stack_a, print_lst_num);
	// printf("-----------\n");
	// lstiter(*stack_b, print_lst_num);
	// printf("-----------\n");
	// printf("index highest b:%d\n", get_index(stack_b, len_tot / 2 - 1));
	// printf("index lowest b:%d|%d\n", get_index(stack_b, 0), lstsize(*stack_b));
	ret = push_low_high_b(stack_b, stack_a, len_tot, lstsize(*stack_b), 'b');
	if (*stack_a && *(int *)((*stack_a)->content) < *(int *)(((*stack_a)->next)->content) && ret)
		swap(stack_a, 'a', 1);
	if (*stack_a && ret)
	{
		push(stack_b, stack_a, 'b', 1);
		push(stack_b, stack_a, 'b', 1);
		rotate(stack_b, 'b', 1);
	}
	// printf("stack_a:\n");
	// lstiter(*stack_a, print_lst_num);
	// printf("stack_b:\n");
	// lstiter(*stack_b, print_lst_num);
	// printf("----------solve----------\n");
	len = lstsize(*stack_a);
	algo_1_solver(stack_a, stack_b, len);
	// printf("stack_a:\n");
	// lstiter(*stack_a, print_lst_num);
	// printf("stack_b:\n");
	// lstiter(*stack_b, print_lst_num);
	return (0);
}
