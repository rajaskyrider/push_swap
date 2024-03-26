/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:16:02 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/26 19:18:03 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	reverse_rotate(t_ps_list **lst)
{
	t_ps_list	*first;
	t_ps_list	*temp;

	if (!*lst || (*lst)->next == NULL)
		return (false);
	first = *lst;
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->prev = NULL;
	temp->next = first;
	first->prev = temp;
	*lst = temp;
	return (true);
}

void	rra(t_ps_list **a, t_result **result, int id)
{
	if (reverse_rotate(a))
		addentry(result, "rra", id);
}

void	rrb(t_ps_list **b, t_result **result, int id)
{
	if (reverse_rotate(b))
		addentry(result, "rrb", id);
}

void	rrr(t_ps_list **a, t_ps_list **b, t_result **result, int id)
{
	if (reverse_rotate(a) && reverse_rotate(b))
		addentry(result, "rrr", id);
}
