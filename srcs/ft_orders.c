/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_orders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 05:41:13 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/19 23:36:28 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void		ft_rra(t_stack *stack)
{
	t_node *tmp;

	if (stack->nbval <= 1)
		return ;
	tmp = stack->first;
	while (tmp->next != stack->last)
		tmp = tmp->next;
	tmp->next = NULL;
	(stack->last)->next = stack->first;
	stack->first = stack->last;
	stack->last = tmp;
}

void		ft_ra(t_stack *stack)
{
	t_node *tmp;

	if (stack->nbval <= 1)
		return ;
	tmp = (stack->first)->next;
	(stack->last)->next = (stack->first);
	(stack->first)->next = NULL;
	(stack->last)->prev = (stack->last);
	(stack->last) = (stack->first);
	(stack->first) = tmp;
	(stack->first)->prev = NULL;
}

void		ft_sa(t_stack *stack)
{
	int		tmp;

	if (stack->nbval <= 1)
		return ;
	tmp = (stack->first)->value;
	(stack->first)->value = ((stack->first)->next)->value;
	((stack->first)->next)->value = tmp;
}

void		ft_pa(t_stack *popstack, t_stack *pushstack)
{
	if (popstack->nbval == 0)
		return ;
	ft_push((popstack->first)->value, pushstack);
	ft_pop(popstack);
}
