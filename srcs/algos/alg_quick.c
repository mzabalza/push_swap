/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_quick.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 12:01:58 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/16 15:02:29 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

	//ft_putstr("\nnbval: \n");
	//ft_putnbr(group->nbval);
	//ft_putstr("\nmid: \n");
	//ft_putnbr(group->mid);

//mejora posible. Si encuentro un numero que se que es del orden ponerlo en la solucion

/*
**Orders the b stack and puts it in bottom of a
*/
static t_group	*set_groups(t_stack *a, t_stack *b)
{
	t_group *group;
	int moves;
	//t_group *tmp;


	group = ft_new_group(a->nbval, find_mid(a->first, a->nbval));
	// ft_putstr("\nnvbal group: ");
	// ft_putnbr(group->nbval);
	// ft_putstr("  mid: ");
	// ft_putnbr(group->mid);
	// ft_putstr("\n");
	ft_mv_half_b(a, b, group);
	//ft_show_board(*a, *b);
	//HAY QUE ARREGLAR ESTOOO
	if (group->nbval % 2)
		(group->nbval)++;
	group->nbval = (group->nbval/2);
	
	group->mid = find_mid(a->first, group->nbval);
	//aqui esta la mejora
	while (b->nbval > 3)
	{
		moves = ft_mv_half_a(a, b);
		group = ft_add_group(moves, find_mid(a->first, moves), group);
		// ft_show_board(*a, *b);
	}
	//tmp = group;
	// while (tmp)
	// 	{
	// 		ft_putstr("nvbal group: ");
	// 		ft_putnbr(tmp->nbval);
	// 		ft_putstr("  mid: ");
	// 		ft_putnbr(tmp->mid);
	// 		ft_putstr("\n");
	// 		tmp = tmp->prev;
	// 	}
	ft_solve_3bstack(a, b);
	return (group);
}

int				alg_quick(t_stack *a, t_stack *b)
{
	int ordered;
	t_group *group;
	int moves;
	//t_group *tmp;

	//ft_show_board(*a, *b);
	group = set_groups(a, b);
	//ft_show_board(*a, *b);
	ordered = 0;
	while (group || b->nbval)
	//while (ordered < 1)
	{
		//tmp = group;
		// while (tmp)
		// {
		// 	ft_putstr("nvbal group: ");
		// 	ft_putnbr(tmp->nbval);
		// 	ft_putstr("  mid: ");
		// 	ft_putnbr(tmp->mid);
		// 	ft_putstr("\n");
		// 	tmp = tmp->prev;
		// }
		if (group->nbval == 2)
		{
			if (find_mid(a->first, group->nbval) == (a->first)->value)
				ft_exec_s(a, b, 'a');
			ft_exec_r(a, b, 'a');
			ft_exec_r(a, b, 'a');
			group = ft_del_group(group);
		}
		else
		{
			if (group->nbval <= 4)
			{
				ft_mv_group_b(a, b, group);
				group = ft_del_group(group);
			}
			else
			{
				//ft_show_board(*a, *b);
				ordered = ft_mv_half_b(a, b, group);
				//ft_show_board(*a, *b);
				//HAY QUE ARREGLAR ESTOOO
				if (group->nbval % 2)
					(group->nbval)++;
				group->nbval = (group->nbval/2);
				//ft_show_board(*a, *b);
				while (ordered--)
					ft_exec_rr(a, 'a');
				group->mid = find_mid(a->first, group->nbval);
				//ft_show_board(*a, *b);
			}
			//ft_mv_group_b(a, b, group);
			//ft_show_board(*a, *b);
			//group = ft_del_group(group);
			while (b->nbval > 3)
			{
				moves = ft_mv_half_a(a, b);
				group = ft_add_group(moves, find_mid(a->first, moves), group);
				//ft_show_board(*a, *b);
				// ft_putstr("nvbal group: ");
				// ft_putnbr(group->nbval);
				// ft_putstr("  mid: ");
				// ft_putnbr(group->mid);
				// ft_putstr("\n");
			}
			ft_solve_3bstack(a, b);
		}
		// ft_show_board(*a, *b);

	}
	ft_show_board(*a, *b);
	while (group)
	{
		// ft_putstr("nvbal group: ");
		// ft_putnbr(group->nbval);
		// ft_putstr("  mid: ");
		// ft_putnbr(group->mid);
		// ft_putstr("\n");
		group = group->prev;
	}
	return (1);	
	
}
