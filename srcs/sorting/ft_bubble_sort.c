/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 20:31:30 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/07 03:32:50 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

t_stack		*ft_bubble_sort(t_stack *c)
{
	t_node	*i;
	t_node	*j;
	int		tmp;

	i = c->first;
	while (i->next)
	{
		j = (i->next);
		while (j)
		{
			if (j->value < i->value)
			{
				tmp = i->value;
				i->value = j->value;
				j->value = tmp;
			}
			j = j->next;
		}
		i = i->next;
	}
	return (c);
}
