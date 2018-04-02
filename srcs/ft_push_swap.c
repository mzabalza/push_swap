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

	if (ac == 1)
		return (0);
	ac_one = 1;
	if (ac == 2)
	{
		ac = ft_nwords(av[1], ' ');
		av = ft_create_strstack(av[1]);
		ac_one = 0;
	}
	if (!ft_checkinp(ac, av, ac_one))
		return (ft_show_error());
	astack = ft_create_astack(ac, av, ac_one);
	if (!ft_check_dupl(astack->first))
		return (ft_show_error());
	bstack = ft_newstack();
	if (!alg_quick(astack, bstack))
		return (0);
	ft_freestack(astack);
	ft_freestack(bstack);
	return (1);
}
