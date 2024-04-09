/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:56:08 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/09 22:04:16 by rpandipe         ###   ########.fr       */
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