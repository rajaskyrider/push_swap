/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:36:41 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/12 19:24:01 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	loop_head_a(t_ps_list **a, int pivot)
{
	t_ps_list	*temp;
	int			count;

	temp = *a;
	count = 0;
	while (temp)
	{
		if (temp->n < pivot)
			break ;
		temp = temp->next;
		count++;
	}
	return (count);
}

int	loop_tail_a(t_ps_list **a, int pivot, int max)
{
	t_ps_list	*temp;
	int			count;

	temp = *a;
	count = 1;
	while (temp->next)
		temp = temp->next;
	while (temp)
	{
		if (temp->n < pivot)
			break ;
		if (temp->n > max)
		{
			count = -2;
			break ;
		}
		temp = temp->prev;
		count++;
	}
	return (count);
}

void	sort_b_aux(t_ps_list **a, t_ps_list **b, t_result **result, int len)
{
	while (len || \
		!((*a)->n < (*a)->next->n && (*a)->next->n < (*a)->next->next->n))
	{
		if (len == 1 && (*a)->n > (*a)->next->n)
			sa(a, result, 1);
		else if (len == 1 || (len >= 2 && (*b)->n > (*b)->next->n) || \
			(len == 3 && (*b)->n > (*b)->next->next->n))
		{
			pa(a, b, result, 1);
			len--;
		}
		else
			sb(b, result, 1);
	}
}

void	sort_three_b(t_ps_list **a, t_ps_list **b, t_result **result, int len)
{
	if (len == 1)
		pa(a, b, result, 1);
	else if (len == 2)
	{
		if ((*b)->n < (*b)->next->n)
			sb(b, result, 1);
		while (len--)
			pa(a, b, result, 1);
	}
	else if (len == 3)
	{
		sort_b_aux(a, b, result, len);
	}
}

void	adjust_rotate_a(t_ps_list **a, t_ps_list **b, t_result **res, int c[2])
{
	while (c[0] || c[1])
	{
		if (c[0] > 0)
		{
			rra(a, res, 1);
			c[0]--;
		}
		if (c[1] > 0)
		{
			rrb(b, res, 1);
			c[1]--;
		}
	}
}
