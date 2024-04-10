/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:56:08 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/10 12:51:21 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_ps_list **lst, int len)
{
	int		max;
	t_ps_list	*temp;

	temp = *lst;
	max = temp->n;
	while (len--)
	{
		if (max < temp->n)
			max = temp->n;
		temp = temp->next;
	}
	return (max);
}

int	find_min(t_ps_list **lst, int len)
{
	int		min;
	t_ps_list	*temp;

	temp = *lst;
	min = temp->n;
	while (len--)
	{
		if (min > temp->n)
			min = temp->n;
		temp = temp->next;
	}
	return(min);
}

t_bool	smart_rotate_a(t_ps_list **a, t_result **result, int piv)
{
	t_ps_list	*temp;

	temp = *a;
	while (temp->next)
		temp = temp->next;
	if ((*a)->n > piv && (*a)->next->n > piv && temp->prev->n < piv)
	{
		rra(a, result, 1);
		return (true);
	}
	return (false);
}