# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerandy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/12 12:43:59 by alerandy          #+#    #+#              #
#    Updated: 2018/01/10 11:19:30 by alerandy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC_PATH = srcs/
OBJ_PATH = objects/
SRC_NAME = wireframe.c coord_crafter.c ft_tabdel.c ft_memclr.c \
		   ft_input.c ft_putpixel.c main.c
OBJ_NAME = $(SRC_NAME:.c=.o)
CC = clang $(FLAG)
FLAG = -Wall -Werror -Wextra -g
FRAME = -framework OpenGL -framework AppKit
LIB = -Lminilibx_macos/ -lmlx -Llibft/ -lft
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all : $(NAME)

$(NAME) : libft success $(OBJ)
	@$(CC) $(LIB) $(FRAME) $(OBJ) -o $(NAME)

libft :
	@$(MAKE) -C libft/

success : minilibx
#	@printf "\033[9A\r\033[K""\033[32mLibrairie mlx compilé avec succès.\033[0m\n"

minilibx :
	@$(MAKE) -C minilibx_macos/

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) -Iminilibx_macos -Iincludes -Ilibft/includes -o $@ -c $<

clean :
	@rm -f $(OBJ_PATH)
	@$(MAKE) -C minilibx_macos/ clean
	@printf "\033[2A\r\033[K""\033[1;30mLib mlx détruite.\033[0m\n"
	@$(MAKE) -C libft/ clean

fclean :
	@rm -f $(NAME)
	@rm -rf $(OBJ_PATH)
	@$(MAKE) -C minilibx_macos/ clean
	@printf "\033[2A\r\033[K""\033[1;30mLib mlx détruite.\033[0m\n"
	@$(MAKE) -C libft/ fclean
	@rm -f minilibx_macos/libmlx.a

re : fclean $(NAME)
	@printf "\033[9A\r\033[K""\033[32mLibrairie mlx compilé avec succès.\033[0m\n"

norm :
	@norminette srcs/ includes/

.PHONY : fclean re norm success minilibx libft all
