/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:07:51 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/09 10:04:44 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	merge_node(t_result **result, t_result **node, char *op)
{
	t_result	*head;
	t_result	*tail;
	t_result	*temp;

	temp = *result;
	tail = (*node)->next;
	if (temp == (*node))
		head = NULL;
	else
	{	
		while (temp->next && temp->next != (*node))
			temp = temp->next;
		head = temp;
	}
	tail->op = op;
	if (head)
		head->next = tail;
	temp = (*node);
	(*node) = (*node)->next;
	free(temp);	
}

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
	(*node) = temp->next->next;
	free(temp->next);
	free(temp);
}

void	result_merge(char *op1, char *op2, char *op3, t_result **result)
{
	t_result	*temp;

	temp = *result;
	while(temp)
	{
		if (temp->next && ft_strncmp(temp->op, op1, ft_strlen(op1)) == 0 \
			&& ft_strncmp(temp->next->op, op2, ft_strlen(op2)) == 0)
			merge_node(result, &temp, op3);
		else
			temp = temp->next;
	}
	temp = *result;
	while(temp)
	{
		if (temp->next && ft_strncmp(temp->op, op2, ft_strlen(op2)) == 0\
			&& ft_strncmp(temp->next->op, op1, ft_strlen(op1)) == 0)
			merge_node(result, &temp, op3);
		else
			temp = temp->next;
	}
}

void	result_purge(char *op1, char *op2, t_result **result)
{
	t_result	*temp;

	temp = *result;
	while(temp)
	{
		if (temp->next && ft_strncmp(temp->op, op1, ft_strlen(op1)) == 0 \
			&& ft_strncmp(temp->next->op, op2, ft_strlen(op2)) == 0)
			purge_node(result, &temp);
		else
			temp = temp->next;
	}
	temp = *result;
	while(temp)
	{
		if (temp->next && ft_strncmp(temp->op, op2, ft_strlen(op2)) == 0 \
			&& ft_strncmp(temp->next->op, op1, ft_strlen(op1)) == 0)
			purge_node(result, &temp);
		else
			temp = temp->next;
	}
}

void	sort_opt(t_result **result)
{
	result_merge("sa", "sb", "ss", result);
	result_merge("ra", "rb", "rr", result);
	result_merge("rra", "rrb", "rrr", result);
	result_purge("pa", "pb", result);
	result_purge("sa", "sa", result);
	result_purge("sb", "sb", result);
	result_purge("ra", "rra", result);
	result_purge("rb", "rrb", result);
}
