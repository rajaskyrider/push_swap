/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:01:13 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/22 15:08:00 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef	enum {
    false,
    true
} bool;

typedef struct psl_list
{
	int				n;
	struct psl_list	*next;
	struct psl_list	*prev;
}					t_ps_list;

void	sa(t_ps_list **a);
void	sb(t_ps_list **b);
void	ss(t_ps_list **a, t_ps_list **b);
void	pa(t_ps_list **a, t_ps_list **b);
void	pb(t_ps_list **a, t_ps_list **b);
void	ra(t_ps_list **a);
void	rb(t_ps_list **b);
void	rr(t_ps_list **a, t_ps_list **b);
void	rra(t_ps_list **a);
void	rrb(t_ps_list **b);
void	rrr(t_ps_list **a, t_ps_list **b);
bool	check_input(int count, char** str, t_ps_list **a);
t_ps_list	*create_node (int n);
void	print_result(t_ps_list **a);

#endif