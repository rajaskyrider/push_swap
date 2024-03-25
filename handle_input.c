/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:29:41 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/25 10:19:19 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_number(char *s)
{
	while (*s)
	{
		if (!((*s == '-') || (*s >= '0' && *s <= '9')))
			return (false);
		s++;
	}
	return (true);
}

bool	checkoverflow(char *str)
{
	int	digits;

	if (*str == '-')
		str++;
	digits = ft_strlen(str);
	if (digits > 10)
		return (true);
	str--;
	if (!((ft_strncmp(str, "2147483647", digits) <= 0) || \
		ft_strncmp(str, "-2147483648", digits) <= 0))
		return (true);
	return (false);
}

bool	addtolst(t_ps_list **a, char *str)
{
	t_ps_list	*temp;
	t_ps_list	*new;
	int			n;

	temp = *a;
	if (!check_number(str) || checkoverflow(str))
		return (false);
	n = ft_atoi(str);
	if (temp == NULL)
		*a = create_node (n);
	else
	{
		while (temp->next != NULL)
		{
			if (temp->n == n || temp->next->n == n)
				return (false);
			temp = temp->next;
		}
		new = create_node(n);
		temp->next = new;
		new->prev = temp;
	}
	return (true);
}

bool	dealstr(t_ps_list **a, char *str)
{
	int		i;
	char	*ans;

	while (*str)
	{
		i = 0;
		while (str[i] && str[i] != 32)
			i++;
		if (str[i] == 32 || str[i] == 0)
		{
			ans = ft_calloc((i + 1), sizeof(char));
			if (!ans)
				return (false);
			ft_strlcpy(ans, str, i + 1);
			if (!addtolst(a, ans))
			{
				free (ans);
				return (false);
			}
			str = str + i + 1;
			free (ans);
		}
	}
	return (true);
}

bool	check_input(int count, char **str, t_ps_list **a)
{
	int	i;

	i = 1;
	if (count == 2)
	{
		if (!dealstr(a, str[1]))
			return (false);
		else
			return (true);
	}
	while (i < count)
	{
		if (!addtolst(a, str[i]))
			return (false);
		i++;
	}
	return (true);
}
