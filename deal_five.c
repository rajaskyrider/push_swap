/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:37:15 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/05 10:54:27 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_five(t_ps_list **a, t_ps_list **b, t_result **result, int piv)
{
	int		count;
	int		id;
	t_ps_list	*temp;

	id = 42;
	temp = *a;
	count = ft_list_count(a);
	while (count > 0)
	{
		if (temp->n < piv)
			pb(a, b, result, id);
		else
			ra(a, result, id);
		count--;
		temp = *a;
	}
}

void	sort_five(t_ps_list **a, t_result **result, int flag)
{
	if (flag == 0)
	{
		sb(a, result, 42);
		rrb(a, result, 42);
	}
	if (flag == 1)
		rrb(a, result, 42);
	else if (flag == 2)
		sb(a, result, 42);
	else if (flag == 3)
		rb(a, result, 42);
	else if (flag == 4)
	{
		sb(a, result, 42);
		rb(a, result, 42);
	}
}

void	reverse_sort(t_ps_list **a, t_result **result, int size)
{
	if (size == 2 && issorted(a))
		sb(a, result, 42);
	else if(size == 3 && !issorted(a))
	{
		if ((*a)->n > (*a)->next->n && (*a)->n < (*a)->next->next->n)
			sort_five(a, result, 1);
		else if((*a)->n < (*a)->next->n && (*a)->n > (*a)->next->next->n)
			sort_five(a, result, 2);
		else if((*a)->n < (*a)->next->n && (*a)->n < (*a)->next->next->n)
			sort_five(a, result, 3);
		else if ((*a)->n > (*a)->next->n && (*a)->n > (*a)->next->next->n \
					&& (*a)->next->n < (*a)->next->next->n)
			sort_five(a, result, 4);
		else if ((*a)->n > (*a)->next->n && (*a)->n > (*a)->next->next->n \
					&& (*a)->next->n > (*a)->next->next->n)
					return ;
	}
	else if(size == 3 && issorted(a))
	{
		sort_five(a, result, 0);
	}
}

void	deal_five(t_ps_list **a, t_result **result)
{
	t_ps_list	*b;
	int			pivot;
	int			size_a;
	int			size_b;

	b = NULL;
	if (issorted (a))
		return ;
	pivot = choose_pivot(a);
	split_five(a, &b, result, pivot);
	size_a = ft_list_count(a);
	size_b = ft_list_count(&b);
	deal_three(a, result, size_a);
	reverse_sort(&b, result, size_b);
	while (size_b > 0)
	{
		pa(a, &b, result, 42);
		size_b--;
	}
}
