/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_3astack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:06:27 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/18 16:06:32 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

static void	ft_solve_2astack(t_stack *a, t_stack *b, t_group *group)
{
	if (find_mid(a->first, group->nbval) == (a->first)->value)
				ft_exec_s(a, b, 'a');
	ft_exec_r(a, b, 'a');
	ft_exec_r(a, b, 'a');
}

t_group		*ft_solve_3astack(t_stack *a, t_stack *b, t_group *group)
{
	//CREO QUE ESTE CASO NO HACE FALTA
	if (group->nbval == 1)
		ft_exec_r(a, b, 'a');
	else if (group->nbval == 2)
		ft_solve_2astack(a, b, group);
	group = ft_del_group(group);
	return (group);
}