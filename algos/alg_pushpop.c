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

int		search_min(t_node *list)
{
	int i;
	int tmp;
	int dst;

	i = 0;
	dst = i;
	tmp = list->value;
	while (list)
	{
		
		if (list->value < tmp)
		{
			tmp = list->value;
			dst = i;
		}
		//ft_putnbr(i);
		i++;
		list = list->next;
	}
	//ft_putnbr(dst);
	
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
char		*alg_pushpop(t_stack *a, t_stack *b)
{
	char *dst;
	int minpos;

	dst = NULL;
	while ((a->first)->next)
	{
		minpos = search_min(a->first);
		ft_move_tomin(a, b, minpos);
	}
	/*
	while ((a->first))
	{
		if (!b->first)
		{
			ft_pa(a, b);
			ft_putstr("pb\n");
			//ft_show_board(*a, *b);
		}
		if ((a->first)->value > (b->first)->value)
		{
			ft_pa(a, b);
			ft_putstr("pb\n");
			//ft_show_board(*a, *b);
		}
		else 
		{
			ft_pa(b, a);
			ft_putstr("pa\n");
			//ft_show_board(*a, *b);
			ft_sa(a);
			ft_putstr("sa\n");
			//ft_show_board(*a, *b);
		}
	}
	*/

	while (b->first)
	{
		ft_pa(b, a);
		ft_putstr("pa\n");
	}
	//ft_show_board(*a, *b);
	return (dst);
}