/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_orders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 05:41:13 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/07 05:45:22 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void		ft_rra(t_stack *stack)
{
	t_node *tmp;

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

	tmp = (stack->first)->next;
	(stack->first)->next = NULL;
	(stack->last)->next = (stack->first);
	(stack->last) = (stack->first);
	(stack->first) = tmp;
}

void		ft_sa(t_stack *stack)
{
	t_node *tmp;

	tmp = (stack->first)->next;
	(stack->first)->next = tmp->next;
	tmp->next = (stack->first);
	stack->first = tmp;
}

void		ft_pa(t_stack *popstack, t_stack *pushstack)
{
	ft_push((popstack->first)->value, pushstack);
	ft_pop(popstack);
}
