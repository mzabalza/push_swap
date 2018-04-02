/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_3bstack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 00:54:51 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/19 22:27:03 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

/*
**First value of b moved to a;First Value is in the second position of b
*/

static void		ft_solve_3bstack3(int b_tmp, t_stack *a, t_stack *b)
{
	ft_exec_p(b, a, 'a');
	ft_exec_p(b, a, 'a');
	ft_exec_r(a, b, 'a');
	if (b_tmp < (a->first)->value)
		ft_exec_s(a, b, 'a');
	ft_exec_r(a, b, 'a');
	ft_exec_r(a, b, 'a');
}

/*
**First Value of b moved to a; two values in b,one of them the first
*/

static void		ft_solve_3bstack2(int b_tmp, t_stack *a, t_stack *b)
{
	if (search_min(b->first) == 0)
	{
		ft_exec_p(b, a, 'a');
		ft_exec_r(a, b, 'a');
		if (b_tmp < (b->first)->value)
		{
			ft_exec_r(a, b, 'a');
			ft_exec_p(b, a, 'a');
			ft_exec_r(a, b, 'a');
		}
		else
		{
			ft_exec_p(b, a, 'a');
			ft_exec_r(a, b, 'a');
			ft_exec_r(a, b, 'a');
		}
	}
	else
		ft_solve_3bstack3(b_tmp, a, b);
}

/*
**Fastest way to solve b stack with 2 values
*/

static void		ft_solve_2bstack(t_stack *a, t_stack *b)
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

/*
**Fastest way to solve b stack with 1,2 or 3 values
*/

void			ft_solve_3bstack(t_stack *a, t_stack *b)
{
	int b_tmp;

	if (b->nbval == 1)
	{
		ft_exec_p(b, a, 'a');
		ft_exec_r(a, b, 'a');
	}
	else if (b->nbval == 2)
		ft_solve_2bstack(a, b);
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
