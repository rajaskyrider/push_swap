/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stable_quick_sort_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:53:34 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/12 19:54:20 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_optim_b(t_ps_list **a, t_ps_list **b, t_result **result, int piv)
{
	t_ps_list	*temp;
	int		count;

	temp = *b;
	count = 0;
	while (temp->next)
		temp = temp->next;
	while (temp && temp->n >= piv)
	{
		temp = temp->prev;
		rrb(b, result, 1);
		if ((*b)->n == find_max(b, ft_list_count(b)))
		{
			pa(a, b, result, 1);
			count++;
		}
	}
	return (count);
}


void	st_quick_sort_b(t_ps_list **a, t_ps_list **b, t_result **result, int len)
{
	int	pivot;
	int	count;
	int	count_a;
	int	number;
	int	piv_a;

	number = len;
	count = 0;
	count_a = 0;
	if (len <= 3)
	{
		sort_three_b(a, b, result, len);
		return ;
	}
	pivot = choose_pivot(b, len);
	piv_a = pivot_b(b, len);
	if (number == ft_list_count(b))
		len -= split_optim_b(a, b, result, pivot);
	while (len != (number / 2))
	{
		if ((*b)->n >= pivot && len--)
		{
			pa(a, b, result, 1);
			if ((*a)->n < piv_a)
			{
				ra(a, result, 1);
				count_a++;
			}
			else
				smart_swap_a(a, result, len, number);
		}

		//else if (number == size && smart_rotate_b(b, result, pivot))
		//	len -= split_optim_b(a, b, result, pivot);
		else
		{
			rb(b, result, 1);
			count++;
		}
	}
	while (((number / 2) != ft_list_count(b) && count) || (!(issorted(a)) && count_a))
	{
		if (count > 0)
		{
			rrb(b, result, 1);
			count--;
		}
		if (count_a > 0)
		{
			rra(a, result, 1);
			count_a--;
		}
	}
	st_quick_sort_a(a, b, result, ((number / 2) + (number % 2)));
	st_quick_sort_b(a, b, result, (number / 2));
}
