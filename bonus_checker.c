/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:45:22 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/22 15:07:31 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_result(t_ps_list **a)
{
	t_ps_list *temp;
	
	temp = *a;
	while (temp)
	{
		ft_printf("%d\n", temp->n);
		if (temp->next != NULL)
			break ;
		temp = temp->next;
	}
}