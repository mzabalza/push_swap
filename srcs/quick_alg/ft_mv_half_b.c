/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv_half_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 12:42:13 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/16 15:02:33 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

/*
**Receives a, b stacks; finds middle value from b; moves half of a to b
**c is the destiny
**returns nº values moved
*/
int		ft_mv_half_a(t_stack *a, t_stack *b)
{
	int 	i;
	int		mid;
	int		moves;
	int		min;

	moves = b->nbval / 2;
	mid = find_mid(b->first, b->nbval);
	// ft_putstr("\nmoves: ");
	// ft_putnbr(moves);
	
	// ft_putstr("\nmid: ");
	if ((b->nbval) % 2)
		moves++;
	i = moves;
	//NO BUSCA EL VALOR SINO LA POSICION. HACER FUNCION QUE ME BUSQUE EL MIN
	min = search_min(b->first);
	while(i)
	{
		// ft_putstr("\nfirst: ");
		// ft_putnbr((b->first)->value);
		// ft_putstr("\nmid: ");
		// ft_putnbr(mid);
		// ft_putstr("\n");
		if ((b->first)->value >= mid)
		{
			if ((b->first)->value == min)
			{
				ft_show_board(*a, *b);
				ft_exec_p(b, a, 'a');
				ft_exec_r(a, b, 'a');
				moves--;
				min = search_min(b->first);
				ft_show_board(*a, *b);
			}
			else
				ft_exec_p(b, a, 'a');
			i--;
			// ft_show_board(*a, *b);
			
		}
		else
		{
			ft_exec_r(b, a, 'b');
			// ft_show_board(*a, *b);
		}
	}
	return (moves);
}
/*
**Receives a, b stacks; finds middle value from a; moves half of a to b
**c is the destiny
**returns nº values moved
*/
//MEJORA AQUI. EN VEZ DE PASAR TODO PASAR LA MITAD BUENA Y LA OTRA RA, Y CUANDO ACABE RRA (ES MAS CORTO)
void	ft_mv_group_b(t_stack *a, t_stack *b, t_group *group)
{
	int i;
	int moves;

	moves = (group->nbval);
	i = moves;
	while(i)
	{
		ft_exec_p(a, b, 'b');
		i--;
	}	
}

int		ft_mv_half_b(t_stack *a, t_stack *b, t_group *group)
{
	int i;
	int moves;
	int j;

	j = 0;
	moves = (group->nbval) / 2;
	i = moves;
	while(i)
	{
		if ((a->first)->value < group->mid)
		{
			i--;
			ft_exec_p(a, b, 'b');
		}
		else
		{
			j++;
			ft_exec_r(a, b, 'a');
		}
	}
	return (j);
}
