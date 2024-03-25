/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:21:51 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/25 19:55:04 by rpandipe         ###   ########.fr       */
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
