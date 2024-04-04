/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:01:05 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/04 18:14:50 by rpandipe         ###   ########.fr       */
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
*/

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
	free_result(&result);
	//free(b);
}

int	main(int argc, char **argv)
{
	t_ps_list	*a;
	//char *str[] = {"0", "5", "4", "3", "2", "1", NULL};
	//char *str[] = {"0", "4", "67", "3", "87", "23", NULL};

	a = NULL;
	//argv = str;
	//argc = 6;
	if (argc < 2)
	{
		ft_printf("Error\n");
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
