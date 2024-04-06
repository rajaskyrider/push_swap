/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:53:34 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/06 19:19:30 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		while (len || \
		!((*a)->n < (*a)->next->n && (*a)->next->n < (*a)->next->next->n))
		{
			if (len == 1 && (*a)->n > (*a)->next->n)
				sa(a, result, 1);
			else if (len == 1 || (len >= 2 && (*b)->n > (*b)->next->n) ||\
				(len == 3 && (*b)->n > (*b)->next->next->n))
			{
				pa(a, b, result, 1);
				len--;
			}
			else
				sb(b, result, 1);
		}
	}
}

void	quick_sort_b(t_ps_list **a, t_ps_list **b, t_result **result, int len)
{
	int	pivot;
	int	count;
	int	number;

	number = len;
	count = 0;
	if (len <= 3)
	{
		sort_three_b(a, b, result, len);
		return ;
	}
	//pivot = choose_pivot(b, result, len);
	pivot = choose_avg(b);
	while (len != (number / 2))
	{
		if ((*b)->n >= pivot && len--)
			pa(a, b, result, 1);
		else if (++count)
			rb(b, result, 1);
	}
	while ((number / 2) != ft_list_count(b) && count--)
		rrb(a, result, 1);
	quick_sort_a(a, b, result, ((number / 2) + (number % 2)));
	quick_sort_b(a, b, result, (number / 2));
}
