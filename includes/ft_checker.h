/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 00:18:06 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/09 00:24:30 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_H
# define FT_CHECKER_H
# include "../libft/libft.h"
# include "../includes/get_next_line.h"

typedef struct		s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct		s_stack
{
	int				nbval;
	t_node			*first;
	t_node			*last;
}					t_stack;

	
int					main(int ac, char **av);
int					ft_checkinp(int ac, char **input);
t_stack				*ft_create_astack(int ac, char **input);
t_stack				*ft_newstack();
void				ft_addnode(int value, t_node **top, t_node **bottom);
void 				ft_pop(t_stack *stack);
void				ft_show_stack(t_node *top);
int					ft_showError();
void				ft_show_board(t_stack astack, t_stack bstack);
int					ft_select_order(char *order, t_stack *a, t_stack *b);
void				ft_sa(t_stack *stack);
void				ft_rra(t_stack *stack);
void				ft_ra(t_stack *stack);
void				ft_pa(t_stack *popstack, t_stack *pushstack);
void				ft_push(int value, t_stack *stack);
int					ft_stack_result(t_stack astack, t_stack bstack);
int					ft_showstr(char *str);
int					ft_check_dupl(t_node *list);
char				*alg_pushpop(t_stack *astack, t_stack *bstack);

#endif
