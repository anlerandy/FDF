# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerandy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/12 12:43:59 by alerandy          #+#    #+#              #
#    Updated: 2017/12/12 16:36:56 by alerandy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC_PATH = srcs/
OBJ_PATH = objects/
SRC_NAME = wireframe.c
OBJ_NAME = $(SRC_NAME:.c=.o)
CC = clang $(FLAG)
FLAG = -Wall -Werror -Wextra
FRAME = -framework OpenGL -framework AppKit
LIB = -Lminilibx_macos/ -lmlx -Llibft/ -lft
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all : $(NAME)

$(NAME) : libft minilibx $(OBJ)
	@$(CC) $(LIB) $(FRAME) $(OBJ) -o $(NAME)

libft :
	@$(MAKE) -C libft/

minilibx :
	@$(MAKE) -C minilibx_macos/

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) -o $@ -c $<

clean :
	@rm -f $(OBJ_PATH)
	@$(MAKE) -C libft/ clean
	@$(MAKE) -C minilibx_macos/ clean

fclean :
	@rm -f $(NAME)
	@rm -rf $(OBJ_PATH)
	@$(MAKE) -C libft/ fclean
	@$(MAKE) -C minilibx_macos/ clean
	@rm -f minilibx_macos/libmlx.a

re : fclean $(NAME)

norm :
	@norminette srcs/ includes/

.PHONY : fclean re norm minilibx libft all
