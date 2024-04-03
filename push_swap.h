/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:01:13 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/03 16:59:07 by rpandipe         ###   ########.fr       */
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
void		pa(t_ps_list **a, t_ps_list **b, t_result **result, int id);
void		pb(t_ps_list **a, t_ps_list **b, t_result **result, int id);
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
int		ft_list_count(t_ps_list **a);
void		quick_sort(t_ps_list **lst, t_result **result);

#endif