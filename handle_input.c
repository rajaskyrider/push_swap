/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:29:41 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/25 18:44:44 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	check_number(char *s)
{
	while (*s)
	{
		if (!((*s == '-') || (*s >= '0' && *s <= '9')))
			return (false);
		s++;
	}
	return (true);
}

t_bool	checkoverflow(char *str)
{
	int	digits;
	int	count;

	count = 0;
	if (*str == '-')
		count = 1;
	digits = ft_strlen(str + count);
	if (digits > 10)
		return (true);
	if (digits == 10)
	{
		if (count == 0)
		{
			if (!(ft_strncmp(str, "2147483647", digits) <= 0))
				return (true);
		}
		else
		{
			if (!(ft_strncmp(str, "-2147483648", 11) <= 0))
				return (true);
		}
	}
	return (false);
}

t_bool	addtolst(t_ps_list **a, char *str)
{
	t_ps_list	*temp;
	t_ps_list	*new;
	int			n;

	if (!check_number(str) || checkoverflow(str))
		return (false);
	n = ft_atoi(str);
	if (*a == NULL)
		*a = create_node (n);
	else
	{
		temp = *a;
		while (temp)
		{
			if (temp->n == n)
				return (false);
			if (temp->next == NULL)
				break ;
			temp = temp->next;
		}
		new = create_node(n);
		temp->next = new;
		new->prev = temp;
	}
	return (true);
}

t_bool	dealstr(t_ps_list **a, char *str)
{
	int		i;
	char	*ans;
	t_bool	check;

	while (*str)
	{
		i = 0;
		while (*str && *str == 32)
			str++;
		while (str[i] && str[i] != 32)
			i++;
		if (i > 0)
		{
			ans = ft_calloc((i + 1), sizeof(char));
			if (!ans)
				return (false);
			ft_strlcpy(ans, str, i + 1);
			check = addtolst(a, ans);
			free (ans);
			if (!check)
				return (false);
		}
		str = str + i;
	}
	return (true);
}

t_bool	check_input(int count, char **str, t_ps_list **a)
{
	int	i;

	if (count == 2)
	{
		i = 0;
		while (str[1][i])
		{
			if (str[1][i] >= '0' && str[1][i] <= '9')
			{
				if (!dealstr(a, str[1]))
					return (false);
				else
					return (true);
			}
			i++;
		}
		return (false);
	}
	i = 1;
	while (i < count)
	{
		if (!addtolst(a, str[i++]))
			return (false);
	}
	return (true);
}
