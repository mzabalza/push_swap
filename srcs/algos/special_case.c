/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 22:59:12 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/14 00:42:02 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

static void	ft_distribute(t_stack *a, t_stack *b)
{
	int mid;
	int i;

	i = 0;
	mid = find_mid(a->first, a->nbval);
	while (i <= ((a->nbval) / 2))
	{
		if ((a->first)->value < mid)
		{
			ft_pa(a, b);
			ft_putstr("pb\n");
			i++;
		}
		else
		{
			ft_ra(a);
			ft_putstr("ra\n");
		}
	}
}

static void	ft_reorder(int *orders)
{
	if (orders[0] && orders[0] == orders[2])
	{
		orders[0] = orders[0] + 3;
		orders[2] = 0;
	}
	else if (orders[0] && orders[0] == orders[3])
	{
		orders[0] = 0;
		orders[3] = orders[3] + 3;
	}
	if (orders[1] && orders[1] == orders[2])
	{
		orders[1] = orders[1] + 3;
		orders[2] = 0;
	}
	else if (orders[1] && orders[1] == orders[3])
	{
		orders[1] = 0;
		orders[3] = orders[3] + 3;
	}
}

int			special_case(t_stack *a, t_stack *b)
{
	int *orders;
	int i;

	if (!(orders = ft_memalloc(16)))
		return (0);
	ft_distribute(a, b);
	i = 0;
	while (i < 2)
	{
		orders[i] = ft_order(a);
		i++;
	}
	while (i < 4)
	{
		orders[i] = ft_xorder(b);
		i++;
	}
	ft_retrack(orders, a);
	ft_retrack(&orders[2], b);
	ft_reorder(orders);
	exec_orders(orders, a, b, 'a');
	exec_orders(&orders[2], b, a, 'b');
	free(orders);
	return (1);
}
