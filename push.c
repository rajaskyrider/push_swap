/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:41:18 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/20 19:26:10 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_ps_list **destinationlist, t_ps_list **sourcelist)
{
	t_ps_list	*temp;

	if (*sourcelist == NULL)
		return ;
	temp = *sourcelist;
	temp->prev = NULL;
	temp->next = *destinationlist;
	(*destinationlist)->prev = temp;
	(*destinationlist) = temp;
	*sourcelist = (*sourcelist)->next;
}

void	pa(t_ps_list **a, t_ps_list **b)
{
	push(a, b);
}

void	pb(t_ps_list **a, t_ps_list **b)
{
	push(b, a);
}
