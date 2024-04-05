/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:01:05 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/05 15:20:13 by rpandipe         ###   ########.fr       */
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
#include "quick_sort.c"
#include "deal_three.c"
#include "deal_five.c"
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
	//t_ps_list	*b;
	int			size;

	result = NULL;
	//b = NULL;
	size = ft_list_count(lst);
	if (size <= 3)
		deal_three(lst, &result, size);
	else if (size <= 5)
		deal_five(lst, &result);
	else
		quick_sort(lst, &result); //bubble_sort(lst, &result);
	print_result(result);
	//ft_printf("pb\nra\npb\npb\npb\nra\nra\nra\npb\nra\nra\npb\npb\n");
	free_result(&result);
	//free(b);
}

int	main(int argc, char **argv)
{
	t_ps_list	*a;
	//char *str[] = {"0", "96 30 7 98 66 4 17 22 65 80 39 34 47 16 72 14 88 90 42 31 56 21 86 10 59 9 20 97 75 68 13 73 26 6 89 58 70 94 3 5 18 2 45 81 61 27 46 87 60 32 33 50 51 77 43 36 99 71 49 57 25 29 28 53 48 76 23 62 64 85 8 74 44 83 12 15 91 78 40 41 38 92 52 1 35 24 84 100 63 79 11 69 54 95 67 37 82 19 55", NULL};
	char *str[] = {"0", "96 30 98 7 66 22 40 4", NULL};

	//char *str[] = {"0", "96 30 7 98 66 4 17 22 65 80 39", NULL};
	a = NULL;
	argv = str;
	argc = 2;
	if (argc < 2)
	{
		//ft_printf("Error\n");
		return (0);
	}
	if (!check_input(argc, argv, &a))
	{
		ft_printf("Error\n");
		free_struct(&a);
		return (0);
	}
	sorting_selector(&a);
	//print_a(&a);
	free_struct(&a);
}
