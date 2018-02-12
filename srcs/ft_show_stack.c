/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 22:58:55 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/09 22:58:58 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

int				ft_showstr(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	if (*str == 'K')
		return (0);
	return (1);
}

int		ft_showError()
{
	ft_putstr("Error");
	ft_putchar('\n');
	return (0);
}

static void		ft_printpad(int pad)
{
	while (pad-- > 0)
		ft_putchar(' ');
}

void		ft_show_board(t_stack astack, t_stack bstack)
{
	int pad;

	ft_putendl("\nSTACK A     ||     STACK B");
	ft_putendl("-------     ||     -------");
	while(astack.first || bstack.first)
	{
		pad = 0;
		if (astack.first)
		{
			pad = ft_nbdigits((astack.first)->value);
			if ((astack.first)->value < 0)
				pad++;
		}
		if (astack.first)
			ft_putnbr((astack.first)->value);
		ft_printpad(12 - pad);
		ft_putstr("||     ");
		if (bstack.first)
			ft_putnbr((bstack.first)->value);
		if (astack.first)
			astack.first = (astack.first)->next;
		if (bstack.first)
			bstack.first = (bstack.first)->next;
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

//esto lo uso en algun lado???
void	ft_show_stack(t_node *top)
{
	while (top)
	{
		ft_putnbr(top->value);
		ft_putchar('\n');
		top = top->next;
	}
}