/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:45:22 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/07 21:01:57 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_a(t_ps_list **a)
{
	t_ps_list	*temp;

	temp = *a;
	while (temp)
	{
		ft_printf("%d\n", temp->n);
		if (temp->next == NULL)
			break ;
		temp = temp->next;
	}
}

void	print_result(t_result *result)
{
	while (result)
	{
		if (result->id == 1 || result->id == 42)
			ft_printf("%s\n", result->op);
		result = result->next;
	}
}
