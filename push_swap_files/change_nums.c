/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   change_nums.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: iris <iris@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 18:08:13 by iris          #+#    #+#                 */
/*   Updated: 2021/06/30 22:27:36 by iris          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    change_stack(int *arr, t_lst *stack_a, int len)
{
	int	i;

	while (stack_a)
	{
		i = 0;
		while (i < len)
		{
			if (*(int *)(stack_a)->content == arr[i])
				*(int *)stack_a->content = arr[i];
			i++;
		}
		stack_a = (stack_a)->next;
	}
}

void    swap_arr(int *arr, int j)
{
    int tmp;

    tmp = arr[j];
    arr[j] = arr[j + 1];
    arr[j + 1] = tmp;
}

void    bubble_sort_arr(int *arr, int len)
{
    int swapped;
    int i;
    int j;

    i = 0;
    j = 0;
    swapped = 1;
    while (swapped == 1 && len - i > 1)
    {
        swapped = 0;
        j = 0;
        while (j < len - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                swap_arr(arr, j);
				swapped = 1;
            }
            j++;
        }
        i++;
    }
}

void    fill_arr(int *arr, t_lst *stack_a)
{
    int i;

    i = 0;
    while (stack_a)
    {
        arr[i] = *(int *)stack_a->content;
        stack_a = stack_a->next;
        i++;
    }
}

int change_nums(t_lst *stack_a)
{
    int len;
    int *arr;
    int *arr_index;

    len = lstsize(stack_a);
    arr = (int *)malloc((sizeof(int) * len + 1));
    arr_index = (int *)malloc((sizeof(int) * len + 1));
    if (!arr || !arr_index)
        return (1);
    fill_arr(arr, stack_a);
    bubble_sort_arr(arr, len);
    change_stack(arr, stack_a, len);
	// printf("newstack:\n");
	// lstiter(stack_a, print_lst_num);
    if (arr)
        free(arr);
	if (arr_index)
		free(arr_index);
	return (0); // return(0) vergeten --> nog leaks
}
