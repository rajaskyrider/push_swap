/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:53:34 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/10 15:25:46 by rpandipe         ###   ########.fr       */
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
	int size;

	number = len;
	count = 0;
	size = ft_list_count(b);
	if (len <= 3)
	{
		sort_three_b(a, b, result, len);
		return ;
	}
	pivot = choose_pivot(b, len);
	if (number == size)
		len -= split_optim_b(a, b, result, pivot);
	while (len != (number / 2))
	{
		if ((*b)->n >= pivot && len--)
		{
			pa(a, b, result, 1);
			smart_swap_a(a, result, len, number);
		}

		//else if (number == size && smart_rotate_b(b, result, pivot))
	//			len -= split_optim_b(a, b, result, pivot);
		else
		{
			rb(b, result, 1);
			count++;
		}
	}
	while ((number / 2) != ft_list_count(b) && count--)
		rrb(b, result, 1);
	quick_sort_a(a, b, result, ((number / 2) + (number % 2)));
	quick_sort_b(a, b, result, (number / 2));
}
