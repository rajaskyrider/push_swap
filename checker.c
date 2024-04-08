/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:47:29 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/08 16:40:44 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_ps_list **a, t_ps_list **b, t_result **br, int flag)
{
	free_struct(a);
	free_struct(b);
	free_result(br);
	if (flag)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
}

void	execute_sort(t_ps_list **a, char *instrn, t_result **br, t_ps_list **b)
{
	if (ft_strncmp(instrn, "sa\n", 4) == 0)
		sa(a, br, 99);
	else if (ft_strncmp(instrn, "sb\n", 4) == 0)
		sb(b, br, 99);
	else if (ft_strncmp(instrn, "ss\n", 4) == 0)
		ss(a, b, br, 99);
	else if (ft_strncmp(instrn, "pa\n", 4) == 0)
		pa(a, b, br, 99);
	else if (ft_strncmp(instrn, "pb\n", 4) == 0)
		pb(a, b, br, 99);
	else if (ft_strncmp(instrn, "ra\n", 4) == 0)
		ra(a, br, 99);
	else if (ft_strncmp(instrn, "rb\n", 4) == 0)
		rb(b, br, 99);
	else if (ft_strncmp(instrn, "rr\n", 4) == 0)
		rr(a, b, br, 99);
	else if (ft_strncmp(instrn, "rra\n", 4) == 0)
		rra(a, br, 99);
	else if (ft_strncmp(instrn, "rrb\n", 4) == 0)
		rrb(b, br, 99);
	else if (ft_strncmp(instrn, "rrr\n", 4) == 0)
		rrr(a, b, br, 99);
	else
		free_all(a, b, br, 1);
}

int	main(int argc, char**argv)
{
	t_ps_list	*a;
	t_ps_list	*b;
	t_result	*bresult;
	char		*instrn;

	a = NULL;
	b = NULL;
	bresult = NULL;
	if (argc > 1 && check_input(argc, argv, &a))
	{
		instrn = get_next_line(0);
		while (instrn)
		{
			execute_sort(&a, instrn, &bresult, &b);
			free(instrn);
			instrn = get_next_line(0);
		}
		if (issorted(&a))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		free_all(&a, &b, &bresult, 0);
	}
	return (0);
}
