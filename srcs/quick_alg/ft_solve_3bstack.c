/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_3bstack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 00:54:51 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/18 00:54:54 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

static void			ft_solve_3bstack2(int b_tmp, t_stack *a, t_stack *b)
{
	if (search_min(b->first) == 0)
	{
		ft_exec_p(b, a, 'a');
		ft_exec_r(a, b, 'a');
		// ft_show_board(*a, *b);
		// ft_putstr("\nvalor b_tmp: ");
		// ft_putnbr(b_tmp);
		// ft_putstr("\nvalor (b->first)->value: ");
		// ft_putnbr((b->first)->value);
		if (b_tmp < (b->first)->value)
		{
			ft_exec_r(a, b, 'a');
			ft_exec_p(b, a, 'a');
			ft_exec_r(a, b, 'a');
			//ft_show_board(*a, *b);
		}
		else
		{
			ft_exec_p(b, a, 'a');
			ft_exec_r(a, b, 'a');
			ft_exec_r(a, b, 'a');
		}
	}
	else
	{
		ft_exec_p(b, a, 'a');
		ft_exec_p(b, a, 'a');
		ft_exec_r(a, b, 'a');
		if (b_tmp < (a->first)->value)
			ft_exec_s(a, b, 'a');
		ft_exec_r(a, b, 'a');
		ft_exec_r(a, b, 'a');
	}
}

static void			ft_solve_2bstack(t_stack *a, t_stack *b)
{
	if (search_min(b->first) == 0)
	{
		ft_exec_p(b, a, 'a');
		ft_exec_r(a, b, 'a');
		ft_exec_p(b, a, 'a');
		ft_exec_r(a, b, 'a');
	}
	else
	{
		ft_exec_p(b, a, 'a');
		ft_exec_p(b, a, 'a');
		ft_exec_r(a, b, 'a');
		ft_exec_r(a, b, 'a');
	}
}

void			ft_solve_3bstack(t_stack *a, t_stack *b)
{
	//SI HAY UNA SOLA ESTO PUEDE DARME PROBLEMAS
	//mucho que mejorar el de 3. Siempre con 6 moves me vale
	int b_tmp;
	if (b->nbval == 2)
	{
		ft_solve_2bstack(a, b);
	}
	else
	{
		if (search_min(b->first) == 0)
		{
			ft_exec_p(b, a, 'a');
			ft_exec_r(a, b, 'a');
			ft_solve_2bstack(a, b);
		}
		else
		{
			ft_exec_p(b, a, 'a');
			b_tmp = (a->first)->value;
			ft_solve_3bstack2(b_tmp, a, b);
		}
	}
}