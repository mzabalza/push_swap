/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkinp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 23:05:14 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/09 01:30:49 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

int		ft_checknumber(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int		ft_checkinp(int ac, char **input)
{
	int i;
	intmax_t nb;

	i = 1;
	while (i < ac)
	{
		if (!ft_checknumber(input[i]))
			return (0);
		nb = ft_atointmax(input[i]);
		if (nb > 2147483647 || nb < -2147483648)
			return (0);
		i++;
	}
	return (1);
}
