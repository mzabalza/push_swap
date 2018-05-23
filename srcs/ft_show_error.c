/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:18:10 by mzabalza          #+#    #+#             */
/*   Updated: 2018/05/21 15:31:42 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void			ft_show_stack(t_node *top)
{
	while (top)
	{
		ft_putnbr(top->value);
		ft_putchar(' ');
		top = top->next;
	}
	ft_putchar('\n');
}

int				ft_showstr(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	if (*str == 'K')
		return (0);
	return (1);
}

int				ft_show_error(void)
{
	write(2, "Error\n", 6);
	exit(-1);
	return (0);
}
