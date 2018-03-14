/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_pushpop2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 06:20:41 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/07 04:03:06 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

static void	ft_move_tomin(t_stack *a, t_stack *b, int dst)
{
	int newdst;

	if (dst > (a->nbval) / 2)
	{
		newdst = ((a->nbval) - dst);
		while (newdst--)
		{
			ft_rra(a);
			ft_putstr("rra\n");
		}
	}
	else
	{
		while (dst-- > 0)
		{
			ft_ra(a);
			ft_putstr("ra\n");
		}
	}
	ft_pa(a, b);
	ft_putstr("pb\n");
}

static void	ft_move_tomax(t_stack *a, t_stack *b, int dst)
{
	int newdst;

	if (dst > (a->nbval) / 2)
	{
		newdst = ((a->nbval) - dst);
		while (newdst--)
		{
			ft_rra(a);
			ft_putstr("rrb\n");
		}
	}
	else
	{
		while (dst-- > 0)
		{
			ft_ra(a);
			ft_putstr("rb\n");
		}
	}
	ft_pa(a, b);
	ft_putstr("pa\n");
}

static void	ft_three_order(t_stack *a)
{
	if (is_ordered(a->first))
		return ;
	if (a->nbval == 2)
	{
		ft_sa(a);
		ft_putstr("sa\n");
	}
	else if (search_max(a->first) + 1 == a->nbval)
	{
		ft_sa(a);
		ft_putstr("sa\n");
	}
	else if (search_max(a->first) == 0)
	{
		ft_ra(a);
		ft_putstr("ra\n");
		ft_three_order(a);
	}
	else
	{
		ft_rra(a);
		ft_putstr("rra\n");
		ft_three_order(a);
	}
}

int			alg_pushpop2(t_stack *a, t_stack *b)
{
	t_stack *c;
	int		margin;
	int		i;

	margin = a->max_margin;
	if (is_ordered(a->first) || is_rordered(a->first, a))
		return (1);
	if (a->nbval < 7 && a->nbval > 3)
		if ((special_case(a, b) == 0))
			return (0);
	c = ft_create_cstack(a->first);
	c = ft_bubble_sort(c);
	while (a->nbval > 3)
	{
		i = find_closer(a->first, c, &margin);
		ft_move_tomin(a, b, i);
		if (a->nbval <= 3 + a->max_margin + 1)
			margin = 0;
	}
	ft_three_order(a);
	while (b->nbval)
		ft_move_tomax(b, a, search_max(b->first));
	ft_freestack(c);
	return (1);
}
