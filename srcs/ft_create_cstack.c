/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_cstack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 20:46:22 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/26 14:33:16 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

t_stack		*ft_create_cstack(t_node *a)
{
	t_stack	*cstack;

	cstack = ft_newstack();
	while (a)
	{
		ft_addnode(a->value, &(cstack->first), &(cstack->last));
		a = a->next;
	}
	return (cstack);
}
