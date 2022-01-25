/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_funs_2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 14:40:37 by iboeters      #+#    #+#                 */
/*   Updated: 2022/01/25 16:56:38 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_lst	*lstnew(void *content)
{
	t_lst	*lst;

	lst = (t_lst *)malloc(sizeof(t_lst));
	if (!lst)
		return (0);
	lst->content = content;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

int	lstsize(t_lst *lst)
{
	int	len;

	len = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
