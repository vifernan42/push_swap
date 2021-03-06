# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 13:23:53 by vifernan          #+#    #+#              #
#    Updated: 2021/11/22 18:01:31 by vifernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CFLAGS	= -Wall -Werror -Wextra

SRCS	= 	push_swap.c \
			stack_utils.c \
			moves.c \
			algorithm2.c \
			a2b.c \
			b2a.c \
			fill.c \
			push.c \
			moves_notus.c \
			moves_dotus.c \
			moves_sotus.c \

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

.PHONY: all clean fclean re
