/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:59:49 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/08 16:17:53 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_optim_a(t_ps_list **a, t_result **result, int piv)
{
	t_ps_list	*temp;

	temp = *a;
	while (temp->next)
		temp = temp->next;
	while (temp && temp->n < piv)
	{
		temp = temp->prev;
		rra(a, result, 1);
	}
}

void	split_a(t_ps_list **a, t_ps_list **b, t_result **result, int len)
{
	int	pivot;
	int	count;
	int	number;

	count = 0;
	number = len;
	pivot = choose_pivot(a, len);
	if (number == ft_list_count(a))
		split_optim_a(a, result, pivot);
	while (len != ((number / 2) + (number % 2)))
	{
		if ((*a)->n < pivot && len--)
			pb(a, b, result, 1);
		else if (++count)
		{
			/*if (number == size)
				split_optim_a(a, result, pivot);
			else*/
				ra(a, result, 1);
		}
	}
	while (((number / 2) + (number % 2)) != ft_list_count(a) && count--)
		rra(a, result, 1);
}

void	sort_a_aux(t_ps_list **a, t_ps_list **b, t_result **result, int len)
{
	while (len != 3 || \
		!((*a)->n < (*a)->next->n && (*a)->next->n < (*a)->next->next->n))
	{
		if (len == 3 && (*a)->n > (*a)->next->n && \
			(*a)->next->next->n)
			sa(a, result, 1);
		else if (len == 3 && !((*a)->next->next->n > (*a)->n \
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
		sort_a_aux(a, b, result, len);
}

void	quick_sort_a(t_ps_list **a, t_ps_list **b, t_result **result, int len)
{
	int	number;

	number = len;
	if (len <= 3)
	{
		sort_three_a(a, b, result, len);
		return ;
	}
	split_a(a, b, result, len);
	quick_sort_a(a, b, result, ((number / 2) + (number % 2)));
	quick_sort_b(a, b, result, (number / 2));
}
