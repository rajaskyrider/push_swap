/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:41:18 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/26 19:49:48 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	push(t_ps_list **destinationlist, t_ps_list **sourcelist)
{
	t_ps_list	*temp;

	if (*sourcelist == NULL)
		return (false);
	temp = *sourcelist;
	*sourcelist = (*sourcelist)->next;
	if (*sourcelist)
		(*sourcelist)->prev = NULL;
	if (*destinationlist)
		(*destinationlist)->prev = temp;
	temp->next = *destinationlist;
	(*destinationlist) = temp;
	return (true);
}

void	pa(t_ps_list **a, t_ps_list **b, t_result **result, int id)
{
	if (push(a, b))
		addentry(result, "pa", id);
}

void	pb(t_ps_list **a, t_ps_list **b, t_result **result, int id)
{
	if (push(b, a))
		addentry(result, "pb", id);
}
