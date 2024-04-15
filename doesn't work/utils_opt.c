/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:56:08 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/10 23:51:45 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_ps_list **lst, int len)
{
	int		max;
	t_ps_list	*temp;

	temp = *lst;
	max = temp->n;
	while (len--)
	{
		if (max < temp->n)
			max = temp->n;
		temp = temp->next;
	}
	return (max);
}

int	find_min(t_ps_list **lst, int len)
{
	int		min;
	t_ps_list	*temp;

	temp = *lst;
	min = temp->n;
	while (len--)
	{
		if (min > temp->n)
			min = temp->n;
		temp = temp->next;
	}
	return(min);
}

t_bool	smart_rotate_a(t_ps_list **a, t_result **result, int piv)
{
	t_ps_list	*temp;

	temp = *a;
	while (temp->next)
		temp = temp->next;
	if ((*a)->n > piv && (*a)->next->n > piv && (temp->n < piv || temp->prev->n < piv))
	{
		rra(a, result, 1);
		return (true);
	}
	return (false);
}

t_bool	smart_rotate_b(t_ps_list **b, t_result **result, int piv)
{
	t_ps_list	*temp;

	temp = *b;
	while (temp->next)
		temp = temp->next;
	if ((*b)->n < piv && (*b)->next->n < piv && (temp->n >= piv || temp->prev->n >= piv))
	{
		rra(b, result, 1);
		return (true);
	}
	return (false);
}

void	smart_swap_a(t_ps_list **a, t_result **result, int len, int number)
{
	if (number - len > 1)
	{
		if ((*a)->n == find_max(a, ft_list_count(a)))
			rra(a, result, 1);
		else if ((*a)->n > (*a)->next->n && (*a)->n - (*a)->next->n < 3)
			sa(a, result, 1);
	}
}

void	smart_swap_b(t_ps_list **b, t_result **result, int len, int number)
{
	if (number - len > 1)
	{
		if ((*b)->n == find_min(b, ft_list_count(b)))
			rrb(b, result, 1);
		else if ((*b)->n < (*b)->next->n && (*b)->next->n - (*b)->n < 3)
			sb(b, result, 1);
	}
}

int	pivot_b(t_ps_list **lst, int len)
{
	t_ps_list	*temp;
	int			half;
	int			pivot;
	t_ps_list	*del;

	temp = copychunk(lst, len);
	bubble_sort(&temp);
	del = temp;
	half = (len / 4);
	while (half--)
		temp = temp->next;
	pivot = temp->n;
	free_struct(&del);
	return (pivot);
}
int	pivot_a(t_ps_list **lst, int len)
{
	t_ps_list	*temp;
	int			half;
	int			pivot;
	t_ps_list	*del;

	temp = copychunk(lst, len);
	bubble_sort(&temp);
	del = temp;
	half = (len / 2) + (len / 4);
	while (half--)
		temp = temp->next;
	pivot = temp->n;
	free_struct(&del);
	return (pivot);
}

int	find_last(t_ps_list **lst)
{
	t_ps_list	*temp;

	temp = *lst;
	while (temp->next)
		temp = temp->next;
	return(temp->n);
}