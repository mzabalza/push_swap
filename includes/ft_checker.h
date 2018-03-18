/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 00:18:06 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/07 03:49:30 by mzabalza         ###   ########.fr       */
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
	struct s_node	*prev;
}					t_node;

typedef struct		s_stack
{
	int				nbval;
	int				max_margin;
	t_node			*first;
	t_node			*last;
}					t_stack;

typedef struct 		s_group 		
{
	int 			nbval;
	int 			mid;
	struct s_group	*next;
	struct s_group	*prev;
}					t_group;

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
void				ft_freestack(t_stack *stack);
void				ft_addnode(int value, t_node **top, t_node **bottom);
void				ft_delete_node(t_stack *stack, int i);
void				ft_pop(t_stack *stack);
void				ft_push(int value, t_stack *stack);

void				ft_sa(t_stack *stack);
void				ft_rra(t_stack *stack);
void				ft_ra(t_stack *stack);
void				ft_pa(t_stack *popstack, t_stack *pushstack);
/*
** Execute order and print it
*/
void				ft_exec_p(t_stack *a, t_stack *b, char c);
void				ft_exec_s(t_stack *a, t_stack *b, char c);
void				ft_exec_r(t_stack *a, t_stack *b, char c);
void				ft_exec_rr(t_stack *a, char c);
void				ft_exec_rrr(t_stack *a, t_stack *b);
/*
** Showing functions
*/
void				ft_show_stack(t_node *top);
int					ft_show_error();
void				ft_show_board(t_stack astack, t_stack bstack);
int					ft_showstr(char *str);
/*
** Hacer un vim de searchs
*/
int					search_max(t_node *list);
int					search_min(t_node *list);
int					find_mid(t_node *list, int nbval);
int					find_closer(t_node *alist, t_stack *cstack, int *margin);
/*
** Sorting Algorithms
*/
char				*alg_pushpop(t_stack *astack, t_stack *bstack);
int					ft_order(t_stack *a);
int					ft_xorder(t_stack *a);
void				exec_orders(int *orders, t_stack *a, t_stack *b, char c);
void				ft_retrack(int *orders, t_stack *a);
int					special_case(t_stack *a, t_stack *b);
int					alg_pushpop2(t_stack *astack, t_stack *bstack);
t_stack				*ft_bubble_sort(t_stack *c);
t_stack				*ft_quick_sort(t_stack *c);
t_stack				*ft_create_cstack(t_node *a);
/*
** Alg_quick
*/
int					alg_quick(t_stack *a, t_stack *b);
int					ft_mv_half_b(t_stack *a, t_stack *b, t_group *group);
int					ft_mv_half_a(t_stack *a, t_stack *b);
t_group				*ft_new_group(int nbval, int mid);
t_group				*ft_add_group(int nbval, int mid, t_group *group);
t_group				*ft_del_group(t_group *group);
void				ft_solve_3bstack(t_stack *a, t_stack *b);
void				ft_mv_group_b(t_stack *a, t_stack *b, t_group *group);



#endif
