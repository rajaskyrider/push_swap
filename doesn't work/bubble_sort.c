/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:56:02 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/07 11:44:23 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_ps_list **lst)
{
	t_ps_list	*a;
	t_ps_list	*b;

	a = *lst;
	b = NULL;
	while (!issorted(&a))
	{
		while (a)
		{
			push(&b, &a);
			if (b->next && b->n < b->next->n)
				swap(&b);
		}
		while (b)
		{
			push(&a, &b);
			if (a->next && a->n > a->next->n)
				swap(&a);
		}
	}
}
