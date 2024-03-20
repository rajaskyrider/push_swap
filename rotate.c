/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:02:21 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/20 19:26:50 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_ps_list **lst)
{
	t_ps_list	*end;
	t_ps_list	*temp;

	if (!*lst || (*lst)->next == NULL)
		return ;
	end = *lst;
	temp = *lst;
	while (end->next != NULL)
		end = end->next;
	end->prev = NULL;
	end->next = temp;
	temp->prev = end;
	*lst = end;
}

void	ra(t_ps_list **a)
{
	rotate(a);
}

void	rb(t_ps_list **b)
{
	rotate(b);
}

void	rr(t_ps_list **a, t_ps_list **b)
{
	ra(a);
	rb(b);
}
