# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/26 13:35:37 by vquesnel          #+#    #+#              #
#*   Updated: 2016/05/26 19:54:33 by vquesnel         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME= wolf3d

SRCS= srcs/main.c srcs/get_map.c srcs/init_node.c srcs/init_env.c\
	  srcs/init_img.c srcs/ray_casting.c srcs/draw_one_line.c\
	  srcs/searchinlist.c srcs/key_hook.c srcs/key_functions.c srcs/create_xpm.c \
	  srcs/create_tab.c

OBJS= $(SRCS:.c=.o)
INCLUDES= -I libft/includes -I includes -I mlx/
LIBS= -L libft/ -lft -L mlx/ -lmlx -lm
FLAGS= -O3 -Ofast -O2 -g
FRAMEWORK= -framework AppKit -framework OpenGL

$(NAME):	$(OBJS)
	@make -C libft/
	@make -C mlx/
	@gcc -o $(NAME) $(OBJS) $(LIBS) $(FRAMEWORK)
	@echo "\n"
	@echo "	\033[37;1m  ,__________,   ,______________, \033[0m"
	@echo "	\033[37;1m  |          |   |               \     \033[0m"
	@echo "	\033[37;1m  |___,      |   |     ,____,     \   \033[0m"
	@echo "	\033[37;1m     /      /    |     |     \     \  \033[0m"
	@echo "	\033[37;1m    /      /     |     |      \     \ \033[0m"
	@echo "	\033[37;1m   /______/      |_____|      /     / \033[0m"
	@echo "	\033[37;1m  ,________________________./      /  \033[0m"
	@echo "	\033[37;1m  |                               /   \033[0m"
	@echo "	\033[37;1m  |_____________________________./     \033[0m"
	@echo "	\033[31;1m  +--------------------------------+\033[0m"
	@echo "	\033[31;1m  | ZDTEAM  @  42 SCHOOL   2 0 1 6 |\033[0m"
	@echo "	\033[31;1m  +--------------------------------+\033[0m"
	@echo "\n"

$(OBJS): %.o: %.c
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

all:	$(NAME)

clean:
	@make -C libft/ clean
	@make -C mlx/ clean
	@rm -f $(OBJS)
	@echo "\033[37mall $(NAME)_files.o are deleted\033[0m"

fclean:	clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "\033[31m$(NAME) is deleted\033[0m"

re:		fclean all

norme: fclean
	@norminette srcs/
	@norminette includes/
	@norminette libft/
	@make re


.PHONY: all clean fclean re
