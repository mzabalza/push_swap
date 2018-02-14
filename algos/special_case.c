/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 22:59:12 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/13 22:59:14 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_checker.h"

/*
** 1 elemento
** 2 elemento
** 3 elemento
** 4 elemento
** 5 elemento
*/

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

int		ft_xorder(t_stack *a)
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

int		ft_order(t_stack *a)
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
//me falta ponerle 'b' cuando sea b
void		exec_orders(int *orders, t_stack *a, t_stack *b)
{
	int i;

	i = 0;
	while (i < 2)
	{
		if (orders[i] == 1)
		{
			ft_sa(a);
			ft_putstr("sa\n");
		}
		if (orders[i] == 2)
		{
			ft_ra(a);
			ft_putstr("ra\n");
		}
		if (orders[i] == 3)
		{
			ft_rra(a);
			ft_putstr("rra\n");
		}
		if (orders[i] == 4)
		{
			ft_sa(a);
			ft_sa(b);
			ft_putstr("ss\n");
		}
		if (orders[i] == 5)
		{
			ft_ra(a);
			ft_ra(b);
			ft_putstr("rr\n");
		}
		if (orders[i] == 6)
		{
			ft_rra(a);
			ft_rra(b);
			ft_putstr("rrr\n");
		}
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

void		special_case(t_stack *a, t_stack *b)
{
	int *orders;
	int i;

	orders = ft_memalloc(16);
	ft_distribute(a, b);
	ft_show_board(*a, *b);
	i = 0;
	while (i < 2)
	{
		orders[i] = ft_order(a);
		i++;
	}
	ft_show_board(*a, *b);
	
	i = 2;
	while (i < 4)
	{
		orders[i] = ft_xorder(b);
		i++;
	}
	ft_putnbr(orders[0]);
	ft_putnbr(orders[1]);
	ft_retrack(orders, a);
	ft_retrack(&orders[2], b);

	if (orders[0] && orders[0] == orders[2])
	{
		orders[0] = orders[0] + 3;
		orders[2] = 0;
	}
	if (orders[0] && orders[0] == orders[3])
	{
		orders[0] = 0;
		orders[3] = orders[3] + 3;
	}
	if (orders [1] && orders[1] == orders[2])
	{
		orders[0] = orders[0] + 3;
		orders[3] = 0;
	}
	if (orders [1] && orders[1] == orders[3])
	{
		orders[0] = 0;
		orders[3] = orders[3] + 3;
	}

	exec_orders(orders, a, b);
	exec_orders(&orders[2], b, a);
	ft_show_board(*a, *b);
}












