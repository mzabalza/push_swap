/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 06:23:14 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/19 22:44:31 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

int			main(int ac, char **av)
{
	t_stack	*astack;
	t_stack *bstack;
	int		ac_one;

	ac_one = 1;
	if (ac == 2)
	{
		ac = ft_nwords(av[1], ' ');
		av = ft_create_strstack(av[1]);
		ac_one = 0;
	}
	(!ft_checkinp(ac, av, ac_one)) ? ft_show_error() : 0;
	astack = ft_create_astack(ac, av, ac_one);
	if (!ft_check_dupl(astack->first))
	{
		ft_freestack(astack);
		return (ft_show_error());
	}
	bstack = ft_newstack();
	alg_quick(astack, bstack);
	ft_freestack(astack);
	ft_freestack(bstack);
	(!ac_one) ? exit(1) : 0;
	return (1);
}
