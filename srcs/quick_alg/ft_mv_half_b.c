/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv_half_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 12:42:13 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/19 22:30:17 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

/*
**Finds the smallest value in a list
*/

static int	ft_smallest(t_node *list)
{
	int smallest;

	smallest = list->value;
	list = list->next;
	while (list)
	{
		if (list->value < smallest)
			smallest = list->value;
		list = list->next;
	}
	return (smallest);
}

/*
**Moves smallest value from b to a, when is located in b->first
*/

static void	ft_mv_min_a(t_stack *a, t_stack *b, int *min, int mid)
{
	if (((b->first)->value == *min) && ((b->first)->value) < mid)
	{
		ft_exec_p(b, a, 'a');
		ft_exec_r(a, b, 'a');
		*min = ft_smallest(b->first);
	}
}

/*
**Receives a, b stacks; finds middle value from b; moves half of a to b
**c is the destiny
**returns nº values moved
*/

int			ft_mv_half_a(t_stack *a, t_stack *b)
{
	int		i;
	int		mid;
	int		moves;
	int		min;

	moves = b->nbval / 2;
	mid = find_mid(b->first, b->nbval);
	if ((b->nbval) % 2)
		moves++;
	i = moves;
	min = ft_smallest(b->first);
	while (i)
	{
		ft_mv_min_a(a, b, &min, mid);
		if ((b->first)->value >= mid)
		{
			ft_exec_p(b, a, 'a');
			i--;
		}
		else
			ft_exec_r(b, a, 'b');
	}
	return (moves);
}

/*
**Receives a, b stacks; finds middle value from a; moves half of a to b
**c is the destiny
**returns nº values moved
*/

void		ft_mv_group_b(t_stack *a, t_stack *b, t_group *group)
{
	int i;
	int moves;

	moves = (group->nbval);
	i = moves;
	while (i)
	{
		ft_exec_p(a, b, 'b');
		i--;
	}
}

int			ft_mv_half_b(t_stack *a, t_stack *b, t_group *group)
{
	int i;
	int moves;
	int j;
	int min;

	min = ft_smallest(a->first);
	j = 0;
	moves = (group->nbval) / 2;
	i = moves;
	while (i)
	{
		if ((a->first)->value < group->mid)
		{
			i--;
			ft_exec_p(a, b, 'b');
		}
		else
		{
			j++;
			ft_exec_r(a, b, 'a');
		}
	}
	return (j);
}
