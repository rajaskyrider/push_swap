/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 17:00:05 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/08 16:43:00 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_list	*copychunk(t_ps_list **a, int len)
{
	t_ps_list	*copyhead;
	t_ps_list	*copy;
	t_ps_list	*tcpy;
	t_ps_list	*temp;

	copyhead = create_node((*a)->n);
	copy = copyhead;
	temp = (*a)->next;
	len--;
	while (len > 0)
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
		len--;
	}
	copy->next = NULL;
	return (copyhead);
}

int	choose_pivot(t_ps_list **lst, int len)
{
	t_ps_list	*temp;
	int			half;
	int			pivot;
	t_ps_list	*del;

	temp = copychunk(lst, len);
	bubble_sort(&temp);
	del = temp;
	half = (len / 2);
	while (half--)
		temp = temp->next;
	pivot = temp->n;
	free_struct(&del);
	return (pivot);
}
