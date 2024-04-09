/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:01:05 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/09 09:40:16 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "handle_input.c"
#include "utils.c"
#include "utils_sort.c"
#include "utils_print.c"
#include "bubble_sort.c"
#include "push.c"
#include "swap.c"
#include "rotate.c"
#include "reverse_rotate.c"
#include "quick_sort_a.c"
#include "quick_sort_b.c"
#include "quick_sort_utils.c"
#include "deal_three.c"
#include "deal_five.c"
#include "post_opt.c"
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
	t_result	*result;
	t_ps_list	*b;
	int			size;

	result = NULL;
	b = NULL;
	if (issorted(lst))
		return ;
	size = ft_list_count(lst);
	if (size <= 3)
		deal_three(lst, &result, size);
	else if (size <= 5)
		deal_five(lst, &result);
	else
		quick_sort_a(lst, &b, &result, size);
	sort_opt(&result);
	print_result(result);
	free_result(&result);
	if (b)
		free_struct(&b);
	b = NULL;
}

int	main(int argc, char **argv)
{
	t_ps_list	*a;

	a = NULL;

	//char *str[] = {"0", "27 60 7 24 5 59 4 33 67 57 54 58 62 82 86 94 13 76 66 42 21 98 85 72 9 81 87 37 49 16 36 17 20 30 61 73 28 11 75 64 95 51 8 89 48 10 55 1 2 56 71 25 45 23 31 77 65 69 78 88 40 74 35 91 80 34 97 99 68 15 26 79 47 32 83 93 39 84 53 46 6 0 63 14 19 43 12 50 52 22 3 90 96 41 29 44 70 92 18 38", NULL};
	//argv = str;
	//argc = 2;

	if (argc < 2)
		return (0);
	if (!check_input(argc, argv, &a))
	{
		free_struct(&a);
		print_error();
	}
	sorting_selector(&a);
	free_struct(&a);
}
