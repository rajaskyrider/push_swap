/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:14:30 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/26 19:13:42 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	swap(t_ps_list **lst)
{
	int	temp;

	if (*lst == NULL || (*lst)->next == NULL)
		return (false);
	temp = (*lst)->n;
	(*lst)->n = (*lst)->next->n;
	(*lst)->next->n = temp;
	return (true);
}

void	sa(t_ps_list **a, t_result **result, int id)
{
	if (swap(a))
		addentry(result, "sa", id);
}

void	sb(t_ps_list **b, t_result **result, int id)
{
	if (swap(b))
		addentry(result, "sb", id);
}

void	ss(t_ps_list **a, t_ps_list **b, t_result **result, int id)
{
	if (swap(a) && swap(b))
		addentry(result, "ss", id);
}
