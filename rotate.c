/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:02:21 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/26 19:16:25 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	rotate(t_ps_list **lst)
{
	t_ps_list	*end;
	t_ps_list	*temp;

	if (!*lst || (*lst)->next == NULL)
		return (false);
	end = *lst;
	temp = *lst;
	while (end->next != NULL)
		end = end->next;
	end->prev = NULL;
	end->next = temp;
	temp->prev = end;
	*lst = end;
	return (true);
}

void	ra(t_ps_list **a, t_result **result, int id)
{
	if (rotate(a))
		addentry(result, "ra", id);
}

void	rb(t_ps_list **b, t_result **result, int id)
{
	if (rotate(b))
		addentry(result, "rb", id);
}

void	rr(t_ps_list **a, t_ps_list **b, t_result **result, int id)
{
	if (rotate(a) && rotate(b))
		addentry(result, "rr", id);
}
