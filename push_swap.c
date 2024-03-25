/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:01:05 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/25 19:53:19 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "handle_input.c"
#include "utils.c"
#include "bonus_checker.c"
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

void	sorting_selector(t_ps_list **lst)
{
	int			s[3];
	t_result	*result;

	s[0] = bubble_sort(lst, &result, 0);
}

int	main(int argc, char **argv)
{
	t_ps_list	*a;
	char *str[] = {"0", "1", "2", "3", NULL};

	a = NULL;
	argv = str;
	argc = 2;
	if (argc < 2)
		return (0);
	if (!check_input(argc, argv, &a))
	{
		free_struct(&a);
		return (0);
	}
	sorting_selector(&a);
	print_result(&a);
	free_struct(&a);
}
