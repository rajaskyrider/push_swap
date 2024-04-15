/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:13:20 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/11 16:41:16 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rank(t_ps_list **a)
{
	t_ps_list	*temp;
	t_ps_list	*del;
	t_ps_list	*ranker;
	int			count;

	temp = copylist(a);
	del = temp;
	ranker = *a;
	while (ranker)
	{
		count = 1;
		temp = del;
		while (temp)
		{
			if (ranker->n > temp->n)
				count++;
			temp = temp->next;
		}
		ranker->n = count;
		ranker = ranker->next;
	}
	free_struct(&del);
}