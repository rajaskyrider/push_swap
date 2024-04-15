/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_purge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:25:41 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/15 09:51:37 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	purge_node(t_result **result, t_result **node)
{
	t_result	*head;
	t_result	*tail;
	t_result	*temp;

	temp = *result;
	tail = (*node)->next->next;
	if (temp == (*node))
		head = NULL;
	else
	{
		while (temp->next && temp->next != (*node))
			temp = temp->next;
		head = temp;
	}
	if (head)
		head->next = tail;
	temp = (*node);
	(*node) = head;
	free(temp->next);
	free(temp);
}

void	purge_rev(char *op1, char *op2, t_result **result)
{
	t_result	*temp;

	temp = *result;
	while (temp)
	{
		if (temp->next && ft_strncmp(temp->op, "rrr", 3) == 0 \
			&& ft_strncmp(temp->next->op, "rra", 3) == 0)
		{
			ft_strlen("rrr");
			ft_strncmp(temp->op, "rrr", 3);
			ft_strncmp(temp->next->op, "rra", 3);
		}
		if (temp->next && ft_strncmp(temp->op, op2, ft_strlen(op2)) == 0 \
			&& ft_strncmp(temp->next->op, op1, ft_strlen(op1)) == 0)
			purge_node(result, &temp);
		else
			temp = temp->next;
	}
}

void	result_purge(char *op1, char *op2, t_result **result)
{
	t_result	*temp;

	temp = *result;
	while (temp)
	{
		if (temp->next && ft_strncmp(temp->op, op1, ft_strlen(op1)) == 0 \
			&& ft_strncmp(temp->next->op, op2, ft_strlen(op2)) == 0)
			purge_node(result, &temp);
		else
			temp = temp->next;
	}
	purge_rev(op1, op2, result);
}
