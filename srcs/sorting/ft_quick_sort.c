/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 20:31:30 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/25 20:31:34 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

t_stack     *ft_quick_sort(t_stack *c)
{
  t_node  *i;
  t_node  *j;
  int     tmp;

  i = c->first;
  while (i->next)
  {
    j = (i->next);
    while (j)
    {
      if (j->value < i->value)
      {
        tmp = i->value;
        i->value = j->value;
        j->value = tmp;
      }
      j = j->next;
    }
    i = i->next;
  }
  ft_show_stack(c->first);
  return (c);
}
