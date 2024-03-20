/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:14:30 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/20 19:25:45 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_ps_list **lst)
{
	int	temp;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	temp = (*lst)->n;
	(*lst)->n = (*lst)->next->n;
	(*lst)->next->n = temp;
}

void	sa(t_ps_list **a)
{
	swap(a);
}

void	sb(t_ps_list *b)
{
	swap(b);
}

void	ss(t_ps_list **a, t_ps_list **b)
{
	sa(a);
	sb(b);
}
