/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:16:02 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/20 19:27:07 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_ps_list **lst)
{
	t_ps_list	*first;
	t_ps_list	*temp;

	if (!*lst || (*lst)->next == NULL)
		return ;
	first = *lst;
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->prev = NULL;
	temp->next = first;
	first->prev = temp;
	*lst = temp;
}

void	rra(t_ps_list **a)
{
	reverse_rotate(a);
}

void	rrb(t_ps_list **b)
{
	reverse_rotate(b);
}

void	rrr(t_ps_list **a, t_ps_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
