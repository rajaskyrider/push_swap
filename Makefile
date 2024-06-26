# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 16:07:00 by rpandipe          #+#    #+#              #
#    Updated: 2024/04/15 15:17:25 by rpandipe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
BONUS_NAME	= checker
LIBFT		= libft.a
CC		= cc
CFLAG		= -Wall -Werror -Wextra -g
RM		= rm -rf
SRCS		= push_swap.c handle_input.c bubble_sort.c deal_three.c \
		  deal_five.c swap.c push.c rotate.c reverse_rotate.c \
		  utils.c utils_print.c utils_sort.c quick_sort_a.c \
		  quick_sort_b.c quick_sort_utils.c post_opt.c utils_opt.c \
		  rank.c insertion_sort.c utils_cost.c \
		  utils_insert.c opt_rotate.c opt_rotateb.c post_purge.c \
		  utils_opt_misc.c
SRCSB		= checker.c
OBJS		= $(SRCS:.c=.o)
OBJSB		= $(SRCSB:.c=.o)
OBJBB 		= ${filter-out push_swap.o ,${OBJS}}


all: $(NAME)

$(NAME) : $(OBJS)
	@make -C libft
	@cp libft/$(LIBFT) .
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(NAME) $(OBJSB)
	$(CC) $(CFLAGS) $(OBJBB) $(OBJSB) $(LIBFT) -o $(BONUS_NAME)

clean:
	cd libft && $(MAKE) clean
	$(RM) $(OBJS) $(OBJSB)

fclean:	clean 
	cd libft && $(MAKE) fclean
	$(RM) $(NAME) $(BONUS_NAME) $(LIBFT)

re: fclean all

.PHONY: all bonus clean fclean re
