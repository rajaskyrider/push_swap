# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpandipe <rpandipe@student.42luxembou      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 16:07:00 by rpandipe          #+#    #+#              #
#    Updated: 2024/04/04 16:48:48 by rpandipe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
BONUS_NAME	= checker
LIBFT		= libft.a
CC		= cc
CFLAG		= -Wall -Werror -Wextra
RM		= rm -rf
SRCS		= push_swap.c handle_input.c bubble_sort.c deal_three.c \
		  deal_five.c swap.c push.c rotate.c reverse_rotate.c \
		  utils.c utils_print.c utils_sort.c
SRCSB		=
OBJS		= $(SRCS:.c=.o)
OBJSB		= $(SRCSB:.c=.o)
OBJBB 		= ${filter-out src/push_swap.o ,${OBJS}}


all: $(NAME)

$(NAME) : $(OBJS)
	@make -C libft
	@cp libft/libft.a
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(NAME) $(OBJSB)
	$(CC) $(CFLAGS) $(OBJBB) $(OBJSB) $(LIBFT) -o $(BONUS_NAME)

clean:
	cd libft && $(MAKE) clean
	$(RM) $(OBJS) $(OBJSB)

fclean:	clean 
	cd libft && $(MAKE) fclean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
