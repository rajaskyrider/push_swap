/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:01:13 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/25 19:57:55 by rpandipe         ###   ########.fr       */
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

void		sa(t_ps_list **a);
void		sb(t_ps_list **b);
void		ss(t_ps_list **a, t_ps_list **b);
void		pa(t_ps_list **a, t_ps_list **b);
void		pb(t_ps_list **a, t_ps_list **b);
void		ra(t_ps_list **a);
void		rb(t_ps_list **b);
void		rr(t_ps_list **a, t_ps_list **b);
void		rra(t_ps_list **a);
void		rrb(t_ps_list **b);
void		rrr(t_ps_list **a, t_ps_list **b);
t_bool		check_input(int count, char **str, t_ps_list **a);
t_ps_list	*create_node(int n);
void		print_result(t_ps_list **a);
void		free_struct(t_ps_list **lst);

#endif