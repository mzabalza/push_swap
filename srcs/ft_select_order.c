/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_order.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 05:32:20 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/10 05:33:20 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void	ft_rra(t_stack *stack)
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

void	ft_ra(t_stack *stack)
{
	t_node *tmp;

	tmp = (stack->first)->next;
	(stack->first)->next = NULL;
	(stack->last)->next = (stack->first);
	(stack->last) = (stack->first);
	(stack->first) = tmp;
}

void	ft_sa(t_stack *stack)
{
	t_node *tmp;

	tmp = (stack->first)->next;
	(stack->first)->next = tmp->next;
	tmp->next = (stack->first);
	stack->first = tmp;
}

void	ft_pa(t_stack *popstack, t_stack *pushstack)
{
	ft_push((popstack->first)->value, pushstack);
	ft_pop(popstack);
}

int	ft_select_order(char *order, t_stack *astack, t_stack *bstack)
{
	t_stack *tmp;

	tmp = bstack;
	if (!ft_strcmp(order, "sa") && astack->nbval > 1)
		ft_sa(astack);
	else if (!ft_strcmp(order, "sb") && bstack->nbval > 1)
		ft_sa(bstack);
	else if (!ft_strcmp(order, "ss") && astack->nbval > 1 && bstack->nbval > 1)
	{
		ft_sa(astack);
		ft_sa(bstack);
	}
	else if (!ft_strcmp(order, "pb") && astack->nbval)
		ft_pa(astack, bstack);
	else if (!ft_strcmp(order, "pa") && bstack->nbval)
		ft_pa(bstack, astack);
	else if (!ft_strcmp(order, "ra") && astack->nbval > 1)
		ft_ra(astack);
	else if (!ft_strcmp(order, "rb") && bstack->nbval > 1)
		ft_ra(bstack);
	else if (!ft_strcmp(order, "rr") && astack->nbval > 1 && bstack->nbval > 1)
	{
		ft_ra(astack);
		ft_ra(bstack);
	}
	else if (!ft_strcmp(order, "rra") && astack->nbval > 1)
		ft_rra(astack);
	else if (!ft_strcmp(order, "rrb") && bstack->nbval > 1)
		ft_rra(bstack);
	else if (!ft_strcmp(order, "rrr") && astack->nbval > 1 && bstack->nbval > 1)
	{
		ft_rra(astack);
		ft_rra(bstack);
	}
	else
		return (0);
	return (1);

}
