/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:59:49 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/06 23:32:19 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a(t_ps_list **a, t_ps_list **b, t_result **result, int len)
{
	if (len <= 3 && ft_list_count(a) <= 3)
		deal_three(a, result, len);
	else if (len == 2)
	{
		if ((*a)->n > (*a)->next->n)
			sa(a, result, 1);
	}
	else if (len == 3)
	{
		while (len != 3 || \
		!((*a)->n < (*a)->next->n && (*a)->next->n < (*a)->next->next->n))
		{
			if (len == 3 && (*a)->n > (*a)->next->n && (*a)->next->next->n)
				sa(a, result, 1);
			else if (len == 3 && !((*a)->next->next->n > (*a)->n\
				&& (*a)->next->next->n > (*a)->next->n))
			{
				pb(a, b, result, 1);
				len--;
			}
			else if ((*a)->n > (*a)->next->n)
				sa(a, result, 1);
			else if (len++)
				pa(a, b, result, 1);
		}
	}
}

void	quick_sort_a(t_ps_list **a, t_ps_list **b, t_result **result, int len)
{
	int	pivot;
	int	count;
	int	number;

	count = 0;
	number = len;
	if (len <= 3)
	{
		sort_three_a(a, b, result, len);
		return ;
	}
	pivot = choose_pivot(a, result, len);
	while (len != ((number / 2) + (number % 2)))
	{
		if ((*a)->n < pivot && len--)
			pb(a, b, result, 1);
		else if (++count)
			ra(a, result, 1);
	}
	while (((number / 2) + (number % 2)) != ft_list_count(a) && count--)
		rra(a, result, 1);
	quick_sort_a(a, b, result, ((number / 2) + (number % 2)));
	quick_sort_b(a, b, result, (number / 2));
}
