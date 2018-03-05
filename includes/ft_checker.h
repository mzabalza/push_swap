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
	struct 			s_node	*next;
	struct 			s_node	*prev;
}					t_node;

typedef struct		s_stack
{
	int				nbval;
	t_node			*first;
	t_node			*last;
}					t_stack;

int					main(int ac, char **av);

int					ft_select_order(char *order, t_stack *a, t_stack *b);
int					ft_stack_result(t_stack astack, t_stack bstack);
size_t				ft_nwords(char const *s, char c);
/*
** Checking functions
*/
int					ft_checkinp(int ac, char **input, int i);
int					ft_check_dupl(t_node *list);
int					is_ordered(t_node *list);
int					is_xordered(t_node *list);
int					is_rordered(t_node *list, t_stack *a);
/*
** Stack operations
*/
t_stack				*ft_create_astack(int ac, char **input, int i);
char				**ft_create_strstack(char *str);
t_stack				*ft_newstack();
void				ft_addnode(int value, t_node **top, t_node **bottom);
void				ft_delete_node(t_stack *stack, int i);
void 				ft_pop(t_stack *stack);
void				ft_push(int value, t_stack *stack);

void				ft_sa(t_stack *stack);
void				ft_rra(t_stack *stack);
void				ft_ra(t_stack *stack);
void				ft_pa(t_stack *popstack, t_stack *pushstack);
/*
** Showing functions
*/
void				ft_show_stack(t_node *top);
int					ft_showError();
void				ft_show_board(t_stack astack, t_stack bstack);
int					ft_showstr(char *str);
/*
** Hacer un vim de searchs
*/
int					search_max(t_node *list);
int					search_min(t_node *list);
int					find_mid(t_node *list, int nbval);
int					find_closer(t_node *alist, t_stack *cstack, int *margin, int nbval);
int					ft_order(t_stack *a);
void				exec_orders(int *orders, t_stack *a, t_stack *b, char c);
/*
** Sorting Algorithms
*/
char				*alg_pushpop(t_stack *astack, t_stack *bstack);
void				special_case(t_stack *a, t_stack *b);
char				*alg_pushpop2(t_stack *astack, t_stack *bstack);
t_stack     		*ft_bubble_sort(t_stack *c);
t_stack     		*ft_quick_sort(t_stack *c);
/*
** Alg_pushpop2
*/
t_stack				*ft_create_cstack(t_node *a);

#endif
