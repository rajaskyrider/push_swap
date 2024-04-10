/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:01:13 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/10 12:51:07 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef enum e_bool{
	false,
	true
}	t_bool;

typedef struct s_ps_list
{
	int					n;
	struct s_ps_list	*next;
	struct s_ps_list	*prev;
}	t_ps_list;

typedef struct s_result
{
	int				id;
	char			*op;
	struct s_result	*next;
}				t_result;

void		sa(t_ps_list **a, t_result **result, int id);
void		sb(t_ps_list **b, t_result **result, int id);
void		ss(t_ps_list **a, t_ps_list **b, t_result **result, int id);
t_bool		swap(t_ps_list **lst);
void		pa(t_ps_list **a, t_ps_list **b, t_result **result, int id);
void		pb(t_ps_list **a, t_ps_list **b, t_result **result, int id);
t_bool		push(t_ps_list **destinationlist, t_ps_list **sourcelist);
void		ra(t_ps_list **a, t_result **result, int id);
void		rb(t_ps_list **b, t_result **result, int id);
void		rr(t_ps_list **a, t_ps_list **b, t_result **result, int id);
void		rra(t_ps_list **a, t_result **result, int id);
void		rrb(t_ps_list **b, t_result **result, int id);
void		rrr(t_ps_list **a, t_ps_list **b, t_result **result, int id);
t_bool		check_input(int count, char **str, t_ps_list **a);
t_ps_list	*create_node(int n);
void		print_result(t_result *result);
void		print_a(t_ps_list **a);
void		free_struct(t_ps_list **lst);
void		free_result(t_result **lst);
t_bool		issorted(t_ps_list **a);
t_ps_list	*copylist(t_ps_list **a);
void		addentry(t_result **result, char *op, int id);
void		bubble_sort(t_ps_list **lst);
int			ft_list_count(t_ps_list **a);
void		quick_sort_a(t_ps_list **a, t_ps_list **b, \
							t_result **result, int len);
void		quick_sort_b(t_ps_list **a, t_ps_list **b, \
							t_result **result, int len);
int			choose_pivot(t_ps_list **lst, int len);
t_ps_list	*copychunk(t_ps_list **a, int len);
void		split_list(t_ps_list **a, t_ps_list **b, \
						t_result **result, int piv);
void		deal_three(t_ps_list **a, t_result **result, int size);
void		deal_five(t_ps_list **a, t_result **result);
void		combine(t_ps_list **a, t_ps_list **b, t_result **result);
t_result	*ft_last(t_result **result);
int			choose_avg(t_ps_list **lst);
void		print_error(void);
void		sort_opt(t_result **result);
int			last_n(t_ps_list **b);
int			find_max(t_ps_list **lst, int len);
int			find_min(t_ps_list **lst, int len);
t_bool		smart_rotate_a(t_ps_list **a, t_result **result, int piv);

#endif