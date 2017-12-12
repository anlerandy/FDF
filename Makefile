# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerandy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/12 12:43:59 by alerandy          #+#    #+#              #
#    Updated: 2017/12/12 13:10:25 by alerandy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC_PATH = srcs/
OBJ_PATH = objects/
SRC_NAME =
OBJ_NAME = $(SRC_NAME:.o=.c)
CC = clang $(FLAG)
FLAG = -Wall -Werror -Wextra
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all : $(NAME)

$(NAME) : libt minilibx $(OBJ)

libt :
	@$(MAKE) -C libft/

minilibx :
	@$(MAKE) -C minilibx_macos/

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(LIB) -o $@ -c $<

clean :
	@rm -f $(OBJ_PATH)
	@$(MAKE) -C libft/ clean
	@$(MAKE) -C minilibx_macos/ clean

fclean :
	@rm -f $(NAME)
	@rm -f $(OBJ_PATH)
	@$(MAKE) -C libft/ fclean
	@$(MAKE) -C minilibx_macos/ clean
	@rm -f minilibx_macos/libmlx.a

re : fclean $(NAME)

norm :
	@norminette srcs/ includesr
