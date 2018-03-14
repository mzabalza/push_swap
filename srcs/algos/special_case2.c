/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 00:07:11 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/14 00:09:00 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

int			ft_xorder(t_stack *a)
{
	if (is_xordered(a->first))
		return (0);
	if (a->nbval == 2)
	{
		ft_sa(a);
		return (1);
	}
	else if (search_min(a->first) + 1 == a->nbval)
	{
		ft_sa(a);
		return (1);
	}
	else if (search_min(a->first) == 0)
	{
		ft_ra(a);
		return (2);
	}
	else
	{
		ft_rra(a);
		return (3);
	}
}

int			ft_order(t_stack *a)
{
	if (is_ordered(a->first))
		return (0);
	if (a->nbval == 2)
	{
		ft_sa(a);
		return (1);
	}
	else if (search_max(a->first) + 1 == a->nbval)
	{
		ft_sa(a);
		return (1);
	}
	else if (search_max(a->first) == 0)
	{
		ft_ra(a);
		return (2);
	}
	else
	{
		ft_rra(a);
		return (3);
	}
}

void		exec_orders(int *orders, t_stack *a, t_stack *b, char c)
{
	int i;

	i = 0;
	while (i < 2)
	{
		if (orders[i] == 1)
			ft_exec_s(a, b, c);
		if (orders[i] == 2)
			ft_exec_r(a, b, c);
		if (orders[i] == 3)
			ft_exec_rr(a, c);
		if (orders[i] == 4)
			ft_exec_s(a, b, 'z');
		if (orders[i] == 5)
			ft_exec_r(a, b, 'z');
		if (orders[i] == 6)
			ft_exec_rrr(a, b);
		i++;
	}
}

void		ft_retrack(int *orders, t_stack *a)
{
	int i;

	i = 1;
	while (i > -1)
	{
		if (orders[i] == 1)
			ft_sa(a);
		if (orders[i] == 2)
			ft_rra(a);
		if (orders[i] == 3)
			ft_ra(a);
		i--;
	}
}
