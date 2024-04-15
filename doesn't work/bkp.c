/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bkp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 22:24:37 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/12 00:05:27 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	loop_head(t_ps_list *temp, int val[2])
{
	int	count;

	count = 0;
	while (temp)
	{
		if (temp->n >= val[0] && temp->n <= val[1])
			break;
		count++;
		temp = temp->next;
	}
	return (count);
}

int	loop_tail(t_ps_list *temp, int val[2])
{
	int	count;

	count = 1;
	while (temp)
	{
		if (temp->n >= val[0] && temp->n <= val[1])
			break;
		count++;
		temp = temp->prev;
	}
	return (count);
}
void	insert_b(t_ps_list **b, t_result **result, int size, int max)
{
	if (!(*b && (*b)->next))
		return ;
	if (size == 0)
	{
		if ((*b)->n < max)
			rb(b, result, 1);
		else if ((*b)->n < (*b)->next->n)
			sb(b, result, 1);
	}
	else
	{
		if ((*b)->n < max)
			rb(b, result, 1);
		else if ((*b)->n < (*b)->next->n)
			sb(b, result, 1);
	}
}

void	reverse_b(t_ps_list **b, t_result **result, int val[2])
{
	t_ps_list	*temp;
	t_ps_list	*lst;

	temp = *b;
	while (temp->next)
		temp = temp->next;
	lst = temp;
	while (temp)
	{
		lst = lst->prev;
		if (temp->n >= val[0] && temp->n <= val[1])
			rrb(b, result, 1);
		else
			break;
		temp = lst;
	}
	
}

void	split_c(t_ps_list **a, t_ps_list **b, t_result **result, int val[2])
{
	t_ps_list *temp;
	int	head;
	int	tail;
	int	size_b;

	temp = *a;
	size_b = ft_list_count(b);
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
	insert_b(b, result, size_b, (val[1] - 10));
}

void	insertion_split(t_ps_list **a, t_ps_list **b, t_result **result, int size)
{
	int	val[2];
	int	i;
	int	loop;

	i = 4;
	val[0] = 1;
	val[1] = size / 5;
	while (i-- > 0)
	{
		loop = 20;
		while (loop--)
			split_c(a, b, result, val);
		if (i < 3)
			reverse_b(b, result, val);
		val[0] += size / 5;
		val[1] += size / 5;
	}
	//print_a(a);
	i = 0;
	/*while (*result)
	{
		(*result) = (*result)->next;
		i++;
	}*/
	//print_a(b);
	quick_sort_a(a, b, result, 20);
	quick_sort_b(a, b, result, 80);
}
