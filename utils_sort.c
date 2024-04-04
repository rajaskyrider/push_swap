/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:47:18 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/04 20:56:08 by rpandipe         ###   ########.fr       */
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
	int		count;

	temp = *a;
	count = 0;
	while(temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

t_result *ft_last(t_result **result)
{
	t_result	*temp;

	temp = *result;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	adjust_b(t_result **result, t_result *start)
{
	int		len;
	char	*str;
	(void) result;

	start = start->next;
	while (start)
	{
		len = ft_strlen(start->op) - 1;
		if (start->op[len] == 'a')
		{
			str = ft_calloc(len + 2,  sizeof(char));
			ft_strlcpy(str, start->op, len +2);
			start->op = str;
			start->op[len] = 'b'; 
		}
		else if (start->op[len] == 'b')
		{
			str = ft_calloc(len + 2,  sizeof(char));
			ft_strlcpy(str, start->op, len +2);
			start->op = str;
			start->op[len] = 'a';
		}
		start = start->next;
	}
}
