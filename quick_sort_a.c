/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 09:29:54 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/12 19:35:07 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	insert_b(t_ps_list **b, t_result **result, int max, int size)
{
	int	count;

	count = 0;
	if (!(*b && (*b)->next))
		return (0);
	if (size == 0)
	{
		if ((*b)->n < max)
			rb(b, result, 1);
		else if ((*b)->n < (*b)->next->n)
			sb(b, result, 1);
	}
	else
	{
		if ((*b)->n > max)
		{
			rb(b, result, 1);
			count++;
		}
		else if ((*b)->n < (*b)->next->n)
			sb(b, result, 1);
	}
	return (count);
}

int	loop_a(t_ps_list **a, t_result **result, int pivot, int len)
{
	int	head;
	int	tail;
	int	max;
	int	count;

	max = find_max(a, len);
	head = loop_head_a(a, pivot);
	tail = loop_tail_a(a, pivot, max);
	if (tail == -2)
		tail = head * 2;
	if (head <= tail)
	{
		count = head;
		while (head--)
			ra(a, result, 1);
	}
	else
	{
		count = tail;
		while (tail--)
			rra(a, result, 1);
	}
	return (count);
}

void	split_a(t_ps_list **a, t_ps_list **b, t_result **result, int len)
{
	int	size[2];
	int	org_size;
	int	pivot[2];
	int	count[2];

	count[0] = 0;
	count[1] = 0;
	size[0] = ft_list_count(a);
	size[1] = ft_list_count(b);
	org_size = len;
	pivot[0] = choose_pivot(a, len);
	pivot[1] = pivot_b(a, len);
	while (len != ((org_size / 2) + (org_size % 2)))
	{
		count[0] += loop_a(a, result, pivot[0], len);
		//if ((*a)->n < pivot && len--)
		pb(a, b, result, 1);
		count[1] += insert_b(b, result, pivot[1], size[1]);
		len--;
	}
	if (((org_size / 2) + (org_size % 2)) == ft_list_count(a))
		count[0] = 0;
	else if (size[1] == 0)
		count[1] = 0;
	adjust_rotate_a(a, b, result, count);
}

void	quick_sort_a(t_ps_list **a, t_ps_list **b, t_result **result, int len)
{
	if (len <=3)
	{
		sort_three_a(a, b, result, len);
		return ;
	}
	split_a(a, b, result, len);
	quick_sort_a(a, b, result, ((len / 2) + (len % 2)));
	quick_sort_b(a, b, result, (len / 2));
}
