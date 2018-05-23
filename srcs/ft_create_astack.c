/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_astack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 20:32:34 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/26 14:33:07 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void		ft_freestack(t_stack *stack)
{
	t_node *tmp;

	while (stack->first)
	{
		tmp = (stack->first)->next;
		free(stack->first);
		stack->first = tmp;
	}
	stack->first = NULL;
	stack->last = NULL;
	free(stack);
}

char		**ft_create_strstack(char *str)
{
	char **av;

	if (!(av = ft_strsplit(str, ' ')))
		exit(1);
	return (av);
}

void		ft_addnode(int value, t_node **top, t_node **bottom)
{
	t_node *newlist;

	if (!(newlist = (t_node *)malloc(sizeof(t_node))))
		exit(1);
	newlist->value = value;
	if ((*top) == NULL)
	{
		*top = newlist;
		*bottom = newlist;
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

t_stack		*ft_newstack(void)
{
	t_stack	*stack;
	t_node	*top;
	t_node	*bottom;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		exit(1);
	top = NULL;
	bottom = NULL;
	stack->nbval = 0;
	stack->first = top;
	stack->last = bottom;
	return (stack);
}

t_stack		*ft_create_astack(int ac, char **input, int i)
{
	t_stack	*astack;
	int		j;

	j = i;
	astack = ft_newstack();
	while (i < ac)
	{
		ft_addnode(ft_atoi(input[i]), &(astack->first), &(astack->last));
		i++;
	}
	astack->nbval = i - j;
	astack->max_margin = astack->nbval / 3;
	return (astack);
}
