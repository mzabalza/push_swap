/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_pushswap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 06:20:41 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/12 06:20:42 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"


int		search_max(t_node *list)
{
	int i;
	int tmp;
	int dst;

	i = 0;
	dst = i;
	tmp = list->value;
	while (list)
	{
		
		if (list->value > tmp)
		{
			tmp = list->value;
			dst = i;
		}
		i++;
		list = list->next;
	}
	return (dst);
}

static void	ft_move_tomin(t_stack *a, t_stack *b, int dst)
{
	int i;
	int newdst;

	i = a->nbval;
	if (dst > i / 2)
	{
		newdst = (i - dst);
		while (newdst--)
		{
			ft_rra(a);
			ft_putstr("rra\n");
		}
	}
	else
	{
		while (dst--)
		{
			ft_ra(a);
			ft_putstr("ra\n");
		}
	}
	ft_pa(a, b);
	ft_putstr("pb\n");
}

static void		ft_three_order(t_stack *a)
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

char		*alg_pushpop(t_stack *a, t_stack *b)
{
	char *dst;
	int *orders;

	orders = ft_memalloc(8);
	dst = NULL;
	if (is_ordered(a->first) || is_rordered(a->first, a))
		return (dst);
	if (a->nbval < 7 && a->nbval > 3)
		special_case(a, b);
	while (a->nbval > 3)
		ft_move_tomin(a, b, search_min(a->first));
	ft_three_order(a);
	while (b->first)
	{
		ft_pa(b, a);
		ft_putstr("pa\n");
	}
	//ft_show_board(*a, *b);
	return (dst);
}