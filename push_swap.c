/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:01:05 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/15 10:08:18 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_result(t_result **result1, t_result **result2, int count[2])
{
	t_result	*temp1;
	t_result	*temp2;

	sort_opt(result1);
	sort_opt(result2);
	temp1 = *result1;
	temp2 = *result2;
	count[0] = 0;
	count[1] = 0;
	while (temp1)
	{
		count[0]++;
		temp1 = temp1->next;
	}
	while (temp2)
	{
		count[1]++;
		temp2 = temp2->next;
	}
}

void	choose_result(t_result *r1, t_result *r2, t_result **r, int count[2])
{
	if (count[0] < count[1])
	{
		*r = r1;
		free_result(&r2);
	}
	else
	{
		*r = r2;
		free_result(&r1);
	}
}

void	choose_sorter(t_ps_list **a, t_ps_list **b, t_result **result, int size)
{
	t_ps_list	*dup_a;
	t_ps_list	*dup_b;
	t_result	*result1;
	t_result	*result2;
	int			count[2];

	dup_a = copylist(a);
	dup_b = NULL;
	result1 = NULL;
	result2 = NULL;
	insertion_sort(a, b, &result1, size);
	quick_sort_a(&dup_a, &dup_b, &result2, size);
	count_result(&result1, &result2, count);
	choose_result(result1, result2, result, count);
	if (dup_b)
		free_struct(&dup_b);
	free_struct(&dup_a);
}

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
		choose_sorter(lst, &b, &result, size);
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
	if (argc < 2)
		return (0);
	if (!check_input(argc, argv, &a))
	{
		free_struct(&a);
		print_error();
	}
	rank(&a);
	sorting_selector(&a);
	free_struct(&a);
}
