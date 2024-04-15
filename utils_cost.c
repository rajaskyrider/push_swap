/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:09:15 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/15 15:02:47 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_reverse_a(t_ps_list **a, t_cost **cost)
{
	t_ps_list	*temp;
	t_cost		*c;
	int			count;

	temp = *a;
	c = *cost;
	count = 1;
	while (temp->next)
		temp = temp->next;
	while (c->next)
		c = c->next;
	while (temp->n != c->a_n)
	{
		count++;
		temp = temp->prev;
	}
	return (count);
}

int	cost_reverse_b(t_ps_list **b, t_cost **cost)
{
	t_ps_list	*temp;
	t_cost		*c;
	int			count;

	temp = *b;
	c = *cost;
	count = 1;
	while (temp->next)
		temp = temp->next;
	while (c->next)
		c = c->next;
	while (temp->n != c->b_n)
	{
		count++;
		temp = temp->prev;
	}
	return (count);
}

int	loop_top(t_ps_list **a, int min)
{
	int			head;
	t_ps_list	*temp;

	head = 0;
	temp = *a;
	while (temp && temp->n != min)
	{
		head++;
		temp = temp->next;
	}
	if (temp->n == min)
		return (head);
	else
		return (0);
}

int	loop_bottom(t_ps_list **a, int min)
{
	int			tail;
	t_ps_list	*temp;

	tail = 1;
	temp = *a;
	while (temp->next)
		temp = temp->next;
	while (temp && temp->n != min)
	{
		tail++;
		temp = temp->prev;
	}
	if (temp->n == min)
		return (tail);
	else
		return (0);
}

void	loop_min(t_ps_list **a, t_result **result, int min)
{
	int	head;
	int	tail;

	if ((*a)->n != min)
	{
		head = loop_top(a, min);
		tail = loop_bottom(a, min);
		if (head >= tail)
		{
			while (head--)
				ra(a, result, 1);
			return ;
		}
		else
		{
			while (tail--)
				rra(a, result, 1);
			return ;
		}
	}
}
