/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:47:29 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/02 16:40:54 by rpandipe         ###   ########.fr       */
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
	sum = 0;
	while (a)
	{
		sum += a->n;
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
	t_ps_list	*temp;
	//t_ps_list	*less;	
	//t_ps_list	*greater;

	id = 1;
	temp = *a;
	//less = *a;
	//greater = *b;
	count = ft_list_count(a);
	while (count > 0)
	{
		if (temp->n > piv)
			pb(a, b, result, id);
		else
			ra(a, result, id);
		count--;
		temp = *a;
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
	}
}

void	quick_sort(t_ps_list **a, t_ps_list	**b, t_result **result)
{
	//t_ps_list	*a;
	
	int			pivot;

	if (!(*a) || !(*a)->next)
		return ;
	//a = copylist(lst);
	//b = NULL;

	if (issorted(a))
		return ;
	pivot = choose_pivot(a);
	split_list(a, b, result, pivot);
	quick_sort(a, b, result);
	quick_sort(b, a, result);
	combine(a, b, result);
	//print_a(a);
}