/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_pushpop2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 06:20:41 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/12 06:20:42 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

//llamale move to
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

char		*alg_pushpop2(t_stack *a, t_stack *b)
{
	char 	*dst;
	int 	*orders;
	t_stack *c;
	int		margin;
	int		i;
	//int		j;

	margin = 30;
	orders = ft_memalloc(8);
	dst = NULL;
	if (is_ordered(a->first) || is_rordered(a->first, a))
		return (dst);
	if (a->nbval < 7 && a->nbval > 3)
		special_case(a, b);
	c = ft_create_cstack(a->first);
	c = ft_bubble_sort(c);
	//j = 0;
	while (a->nbval > 3)
	{
		i = find_closer(a->first, c, &margin, a->nbval);
		//ft_putnbr(i);
		//ft_putchar('|');
		//ft_putnbr(margin);
		//ft_putchar('\n');
		ft_move_tomin(a, b, i);
		if (a->nbval <= 3 + 31)
			margin = 0;
		//ft_show_board(*a, *b);
		//j++;
	}
	//ft_show_board(*a, *b);
	ft_three_order(a);
	while (b->nbval)
	{
		ft_move_tomax(b, a, search_max(b->first));
	}
	//while (b->first)
	//{
	//	ft_pa(b, a);
	//	ft_putstr("pa\n");
	//}
	//ft_show_board(*a, *b);
	return (dst);
}
