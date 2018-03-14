/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 04:33:29 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/07 05:45:56 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

int		ft_check_dupl(t_node *list)
{
	t_node	*tmp;

	while (list->next)
	{
		tmp = list->next;
		while (tmp)
		{
			if (list->value == tmp->value)
				return (0);
			tmp = tmp->next;
		}
		list = list->next;
	}
	return (1);
}

int		ft_check_numbers(t_stack stack)
{
	while ((stack.first)->next)
	{
		if ((stack.first)->value >= (((stack.first)->next)->value))
			return (0);
		stack.first = (stack.first)->next;
	}
	return (1);
}

int		ft_stack_result(t_stack astack, t_stack bstack)
{
	if (!ft_check_numbers(astack))
		return (ft_showstr("KO"));
	if (bstack.nbval != 0)
		return (ft_showstr("KO"));
	return (ft_showstr("OK"));
}
