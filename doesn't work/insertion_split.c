/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 22:24:37 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/12 00:13:14 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	loop_head(t_ps_list *temp, int val)
{
	int	count;

	count = 0;
	while (temp)
	{
		if (temp->n == val)
			break;
		count++;
		temp = temp->next;
	}
	return (count);
}

int	loop_tail(t_ps_list *temp, int val)
{
	int	count;

	count = 1;
	while (temp)
	{
		if (temp->n == val)
			break;
		count++;
		temp = temp->prev;
	}
	return (count);
}

void	split_c(t_ps_list **a, t_ps_list **b, t_result **result, int val)
{
	t_ps_list *temp;
	int	head;
	int	tail;

	temp = *a;
	head = loop_head(temp, val);
	temp = *a;
	while(temp->next)
		temp = temp->next;
	tail = loop_tail(temp, val);
	if (head <= tail)
		while (head-- > 0)
			ra(a, result, 1);
	else
		while (tail-- > 0)
			rra(a, result, 1);
	pb(a, b, result, 1);
}

void	insertion_split(t_ps_list **a, t_ps_list **b, t_result **result, int size)
{
	int	i;

	(void) size;
	i = 1;
	while (i <= 100)
	{
		split_c(a, b, result, i);
		i++;
	}
	while (*b)
		pa(a, b, result, 1);
}
