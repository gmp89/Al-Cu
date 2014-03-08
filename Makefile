#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/07 21:33:17 by gpetrov           #+#    #+#              #
#    Updated: 2014/03/08 23:54:37 by gpetrov          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= puissance4
FILES	= main.c win_conditions.c tools.c check.c move.c charly.c
SRCS	= $(addprefix src/, $(FILES))
OBJS	= $(SRCS:src/%.c=.obj/%.o)
INC		= -I includes -I libft/includes
FLAGS	= -Wall -Wextra -Werror -O3
LIB		= -L libft -lft

all: $(NAME)
$(NAME): $(OBJS)
	@make -C libft
	@cc $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(LIB)
	@echo "\n > \033[36m$(NAME)\033[m project com\
	pilation [\033[32mDONE\033[m]\n"


.obj/%.o: src/%.c
	@mkdir -p .obj
	@cc -c $< -o $@ $(FLAGS) $(INC)
	@echo -n .
gdb:
	make -C libft
	cc -g $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(LIB)
	lldb $(NAME)
clean:
	@rm -rf .obj
fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "fclean : [\033[32mDONE\033[m]"
re: fclean all
.PHONY: all gdb clean fclean re
