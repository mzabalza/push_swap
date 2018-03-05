# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/09 21:09:19 by mzabalza          #+#    #+#              #
#    Updated: 2018/02/09 21:09:21 by mzabalza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CH_NAME = checker

PS_NAME = push_swap

FLAGS = -Wall -Werror -Wextra

CH_SRC = srcs/checker.c\
		srcs/ft_checkinp.c\
		srcs/ft_create_astack.c\
		srcs/ft_show_stack.c\
		srcs/ft_select_order.c\
		srcs/get_next_line.c\
		srcs/ft_stack_ops.c\
		srcs/ft_stack_result.c\
		srcs/ft_nwords.c\
		srcs/algos/is_ordered.c\
		srcs/algos/special_case.c\
		srcs/find_mid.c\
		srcs/algos/alg_pushpop.c

PS_SRC = srcs/ft_push_swap.c\
		srcs/ft_checkinp.c\
		srcs/ft_create_astack.c\
		srcs/ft_show_stack.c\
		srcs/ft_stack_ops.c\
		srcs/ft_stack_result.c\
		srcs/algos/alg_pushpop.c\
		srcs/algos/alg_pushpop2.c\
		srcs/algos/special_case.c\
		srcs/algos/is_ordered.c\
		srcs/sorting/ft_quick_sort.c\
		srcs/sorting/ft_bubble_sort.c\
		srcs/ft_select_order.c\
		srcs/find_mid.c\
		srcs/ft_nwords.c\
		srcs/ft_create_cstack.c

OBJ		= $(patsubst srcs/%.c,./%.o,$(SRC))

all: $(CH_NAME) $(PS_NAME)

$(CH_NAME):
		 	@gcc -Wall -Werror -Wextra $(CH_SRC) -L./libft -lft -Iincludes -o $(CH_NAME)
		 	@printf '\033[32m[ ✔ ] %s\n\033[0m' "Checker is done !"

$(PS_NAME):
		 	@gcc -Wall -Werror -Wextra $(PS_SRC) -L./libft -lft -Iincludes -o $(PS_NAME)
		 	@printf '\033[32m[ ✔ ] %s\n\033[0m' "Push_swap is done !"


clean:
		 	@/bin/rm -rf *.o
		 	@printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean"

fclean: clean
		 	@/bin/rm -rf $(CH_NAME)
		 	@/bin/rm -rf $(PS_NAME)
		 	@printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean"

re: fclean
	make

.PHONY: clean fclean re all
