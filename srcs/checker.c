/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 22:57:59 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/09 01:34:00 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

//limite de tamano del stack 
	//ft_check_inp();
	//ft_check_op();
	//ft_stack_op()
	//ft_newstack
		//isempty	boolean, returns if stack is empty
		//push(int)	Interns an element in the stack
		//pop()		Deletes the last inserted element in the stack
		//size		Returns the number of elements in the stack
		//top		Returns the top element of the stack


	
int				main(int ac, char **av)
{
	t_stack *astack;
	t_stack *bstack;
	char	*line;

	if (ac == 1)
		return (0);
	if (!ft_checkinp(ac, av))
		return (ft_showError());
	astack = ft_create_astack(ac, av);
	if (!ft_check_dupl(astack->first))
		return (ft_showError());
	bstack = ft_newstack();
	ft_show_board(*astack, *bstack);
	ft_putchar('\n');	
	while (get_next_line(0, &line))
	{
		if(!ft_select_order(line, astack, bstack))
			return (ft_showError());
	}
	ft_show_board(*astack, *bstack);
	ft_stack_result(*astack, *bstack);
	return (1);
}
