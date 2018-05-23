/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 22:58:55 by mzabalza          #+#    #+#             */
/*   Updated: 2018/05/21 15:31:55 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

static void		ft_printpad(int pad)
{
	while (pad-- > 0)
		ft_putchar(' ');
}

static void		show_ab(t_stack astack, int pad)
{
	if (astack.first)
	{
		pad = ft_nbdigits((astack.first)->value);
		if ((astack.first)->value < 0)
			pad++;
	}
	if (astack.first)
		ft_putnbr((astack.first)->value);
	ft_printpad(12 - pad);
}

static void		colored_board(t_stack astack, t_stack bstack)
{
	while (astack.first || bstack.first)
	{
		write(1, "\x1b[44;37m", 9);
		show_ab(astack, 0);
		ft_putstr("\x1b[0m||  \x1b[41;37m");
		show_ab(bstack, 12);
		if (astack.first)
			astack.first = (astack.first)->next;
		if (bstack.first)
			bstack.first = (bstack.first)->next;
		ft_putchar('\n');
	}
}

void			ft_show_board(t_stack astack, t_stack bstack)
{
	usleep(100000);
	write(1, "\x1b[H\x1b[2J", 7);
	ft_putendl("\nSTACK A     ||  STACK B     \n-------     ||  -------     ");
	colored_board(astack, bstack);
	ft_putchar('\n');
	write(1, "\x1b[0m", 4);
}
