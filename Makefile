# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vifernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 13:23:53 by vifernan          #+#    #+#              #
#    Updated: 2021/11/10 15:10:14 by vifernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CFLAGS	= -Wall -Wextra -Werror

SRCS	= 	push_swap.c \
			moves.c \

OBJS	= $(SRCS:.c=.o)
CC		= 	gcc
INCLUDES = -I./includes

all: $(NAME)

BCyan = \033[1;36m
GREEN = \033[0;32m
Yellow = \033[0;33m
Red = \033[0;31m
NO_COLOR = \033[0m

$(NAME): $(OBJS)
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) libft/libft.a $(OBJS) -o $(NAME)
	@echo "$(GREEN)[COMPILED]$(NO_COLOR)"

clean:
	rm -rf $(OBJS)
	@$(MAKE) fclean -C ./libft
	@echo "$(Yellow)[CLEAN]$(NO_COLOR)"

fclean: clean
	rm -rf $(NAME)
	@echo "$(Red)[FCLEAN]$(NO_COLOR)"
	
re: fclean all

.PHONY: all clean fclean re bonus test
