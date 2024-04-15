/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_opt_misc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:07:57 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/15 15:08:26 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (temp->n);
}

t_bool	cont_split(t_ps_list **a, int piv_a)
{
	t_ps_list	*temp;

	temp = *a;
	while (temp)
	{
		if (temp->n > piv_a)
			return (true);
		temp = temp->next;
	}
	return (false);
}
