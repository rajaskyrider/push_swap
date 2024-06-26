/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stable_quick_sort_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:59:49 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/12 19:54:04 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_optim_a(t_ps_list **a, t_ps_list **b, t_result **result, int piv)
{
	t_ps_list	*temp;
	int			count;
	int			piv_b;
	int			count_b;
	int			size;

	count = 0;
	count_b = 0;
	temp = *a;
	piv_b = pivot_b(a, ft_list_count(a));
	size = ft_list_count(b);
	while (temp->next)
		temp = temp->next;
	while (temp->prev && (temp->n < piv || temp->prev->n < piv))
	{
		temp = temp->prev;
		rra(a, result, 1);
		if ((*a)->n < piv)
		{
			pb(a, b, result, 1);
			count++;
			if ((*b)->next && (*b)->n < piv_b)
			{
				rb(b, result, 1);
				count_b++;
			}
			else if ((*b)->next &&  (*b)->n < (*b)->next->n)
				sb(b, result, 1);

			//if ((*b)->n == min)
			//	rb(b, result, 1);
			//else if ((*b)->next && (*b)->n < (*b)->next->n)
			//	sb(b , result, 1);
		}
	}
	if ((*a)->n == find_max(a, ft_list_count(a)))
		ra(a, result, 1);
	while (size != 0 && count_b-- > 0)
		rrb(b, result, 1);
	return (count);
}

void	split_a_three(t_ps_list **a, t_ps_list **b, t_result **result, int len)
{
	int	pivot;
	int	count;
	int	number;
	int	size;
	//int	piv_a; //
	int	piv_b;
	int	size_b;
	int	count_b;
	//int	flag;

	count = 0;
	count_b = 0;
	size = ft_list_count(a);
	size_b = ft_list_count(b);
	//flag = 0;
	number = len;
	pivot = choose_pivot(a, len);
	piv_b = pivot_b(a, len);
	//piv_a = pivot_a(a, len);
	if (number == size)
		len -= split_optim_a(a, b, result, pivot);
	while (len != ((number / 2) + (number % 2)))
	{
		if ((*a)->n < pivot && len--)
		{
			/*if ((len - 1) > 0 && (*a)->n > (*a)->next->n)
			{
				sa(a, result, 1);
				pb(a, b, result, 1);
				len--;
			}*/
			//not sure about loop above
			pb(a, b, result, 1);
			if (size_b == 0 && (*b)->next && (*b)->n < piv_b)
			{
				if ((number - len) == 3 && (*b)->n > (*b)->next->next->n)
					sb(b, result, 1);
				else if ((*b)->next)
					rb(b, result, 1);
			}
			else if (size_b != 0 && (*b)->n > piv_b)
			{
				rb(b, result, 1);
				count_b++;
			}
			else
				smart_swap_b(b, result, len, number);
			
			//if ((*b)->next && (*b)->n < (*b)->next->n)
			//	sb(a, result, 1);
			//if (len - 1 > 0 && )
			//flag = 0;
			/*if ((number - len) == ft_list_count(b) && (*b)->n < last_n(b))
			{	
				rb(b, result, 1);
				if ((*b)->n < (*b)->next->n)
					sb(b , result, 1);
			}*/			
		}
		/*else if ((len + count) == ft_list_count(a) && (*a)->n > last_n(a) && flag == 0)
		{
			rra(a, result, 1);
			sa(a, result, 1);
			flag = 1;
		}*/
		else if (number == size && smart_rotate_a(a, result, pivot))
			len -= split_optim_a(a, b, result, pivot);
		else
		{
			//presort a

			ra(a, result, 1);
			count++;
		}
	}
	while ((((number / 2) + (number % 2)) != ft_list_count(a) && count) || (size_b != 0 && count_b))
	{	
		if (count > 0)
		{
			rra(a, result, 1);
			count--;
		}
		if (count_b > 0)
		{
			rrb(b, result, 1);
			count_b--;
		}
	}
	
}

void	st_quick_sort_a(t_ps_list **a, t_ps_list **b, t_result **result, int len)
{
	int	number;

	number = len;
	if (len <= 3)
	{
		sort_three_a(a, b, result, len);
		return ;
	}
	/*else if (len <= 5 && len == ft_list_count(a))
	{
		deal_five(a, &result);
		return ;
	}*/
	split_a_three(a, b, result, len);
	st_quick_sort_a(a, b, result, ((number / 2) + (number % 2)));
	st_quick_sort_b(a, b, result, (number / 2));
}
