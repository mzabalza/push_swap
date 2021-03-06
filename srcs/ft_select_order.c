/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_order.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 05:32:20 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/07 05:45:44 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

static int	ft_select_order2(char *order, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(order, "rr"))
	{
		ft_ra(a);
		ft_ra(b);
	}
	else if (!ft_strcmp(order, "rra"))
		ft_rra(a);
	else if (!ft_strcmp(order, "rrb"))
		ft_rra(b);
	else if (!ft_strcmp(order, "rrr"))
	{
		ft_rra(a);
		ft_rra(b);
	}
	else
		return (0);
	return (1);
}

int			ft_select_order(char *order, t_stack *a, t_stack *b)
{
	t_stack *tmp;

	tmp = b;
	if (!ft_strcmp(order, "sa"))
		ft_sa(a);
	else if (!ft_strcmp(order, "sb"))
		ft_sa(b);
	else if (!ft_strcmp(order, "ss"))
	{
		ft_sa(a);
		ft_sa(b);
	}
	else if (!ft_strcmp(order, "pb"))
		ft_pa(a, b);
	else if (!ft_strcmp(order, "pa"))
		ft_pa(b, a);
	else if (!ft_strcmp(order, "ra"))
		ft_ra(a);
	else if (!ft_strcmp(order, "rb"))
		ft_ra(b);
	else
		return (ft_select_order2(order, a, b));
	return (1);
}
