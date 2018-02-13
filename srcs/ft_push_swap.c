/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 06:23:14 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/12 06:23:17 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

int			main(int ac, char **av)
{
	t_stack *astack;
	t_stack *bstack;

	//if (ac == 1)
	//	return (0);
	//if (!ft_checkinp(ac, av))
	//	return (ft_showError());
	astack = ft_create_astack(ac, av);
	if (!ft_check_dupl(astack->first))
		return (ft_showError());
	bstack = ft_newstack();
	//ft_show_board(*astack, *bstack);
	alg_pushpop(astack, bstack);
	//alg_div_conquer(astack, bstack);

	return (1);
}
