/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 09:53:20 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/04 15:21:11 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_ps_list **a, t_result **result, int flag)
{
	if (flag == 1)
		sa(a, result, 42);
	else if (flag == 2)
		rra(a, result, 42);
	else if (flag == 3)
	{
		sa(a, result, 42);
		ra(a, result, 42);
	}
	else if (flag == 4)
		ra(a, result, 42);
	else if (flag == 5)
	{
		sa(a, result, 42);
		rra(a, result, 42);
	}
}

void	deal_three(t_ps_list **a, t_result **result, int size)
{
	if (size == 2 && !issorted(a))
		sa(a, result, 42);
	else if(size == 3 && !issorted(a))
	{
		if ((*a)->n > (*a)->next->n && (*a)->n < (*a)->next->next->n)
			sort_three(a, result, 1);
		else if((*a)->n < (*a)->next->n && (*a)->n > (*a)->next->next->n)
			sort_three(a, result, 2);
		else if((*a)->n < (*a)->next->n && (*a)->n < (*a)->next->next->n)
			sort_three(a, result, 3);
		else if ((*a)->n > (*a)->next->n && (*a)->n > (*a)->next->next->n \
					&& (*a)->next->n < (*a)->next->next->n)
			sort_three(a, result, 4);
		else if ((*a)->n > (*a)->next->n && (*a)->n > (*a)->next->next->n \
					&& (*a)->next->n > (*a)->next->next->n)
					sort_three(a, result, 5);
	}
	else
		return ;
}
