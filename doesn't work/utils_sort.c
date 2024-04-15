/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:47:18 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/09 00:19:55 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_result	*createentry(char *op, int id)
{
	t_result	*entry;

	entry = (t_result *)ft_calloc(1, sizeof(t_result));
	if (!entry)
		exit(0);
	entry->id = id;
	entry->op = op;
	entry->next = NULL;
	return (entry);
}

void	addentry(t_result **result, char *op, int id)
{
	t_result	*lst;

	if (*result == NULL)
	{
		*result = createentry(op, id);
		return ;
	}
	lst = *result;
	while (lst->next)
	{
		lst = lst->next;
	}
	lst->next = createentry(op, id);
}

int	ft_list_count(t_ps_list **a)
{
	t_ps_list	*temp;
	int			count;

	temp = *a;
	count = 0;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

t_result	*ft_last(t_result **result)
{
	t_result	*temp;

	temp = *result;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

int	last_n(t_ps_list **b)
{
	t_ps_list	*temp;

	temp = *b;
	while(temp->next)
		temp = temp->next;
	return (temp->n);
}
