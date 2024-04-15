/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threeway_quicksort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:57:08 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/11 15:29:03 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	optim_lst(t_ps_list **a, t_ps_list **b, t_result **result, int size)
{
	t_ps_list	*temp;
	int		count;

	count = 0;
	temp = *a;
	while (temp->next)
		temp = temp->next;
	while (temp && temp->n < size / 3)
	{
		temp = temp->prev;
		rra(a, result, 1);
		if ((*a)->n == find_min(a, ft_list_count(a)))
		{
			pb(a, b, result, 1);
			count++;
		}
	}

	return (count);
}

void threeway_sort(t_ps_list **a, t_ps_list **b, t_result **result, int size)
{
	int	chunk_min;
	int	chunk_mid;
	int	chunk_max;
	int	number;

	chunk_min = (size / 3) + (size % 3);
	chunk_mid = size / 3;
	chunk_max = size - (chunk_min + chunk_mid);
	number = size;
	size -= optim_lst(a, b, result, size);
	while(size)
	{
		if ((*a)->n < chunk_min)
		{
			pb(a, b, result, 1);
			rb(b, result, 1);
		}
		else if ((*a)->n < chunk_mid)
		{
			pb(a, b, result, 1);
			smart_swap_b(b, result, size, number);
		}
		else
			
			ra(a, result, 1);
		size--;
	}
	quick_sort_a(a, b, result, ft_list_count(a));
	quick_sort_b(a, b, result, ft_list_count(b));
}
