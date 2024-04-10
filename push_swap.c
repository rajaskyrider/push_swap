/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:01:05 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/09 23:38:28 by rpandipe         ###   ########.fr       */
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
#include "quick_sort_a.c"
#include "quick_sort_b.c"
#include "quick_sort_utils.c"
#include "deal_three.c"
#include "deal_five.c"
#include "post_opt.c"
#include "utils_opt.c"
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
	//char *str[] = {"0", "31 73 93 65 87 45 24 46 53 26 40 42 56 3 50 86 98 69 19 20 54 77 81 29 30 14 80 37 92 9 62 96 38 13 72 8 83 79 71 35 97 7 91 12 22 67 11 52 59 90 21 28 49 63 82 95 4 55 60 75 61 47 64 5 39 57 2 99 78 10 17 34 43 41 27 58 89 66 85 48 36 76 32 15 88 18 6 33 1 94 84 25 16 51 70 23 68 100 74 44", NULL};
	//char	*str[] = {"0", "-2147483648 0 -2147483647 9487 2147483647", NULL};
	//714 32 18 92 14 55 82 38 67 94 12 54 26 36 73 80 2 44 65 71 64 15 81 78 27 30 89 53 13 5 63 58 43 88 24 4 17 33 34 62 9 90 0 35 47 7 75 87 42 60 19 20 29 76 11 59 86 57 91 48 22 6 70 10 49 16 41 52 21 93 66 45 96 72 31 37 39 97 51 50 46 77 25 98 85 1 74 83 79 40 56 3 95 68 8 23 99 84 28 69 61
	//717 30 33 59 97 44 73 81 49 20 7 46 35 12 76 6 90 99 8 15 42 61 13 54 56 80 72 60 98 37 17 89 3 4 70 55 66 48 21 88 91 52 0 50 45 11 85 84 79 75 19 27 23 16 62 95 32 38 40 64 92 83 41 74 2 68 5 47 43 87 67 93 10 9 53 29 18 82 26 78 36 86 34 39 57 69 77 28 51 94 14 24 71 63 58 22 1 25 96 65 31
	//719 18 57 70 31 50 23 38 77 42 25 59 41 14 33 78 51 83 60 8 6 45 81 61 87 0 53 71 7 46 2 80 66 68 17 58 29 97 94 74 95 9 99 12 55 1 64 20 54 91 30 84 56 37 98 69 34 93 43 90 73 27 16 10 5 24 96 49 63 19 62 92 35 76 65 28 21 88 40 48 4 82 44 47 85 72 11 86 67 26 75 39 15 32 52 13 89 36 79 22 3
	//char *str[] = {"0", "10 9 8 7 6 5 4 3 2 1", NULL};
	//char *str[] = {"0", "3 4 6 10 5 8 9 7 2 1", NULL};
	//10 8 2 6 7 4 9 3 1 5
	//6 2 10 8 7 3 5 9 1 4

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
