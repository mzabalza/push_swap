/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 22:57:59 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/26 11:53:48 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

static int	read_instructions(t_stack *astack, t_stack *bstack, int show)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (!ft_select_order(line, astack, bstack))
			return (ft_show_error());
		if (show == 2)
			ft_show_board(*astack, *bstack);
		free(line);
	}
	ft_stack_result(*astack, *bstack);
	ft_freestack(astack);
	ft_freestack(bstack);
	return (1);
}

int			main(int ac, char **av)
{
	t_stack *astack;
	t_stack *bstack;
	int		ac_one;

	ac_one = 1;
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		ac = ft_nwords(av[1], ' ');
		av = ft_create_strstack(av[1]);
		ac_one = 0;
	}
	if (ac_one && !(ft_strcmp(av[1], "-v")))
		ac_one = 2;
	if (!ft_checkinp(ac, av, ac_one))
		return (ft_show_error());
	astack = ft_create_astack(ac, av, ac_one);
	bstack = ft_newstack();
	if (!ft_check_dupl(astack->first))
		return (ft_show_error());
	if (!(read_instructions(astack, bstack, ac_one)))
		return (0);
	return (1);
}
