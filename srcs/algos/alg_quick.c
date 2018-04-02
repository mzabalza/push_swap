/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_quick.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 12:01:58 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/29 18:13:00 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

/*
**Orders the b stack and puts it in bottom of a
*/

static t_group	*set_groups(t_stack *a, t_stack *b)
{
	t_group	*group;
	int		moves;

	group = ft_new_group(a->nbval, find_mid(a->first, a->nbval));
	ft_mv_half_b(a, b, group);
	if (group->nbval % 2)
		(group->nbval)++;
	group->nbval = (group->nbval / 2);
	group->mid = find_mid(a->first, group->nbval);
	while (b->nbval > 3)
	{
		moves = ft_mv_half_a(a, b);
		group = ft_add_group(moves, find_mid(a->first, moves), group);
	}
	if (b->nbval)
		ft_solve_3bstack(a, b);
	return (group);
}

static void		ft_move_minto_a(t_stack *a, t_stack *b, int dst)
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
	ft_ra(b);
	ft_putstr("ra\n");
}

int				alg_quick(t_stack *a, t_stack *b)
{
	t_group	*group;
	int		moves;

	if (a->nbval < 80)
		return (alg_pushpop2(a, b));
	group = set_groups(a, b);
	while (group || b->nbval)
	{
		if (group->nbval <= 2)
			group = ft_solve_3astack(a, b, group);
		else
			group = ft_solve_astack(a, b, group);
		while (b->nbval > 14)
		{
			moves = ft_mv_half_a(a, b);
			group = ft_add_group(moves, find_mid(a->first, moves), group);
		}
		while (b->nbval > 3)
			ft_move_minto_a(b, a, search_min(b->first));
		if (b->nbval)
			ft_solve_3bstack(a, b);
	}
	return (1);
}
