/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_astack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 20:32:34 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/09 20:32:36 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

char		**ft_create_strstack(char *str)
{
	return (ft_strsplit(str, ' '));
}

void		ft_addnode(int value, t_node **top, t_node **bottom)
{
	t_node *newlist;

	newlist = (t_node *)malloc(sizeof(t_node));
	newlist->value = value;
	if ((*top) == NULL)
	{
		*top = newlist;
		*bottom = newlist;
		//
		newlist->prev = NULL;
	}
	else
	{
		(*bottom)->next = newlist;
		newlist->prev = (*bottom);
		(*bottom) = newlist;
	}
	newlist->next = NULL;
}

t_stack		*ft_newstack()
{
	t_stack	*stack;
	t_node	*top;
	t_node	*bottom;

	stack = (t_stack *)malloc(sizeof(t_stack));
	top = (t_node *)malloc(sizeof(t_node));
	bottom = (t_node *)malloc(sizeof(t_node));
	top = NULL;
	bottom = NULL;
	stack->first = top;
	stack->last = bottom;
	return (stack);
}

t_stack		*ft_create_astack(int ac, char **input, int i)
{
	t_stack	*astack;
	int 	j;

	j = i;
	astack = ft_newstack();
	while (i < ac)
	{
		ft_addnode(ft_atoi(input[i]), &(astack->first), &(astack->last));
		i++;
	}
	astack->nbval = i - j;
	return (astack);
}
