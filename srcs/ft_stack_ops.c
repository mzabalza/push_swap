/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 06:40:41 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/07 05:17:52 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void		ft_delete_node(t_stack *stack, int i)
{
	t_node *list;

	list = stack->first;
	while (i--)
		list = list->next;
	if (!list->prev)
	{
		(list->next)->prev = list->prev;
		stack->first = list->next;
	}
	else if (!list->next)
		(list->prev)->next = list->next;
	else
	{
		(list->prev)->next = list->next;
		(list->next)->prev = list->prev;
	}
	free(list);
}

/*
**Deletes the last inserted element in the stack
*/

void		ft_pop(t_stack *stack)
{
	t_node *tmp;

	if (stack->first == NULL)
		return ;
	tmp = stack->first;
	stack->first = stack->first->next;
	stack->nbval--;
	free(tmp);
}

/*
**Interns an element in the stack
*/

void		ft_push(int value, t_stack *stack)
{
	t_node *newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	newnode->value = value;
	if (stack->first)
		newnode->next = (stack->first);
	else
	{
		newnode->next = NULL;
		(stack->last) = newnode;
	}
	(stack->first) = newnode;
	stack->nbval++;
}
