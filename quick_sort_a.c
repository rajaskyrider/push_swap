/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:59:49 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/15 11:52:59 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_optim_a(t_ps_list **a, t_ps_list **b, t_result **result, int piv)
{
	t_ps_list	*temp;
	int			count;

	count = 0;
	temp = *a;
	while (temp->next)
		temp = temp->next;
	while (temp && temp->n < piv)
	{
		temp = temp->prev;
		rra(a, result, 1);
		if ((*a)->n == find_min(a, ft_list_count(a)))
		{
			pb(a, b, result, 1);
			count++;
		}
	}
	if ((*a)->n == find_max(a, ft_list_count(a)))
		ra(a, result, 1);
	return (count);
}

void	split_a(t_ps_list **a, t_ps_list **b, t_result **result, int len)
{
	int	pivot[2];
	int	count[2];
	int	number;
	int	size[2];

	set_initials(count, size, a, b);
	number = len;
	pivot[0] = choose_pivot(a, len);
	pivot[1] = pivot_b(a, len);
	if (number == size[0])
		len -= split_optim_a(a, b, result, pivot[0]);
	while (len != ((number / 2) + (number % 2)))
	{
		if ((*a)->n < pivot[0] && len--)
		{
			pb(a, b, result, 1);
			count[1] += br(b, result, (int []){size[1], pivot[1], number, len});
		}
		else if (number == size[0] && smart_rotate_a(a, result, pivot[0]))
			len -= split_optim_a(a, b, result, pivot[0]);
		else
			count[0] += case_a_alt(a, result);
	}
	if (((number / 2) + (number % 2)) != ft_list_count(a) || size[1] != 0)
		fix_rotate(a, b, result, count);
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
