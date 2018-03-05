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

int		search_min(t_node *list)
{
	int i;
	int tmp;
	int dst;

	i = 0;
	dst = i;
	tmp = list->value;
	while (list)
	{
		if (list->value < tmp)
		{
			tmp = list->value;
			dst = i;
		}
		i++;
		list = list->next;
	}
	return (dst);
}

int		search_value(t_node *list, int val)
{
	int i;

	i = 0;
	while (list)
	{
		if (list->value == val)
			return (i);
		i++;
		list = list->next;
	}
	return (-1);
}

int		find_closer(t_node *alist, t_stack *cstack, int *margin, int nbval)
{
	int dst;
	int tmp;
	int	i;
	int j;
	t_node *clist;
	int tmp2;

	tmp2 = 0;

	clist = cstack->first;
	i = 0;
	j = 0;

	//dst = search_value(alist, clist->value);
	dst = clist->value;
	//ft_putchar('{');
	//ft_putnbr(dst);
	while (i < *margin && (clist = clist->next))
	{
		i++;
		tmp = search_value(alist, dst);
		tmp2 = search_value(alist, clist->value);
		//if (tmp > nbval / 2)
		//	tmp = nbval - tmp;
		//if (tmp2 > nbval / 2)
		//	tmp2 = nbval - tmp2;
		//ft_putnbr(tmp);
		if (tmp2 < tmp)
		{
			j = i;
			dst = clist->value;
		}
	}
	//ft_putchar('}');
	if (j)
		(*margin)--;
	if (!j || *margin == 0)
		(*margin) = 2;
	ft_delete_node(cstack, j);
	//ft_show_stack(cstack->first);
	i = nbval;
	//ft_putnbr(dst);
	return (search_value(alist, dst));
}

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
