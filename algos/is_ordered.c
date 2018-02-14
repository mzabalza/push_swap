/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ordered.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 00:27:37 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/14 00:27:39 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

int		is_ordered(t_node *list)
{
	while (list->next)
	{
		if (list->value > (list->next)->value)
			return (0);
		list = list->next;
	}
	return (1);
}

int		is_xordered(t_node *list)
{
	while (list->next)
	{
		if (list->value < (list->next)->value)
			return (0);
		list = list->next;
	}
	return (1);
}