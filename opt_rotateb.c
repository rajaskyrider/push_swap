/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_rotateb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:49:45 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/15 15:14:37 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fix_rotate_b(t_ps_list **a, t_ps_list **b, \
					t_result **result, int count[2])
{
	while ((count[0]) || (count[1]))
	{
		if (count[0] > 0)
		{
			rrb(b, result, 1);
			count[0]--;
		}
		if (count[1] > 0)
		{
			rra(a, result, 1);
			count[1]--;
		}
	}
}

void	set_initials_b(int pivot[2], int count[2], int len, t_ps_list **b)
{
	count[0] = 0;
	count[1] = 0;
	pivot[0] = choose_pivot(b, len);
	pivot[1] = pivot_b(b, len);
}

int	case_b_alt(t_ps_list **b, t_result **result)
{
	int	count;

	count = 0;
	rb(b, result, 1);
	count++;
	return (count);
}

void	opt_rot_cost(t_ps_list **a, t_ps_list **b, \
						t_result **result, int mix[4])
{
	int	moves[2];
	int	flag[2];

	moves[0] = mix[0];
	moves[1] = mix[1];
	flag[0] = mix[2];
	flag[1] = mix[3];
	while (moves[0] > 0 || moves[1] > 0)
	{
		if (flag[0] == 0 && moves[0] > 0)
			ra(a, result, 1);
		else if (flag[0] == 1 && moves[0] > 0)
			rra(a, result, 1);
		if (flag[1] == 0 && moves[1] > 0)
			rb(b, result, 1);
		else if (flag[1] == 1 && moves[1] > 0)
			rrb(b, result, 1);
		moves[0]--;
		moves[1]--;
	}
}
