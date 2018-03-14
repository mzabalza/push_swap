/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ex_and_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 22:53:13 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/14 00:41:18 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void	ft_exec_s(t_stack *a, t_stack *b, char c)
{
	ft_sa(a);
	if (c == 'z')
	{
		ft_sa(b);
		ft_putstr("ss\n");
	}
	else
	{
		ft_putchar('s');
		ft_putchar(c);
		ft_putchar('\n');
	}
}

void	ft_exec_r(t_stack *a, t_stack *b, char c)
{
	ft_ra(a);
	if (c == 'z')
	{
		ft_ra(b);
		ft_putstr("rr\n");
	}
	else
	{
		ft_putchar('r');
		ft_putchar(c);
		ft_putchar('\n');
	}
}

void	ft_exec_rr(t_stack *a, char c)
{
	ft_rra(a);
	ft_putstr("rr");
	ft_putchar(c);
	ft_putchar('\n');
}

void	ft_exec_rrr(t_stack *a, t_stack *b)
{
	ft_rra(a);
	ft_rra(b);
	ft_putstr("rrr\n");
}
