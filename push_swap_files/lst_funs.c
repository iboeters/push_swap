/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_funs.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/17 13:25:06 by iboeters      #+#    #+#                 */
/*   Updated: 2021/05/18 21:01:14 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstadd_back(t_lst **lst, t_lst *new)
{
	t_lst	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		(*lst)->prev = *lst;
		return ;
	}
	tmp = lstlast(*lst);
	new->prev = tmp;
	tmp->next = new;
	(*lst)->prev = tmp->next;
}

void	lstadd_front(t_lst **lst, t_lst *new)
{
	t_lst	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		(*lst)->prev = *lst;
		(*lst)->next = NULL;
		return ;
	}
	tmp = (*lst)->prev;
	(*lst)->prev = new;
	new->prev = tmp;
	new->next = *lst;
	*lst = new;
}

void	lstclear(t_lst **lst, void (*del)(void*))
{
	t_lst	*ptr;
	t_lst	*tmp;

	if (!*lst)
		return ;
	ptr = *lst;
	while (ptr)
	{
		tmp = ptr->next;
		del(ptr->content);
		free(ptr);
		ptr = tmp;
	}
	*lst = NULL;
}

void	lstiter(t_lst *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_lst	*lstlast(t_lst *lst)
{
	if (!lst)
		return (0);
	return (lst->prev);
}

t_lst		*lstnew(void *content)
{
	t_lst *lst;

	lst = (t_lst *)malloc(sizeof(t_lst));
	if (!lst)
		return (0);
	lst->content = content;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

int		lstsize(t_lst *lst)
{
	int len;

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