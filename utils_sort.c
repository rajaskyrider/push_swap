/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:47:18 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/26 18:53:13 by rpandipe         ###   ########.fr       */
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
