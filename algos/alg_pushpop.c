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

char		*alg_pushpop(t_stack *a, t_stack *b)
{
	char *dst;

	dst = NULL;
	//ft_show_board(*a, *b);
	//ft_pa(a, b);
	while (a->first)
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
	while (b->first)
	{
		ft_pa(b, a);
		ft_putstr("pa\n");
	}
	//ft_show_board(*a, *b);
	return (dst);
}