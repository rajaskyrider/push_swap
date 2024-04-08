/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:01:05 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/08 18:56:29 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
