/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 09:56:21 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/15 15:14:26 by rpandipe         ###   ########.fr       */
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
	node->flag_a = 0;
	node->flag_b = 0;
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

void	min_cost(t_ps_list **a, t_ps_list **b, t_result **result, t_cost **cost)
{
	t_cost	*temp;
	int		min;
	int		moves[2];
	int		flag[2];

	temp = *cost;
	min = 2147483647;
	moves[0] = 0;
	moves[1] = 0;
	while (temp)
	{
		if (temp->cost < min)
		{
			min = temp->cost;
			moves[0] = temp->moves_a;
			moves[1] = temp->moves_b;
			flag[0] = temp->flag_a;
			flag[1] = temp->flag_b;
		}
		temp = temp->next;
	}
	opt_rot_cost(a, b, result, (int []){moves[0], moves[1], flag[0], flag[1]});
}

void	insert_five(t_ps_list **a, t_ps_list **b, t_result **result, int n)
{
	int	avg;

	avg = 0;
	avg = choose_avg(a);
	while (n > 5)
	{
		if ((*a)->n < avg)
		{
			pb(a, b, result, 1);
			n--;
			avg = choose_avg(a);
		}
		else
			ra(a, result, 1);
	}
}
