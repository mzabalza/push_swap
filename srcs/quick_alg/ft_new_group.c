/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_group.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:04:56 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/19 22:31:26 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

/*
 **Delete node of the group
*/

t_group		*ft_del_group(t_group *group)
{
	t_group *tmp;

	if (!(group->prev))
	{
		free(group);
		group = NULL;
		return (group);
	}
	tmp = group;
	group = tmp->prev;
	group->next = tmp->next;
	free(tmp);
	return (group);
}

/*
 **Adding nodes to the group
*/

t_group		*ft_add_group(int nbval, int mid, t_group *group)
{
	t_group *newgroup;

	if (!(newgroup = (t_group *)malloc(sizeof(t_group))))
		exit(1);
	newgroup->nbval = nbval;
	newgroup->mid = mid;
	newgroup->next = NULL;
	newgroup->prev = group;
	return (newgroup);
}

/*
**First creation of the group
*/

t_group		*ft_new_group(int nbval, int mid)
{
	t_group *newgroup;

	if (!(newgroup = (t_group *)malloc(sizeof(t_group))))
		exit(1);
	newgroup->nbval = nbval;
	newgroup->mid = mid;
	newgroup->next = NULL;
	newgroup->prev = NULL;
	return (newgroup);
}
