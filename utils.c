/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:21:51 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/26 20:08:28 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_list	*create_node(int n)
{
	t_ps_list	*node;

	node = (t_ps_list *)malloc(sizeof(t_ps_list));
	if (!node)
		return (NULL);
	node->n = n;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	free_struct(t_ps_list **lst)
{
	t_ps_list	*current;
	t_ps_list	*next_node;

	current = *lst;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*lst = NULL;
}

void	free_result(t_result **lst)
{
	t_result	*current;
	t_result	*next_node;

	current = *lst;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*lst = NULL;
}

t_bool	issorted(t_ps_list **a)
{
	t_ps_list	*current;

	current = *a;
	while (current && current->next)
	{
		if (current->n > current->next->n)
			return (false);
		current = current->next;
	}
	return (true);
}

t_ps_list	*copylist(t_ps_list **a)
{
	t_ps_list	*copyhead;
	t_ps_list	*copy;
	t_ps_list	*tcpy;
	t_ps_list	*temp;

	copyhead = create_node((*a)->n);
	copy = copyhead;
	temp = (*a)->next;
	while (temp)
	{
		tcpy = create_node(temp->n);
		if (!tcpy)
		{
			free_struct(&copyhead);
			return (NULL);
		}
		tcpy->prev = copy;
		copy->next = tcpy;
		copy = copy->next;
		temp = temp->next;
	}
	return (copyhead);
}
