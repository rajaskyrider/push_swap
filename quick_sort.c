/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:47:29 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/29 17:51:11 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	choose_pivot(t_ps_list **lst)
{
	int	sum;
	int	c;
	int	avg;
	t_ps_list	*a;

	a = *lst;
	c = 0;
	while (a)
	{
		sum = a->n;
		c++;
		a = a->next;
	}
	if (c == 0)
		return (0);
	avg = sum / c;
	return (avg);
}

void	split_list(t_ps_list **a, t_ps_list **b, t_result **result, int piv)
{
	int		count;
	int		id;
	t_ps_list	*less;	
	t_ps_list	*greater;

	id = 1;
	less = *a;
	greater = *b;
	count = ft_list_count(a);
	while (count > 0)
	{
		if (less->n > piv)
			pb(&less, &greater, result, id);
		else
			ra(&less, result, id);
		count--;
	}
}

void	combine(t_ps_list **a, t_ps_list **b, t_result **result)
{
	int	id;

	id = 1;
	while (*b)
	{
		pa(a, b, result, id);
		ra(a, result, id);
		(*b) = (*b)->next;
	}
}

void	quick_sort(t_ps_list **lst, t_result **result)
{
	t_ps_list	*a;
	t_ps_list	*b;
	int			pivot;

	a = copylist(lst);
	b = NULL;

	if (issorted(&a))
		return ;
	pivot = choose_pivot(lst);
	split_list(&a, &b, result, pivot);
	quick_sort(&a, result);
	quick_sort(&b, result);
	combine(&a, &b, result);
}