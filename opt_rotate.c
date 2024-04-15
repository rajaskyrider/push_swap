/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:20:29 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/15 11:51:29 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_initials(int count[2], int size[2], t_ps_list **a, t_ps_list **b)
{
	count[0] = 0;
	count[1] = 0;
	size[0] = ft_list_count(a);
	size[1] = ft_list_count(b);
}

void	case_b(t_ps_list **b, t_result **result, int number, int len)
{
	if ((number - len) == 3 && (*b)->n > (*b)->next->next->n)
		sb(b, result, 1);
	else
		rb(b, result, 1);
}

int	case_a_alt(t_ps_list **a, t_result **result)
{
	int	count;

	count = 0;
	ra(a, result, 1);
	count++;
	return (count);
}

void	fix_rotate(t_ps_list **a, t_ps_list **b, \
					t_result **result, int count[2])
{
	while ((count[0] > 0) || (count[1] > 0))
	{
		if (count[0] > 0)
		{
			rra(a, result, 1);
			count[0]--;
		}
		if (count[1] > 0)
		{
			rrb(b, result, 1);
			count[1]--;
		}
	}
}

int	br(t_ps_list **b, t_result **result, int mix[4])
{
	int	size;
	int	pivot;
	int	number;
	int	len;
	int	count;

	size = mix[0];
	pivot = mix[1];
	number = mix[2];
	len = mix[3];
	count = 0;
	if (size == 0 && (*b)->n < pivot)
		case_b(b, result, number, len);
	else if (size != 0 && (*b)->n > pivot)
	{
		rb(b, result, 1);
		count++;
	}
	else
		smart_swap_b(b, result, len, number);
	return (count);
}
