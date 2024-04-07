/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:47:29 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/08 00:12:50 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
#include "handle_input.c"
#include "utils.c"
#include "utils_sort.c"
#include "utils_print.c"
#include "bubble_sort.c"
#include "push.c"
#include "swap.c"
#include "rotate.c"
#include "reverse_rotate.c"
#include "quick_sort.c"
#include "./libft/libft.h"
#include "./libft/ft_printf.h"
#include "./libft/ft_printf.c"
#include "./libft/ft_printstr.c"
#include "./libft/ft_printnbr.c"
#include "./libft/ft_bonus1.c"
#include "./libft/ft_bonus2.c"
#include "./libft/ft_bonussorter.c"
#include "./libft/ft_savestr.c"
#include "./libft/ft_savenbr.c"
#include "./libft/ft_savemem.c"
#include "./libft/ft_width.c"
#include "./libft/ft_nbraux.c"
#include "./libft/ft_precision.c"
#include "./libft/ft_plusaux.c"
#include "./libft/ft_dealcomb.c"
#include "./libft/libft.h"
#include "./libft/ft_putchar_fd.c"
#include "./libft/ft_putstr_fd.c"
#include "./libft/ft_putnbr_fd.c"
#include "./libft/ft_printmem.c"
#include "./libft/ft_strlen.c"
#include "./libft/ft_strlcpy.c"
#include "./libft/ft_isdigit.c"
#include "./libft/ft_memmove.c"
#include "./libft/ft_memcpy.c"
#include "./libft/ft_memset.c"
#include "./libft/ft_itoa.c"
#include "./libft/ft_calloc.c"
#include "./libft/ft_strncmp.c"
#include "./libft/ft_isalnum.c"
#include "./libft/ft_atoi.c"
#include "./libft/get_next_line.c"
#include "./libft/get_next_line_utils.c"
*/
void	free_all(t_ps_list **a, t_ps_list **b, t_result **br, int flag)
{
	free_struct(a);
	free_struct(b);
	free_result(br);
	if (flag)
		write(2, "Error\n", 6);
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
