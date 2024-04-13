/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 09:35:07 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/13 16:06:07 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_five(t_ps_list **a, t_ps_list **b, t_result **result, int n)
{
	int	avg;

	avg = 0;
	while (n > 5)
	{
		avg = choose_avg(a);
		if ((*a)->n > 6)
			pb(a, b, result, 1);
		else
			ra(a, result, 1);
		n--;
	}
}

int	find_matching(t_ps_list *a, int b)
{
	int match;
	int min;
	int	diff;

	min = 2147483647;
	while (a)
	{
		diff = (a->n - b);
		if (diff > 0 && diff < min)
		{
			min = diff;
			match = a->n;
		}
		a = a->next;
	}
	return (match);
}

void	addmoves(t_cost **cost, t_ps_list **a, t_ps_list **b)
{
	t_cost		*temp;
	int			count[2];
	t_ps_list	*c;
	t_ps_list	*d;

	temp = *cost;
	c = *a;
	d = *b;
	count[0] = 0;
	count[1] = 0;
	while (temp->next)
		temp = temp->next;
	while (temp->a_n != c->n)
	{
		count[0]++;
		c = c->next;
	}
	while (temp->b_n != d->n)
	{
		count[1]++;
		d = d->next;
	}
	temp->moves_a = count[0];
	temp->moves_b = count[1];
	temp->cost = count[0] + count[1];
}

void	find_cost(t_ps_list **a, t_ps_list **b, t_result **result, t_cost **cost)
{
	t_ps_list	*a_dup;
	t_ps_list	*b_dup;
	int			m;

	a_dup = *a;
	b_dup = *b;
	while (b_dup)
	{
		m = find_matching(a, b_dup->n);
		addcost(cost, m, b_dup->n);
		addmoves(cost, a, b);
		b_dup = b_dup->next;
	}
}

void	insertion_sort(t_ps_list **a, t_ps_list **b, t_result **result, int n)
{
	t_cost		*cost;
	
	cost = NULL;
	split_five(a, b, result, n);
	deal_five(a, result);
	while (*b != NULL)
	{
		find_cost(a, b, result, &cost);
		min_cost(a, b, result, &cost);
}
