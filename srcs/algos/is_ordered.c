/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ordered.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 00:27:37 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/07 03:41:48 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

static void	ft_move_tomin(t_stack *a, int dst)
{
	int i;
	int newdst;

	i = a->nbval;
	if (dst > i / 2)
	{
		newdst = (i - dst);
		while (newdst--)
		{
			ft_rra(a);
			ft_putstr("rra\n");
		}
	}
	else
	{
		while (dst--)
		{
			ft_ra(a);
			ft_putstr("ra\n");
		}
	}
}

int			is_rordered(t_node *list, t_stack *a)
{
	int		j;
	int		i;
	t_node	*tmp;

	tmp = list;
	j = search_min(list);
	i = 0;
	while (i + 1 < j)
	{
		if (list->value > (list->next)->value)
			return (0);
		list = list->next;
		i++;
	}
	list = list->next;
	while (list->next)
	{
		if (list->value > (list->next)->value)
			return (0);
		list = list->next;
	}
	if (!(list->value < tmp->value))
		return (0);
	ft_move_tomin(a, search_min(a->first));
	return (1);
}

int			is_ordered(t_node *list)
{
	while (list->next)
	{
		if (list->value > (list->next)->value)
			return (0);
		list = list->next;
	}
	return (1);
}

int			is_xordered(t_node *list)
{
	while (list->next)
	{
		if (list->value < (list->next)->value)
			return (0);
		list = list->next;
	}
	return (1);
}
