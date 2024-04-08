/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:53:34 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/08 23:57:31 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_optim_b(t_ps_list **b, t_result **result, int piv)
{
	t_ps_list	*temp;

	temp = *b;
	while (temp->next)
		temp = temp->next;
	while (temp && temp->n >= piv)
	{
		temp = temp->prev;
		rrb(b, result, 1);
	}
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
	pivot = choose_pivot(b, len);
	if (number == ft_list_count(b))
		split_optim_b(b, result, pivot);
	while (len != (number / 2))
	{
		if ((*b)->n >= pivot && len--)
			pa(a, b, result, 1);
		else if (++count)
			rb(b, result, 1);
	}
	while ((number / 2) != ft_list_count(b) && count--)
		rrb(b, result, 1);
	quick_sort_a(a, b, result, ((number / 2) + (number % 2)));
	quick_sort_b(a, b, result, (number / 2));
}
