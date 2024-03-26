/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:56:02 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/26 19:59:03 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_ps_list **lst, t_result **result)
{
	t_ps_list	*a;
	t_ps_list	*b;
	int			id;

	id = 0;
	a = copylist(lst);
	b = NULL;
	while (!issorted(&a))
	{
		while (a)
		{
			pb(&a, &b, result, id);
			if (b->next && b->n < b->next->n)
				sb(&b, result, id);
		}
		while (b)
		{
			pa(&a, &b, result, id);
			if (a->next && a->n > a->next->n)
				sa(&a, result, id);
		}
	}
	free_struct(&a);
}
