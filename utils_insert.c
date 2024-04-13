/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 09:56:21 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/13 10:24:15 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cost	*create_cost(int a, int b)
{
	t_cost	*node;

	node = (t_cost *)malloc(sizeof(t_cost));
	if (!node)
		exit (1);
	node->a_n = a;
	node->b_n = b;
	node->moves_a = 2147483647;
	node->moves_b = 2147483647;
	node->cost = 2147483647;
	node->next = NULL;
	return (node);
}

void	addcost(t_cost **cost, int a, int b)
{
	t_cost	*lst;

	if (*cost == NULL)
	{
		*cost = create_cost(a, b);
		return ;
	}
	lst = *cost;
	while (lst->next)
	{
		lst = lst->next;
	}
	lst->next = create_cost(a, b);
}

void	free_cost(t_cost **lst)
{
	t_cost	*current;
	t_cost	*next_node;

	current = *lst;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*lst = NULL;
}