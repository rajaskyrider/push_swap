/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:21:51 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/21 20:22:16 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_list	*create_node (int n)
{
	t_ps_list *node;

	node = (t_ps_list *)malloc(sizeof(t_ps_list));
	if (!node)
		return (NULL);
	node->n = n;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
