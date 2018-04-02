# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/09 21:09:19 by mzabalza          #+#    #+#              #
#    Updated: 2018/03/26 13:59:48 by mzabalza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#RM = /usr/bin/env rm
CH_NAME = checker
PS_NAME = push_swap

LIBFT = libft/libft.a
 
CC = clang
CFLAGS = -Wall -Werror -Wextra -Iincludes
#-L./libft 

CH_SRC = srcs/checker.c\
		srcs/ft_checkinp.c\
		srcs/ft_create_astack.c\
		srcs/ft_show_stack.c\
		srcs/ft_select_order.c\
		srcs/ft_orders.c\
		srcs/get_next_line.c\
		srcs/ft_stack_ops.c\
		srcs/ft_stack_result.c\
		srcs/ft_nwords.c\
		srcs/algos/is_ordered.c\
		srcs/algos/special_case.c\
		srcs/algos/special_case2.c\
		srcs/find_mid.c\
		srcs/algos/alg_pushpop.c\
		srcs/ft_ex_and_print.c

CH_OBJ		= $(CH_SRC:.c=.o)

PS_SRC = srcs/ft_push_swap.c\
		srcs/ft_checkinp.c\
		srcs/ft_create_astack.c\
		srcs/ft_show_stack.c\
		srcs/ft_stack_ops.c\
		srcs/ft_stack_result.c\
		srcs/algos/alg_pushpop.c\
		srcs/algos/alg_pushpop2.c\
		srcs/algos/special_case.c\
		srcs/algos/special_case2.c\
		srcs/algos/is_ordered.c\
		srcs/sorting/ft_bubble_sort.c\
		srcs/ft_select_order.c\
		srcs/ft_orders.c\
		srcs/find_mid.c\
		srcs/ft_nwords.c\
		srcs/ft_create_cstack.c\
		srcs/ft_ex_and_print.c\
		srcs/algos/alg_quick.c\
		srcs/quick_alg/ft_new_group.c\
		srcs/quick_alg/ft_mv_half_b.c\
		srcs/quick_alg/ft_solve_3bstack.c\
		srcs/quick_alg/ft_solve_3astack.c

PS_OBJ		= $(PS_SRC:.c=.o)

all: $(LIBFT) $(CH_NAME) $(PS_NAME) 

$(LIBFT):
	make -C libft

$(CH_NAME): $(CH_OBJ)
	$(CC) $(CFLAGS) $(CH_OBJ) $(LIBFT) -o $(CH_NAME)
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "Checker is done !"

$(PS_NAME): $(PS_OBJ)
	$(CC) $(CFLAGS) $(PS_OBJ) $(LIBFT) -o $(PS_NAME)
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "Push_swap is done !"


clean:
	rm -f $(CH_OBJ)
	rm -f $(PS_OBJ)
	make -C libft clean
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean"

fclean: clean
	make -C libft fclean
	rm $(PS_NAME)
	rm $(CH_NAME)
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean"

re: fclean all

.PHONY: clean fclean re all
