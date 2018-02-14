/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 21:46:16 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/13 21:46:18 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

static int		selection_sort(int *order, int nbval)
{
	int i;
	int j;
	int tmp;

	i = 0;
	tmp = 0;
	while (i < (nbval - 1))
	{
		j = i + 1;
		while (j < nbval)
		{
			if (order[i] > order[j])
			{
				tmp = order[i];
				order[i] = order[j];
				order[j] = tmp;
			}
			j++;
		}
		i++;
	}
	i = (nbval / 2);
	return (order[i]);
}

int				find_mid(t_node *list, int nbval)
{
	int *order;
	int i;
	int mid;

	order = (int *)malloc(sizeof(int) * (nbval));
	i = 0;
	while (list)
	{
		order[i] = list->value;
		list = list->next;
		i++;
	}
	order[i] = '\0';
	mid = selection_sort(order, nbval);
	return (mid);
}
