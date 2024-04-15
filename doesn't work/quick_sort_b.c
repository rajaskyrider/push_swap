/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 09:30:25 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/12 19:35:01 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	insert_a(t_ps_list **a, t_result **result, int max)
{
	int	count;

	count = 0;
	if (!(*a && (*a)->next))
		return (0);
	if ((*a)->n < max)
	{
		ra(a, result, 1);
		count++;
	}
	else if ((*a)->n > (*a)->next->n)
		sa(a, result, 1);
	return (count);
}

void	adjust_rotate_b(t_ps_list **a, t_ps_list **b, t_result **res, int c[2])
{
	while (c[0] || c[1])
	{
		if (c[0] > 0)
		{
			rrb(b, res, 1);
			c[0]--;
		}
		if (c[1] > 0)
		{
			rra(a, res, 1);
			c[1]--;
		}
	}
}

int	loop_b(t_ps_list **b, t_result **result, int pivot)
{
	t_ps_list	*temp;
	int			count;
	int			head;

	temp = *b;
	head = 0;
	while (temp)
	{
		if (temp->n >= pivot)
			break ;
		temp = temp->next;
		head++;
	}
	count = head;
	while (head--)
		rb(b, result, 1);
	return (count);
}

void	split_b(t_ps_list **a, t_ps_list **b, t_result **result, int len)
{
	int	org_size;
	int	pivot[2];
	int	count[2];

	count[0] = 0;
	count[1] = 0;
	org_size = len;
	pivot[0] = choose_pivot(b, len);
	pivot[1] = pivot_a(b, len);
	while (len != (org_size / 2))
	{
		count[0] += loop_b(b, result, pivot[0]);
		//if ((*b)->n >= pivot && len--)
		pa(a, b, result, 1);
		count[1] += insert_a(a, result, pivot[1]);
		len--;
	}
	if ((org_size / 2) == ft_list_count(b))
		count[0] = 0;
	else if (issorted(a))
		count[1] = 0;
	adjust_rotate_b(a, b, result, count);
}

void	quick_sort_b(t_ps_list **a, t_ps_list **b, t_result **result, int len)
{
	if (len <= 3)
	{
		sort_three_b(a, b, result, len);
		return ;
	}
	split_b(a, b, result, len);
	quick_sort_a(a, b, result, ((len / 2) + (len % 2)));
	quick_sort_b(a, b, result, (len / 2));
}