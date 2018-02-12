/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 06:40:41 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/10 06:40:43 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

//Deletes the last inserted element in the stack
void 		ft_pop(t_stack *stack)
{
	t_node *tmp;

	if (stack->first == NULL)
		return ;
	tmp = stack->first;
	stack->first = stack->first->next;
	stack->nbval--;
	free(tmp);
}

//Interns an element in the stack
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