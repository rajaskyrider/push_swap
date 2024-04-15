/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:53:34 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/15 15:01:45 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_optim_b(t_ps_list **a, t_ps_list **b, t_result **result, int piv)
{
	t_ps_list	*temp;
	int			count;

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

void	split_b(t_ps_list **a, t_ps_list **b, t_result **result, int len)
{
	int	pivot[2];
	int	count[2];
	int	number;

	number = len;
	set_initials_b(pivot, count, len, b);
	if (number == ft_list_count(b))
		len -= split_optim_b(a, b, result, pivot[0]);
	while (len != (number / 2))
	{
		if ((*b)->n >= pivot[0] && len--)
		{
			pa(a, b, result, 1);
			if ((*a)->n < pivot[1])
				count[1] += case_a_alt(a, result);
			else
				smart_swap_a(a, result, len, number);
		}
		else
			count[0] += case_b_alt(b, result);
	}
	if ((number / 2) != ft_list_count(b) || !(issorted(a)))
		fix_rotate_b(a, b, result, count);
}

void	quick_sort_b(t_ps_list **a, t_ps_list **b, t_result **result, int len)
{
	int	number;

	number = len;
	if (len <= 3)
	{
		sort_three_b(a, b, result, len);
		return ;
	}
	split_b(a, b, result, len);
	quick_sort_a(a, b, result, ((number / 2) + (number % 2)));
	quick_sort_b(a, b, result, (number / 2));
}
