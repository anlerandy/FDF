# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerandy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 12:38:11 by alerandy          #+#    #+#              #
#    Updated: 2018/01/16 10:33:33 by alerandy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = srcs/
OBJ_PATH = objects/
SRC_NAME = ft_putchar.c ft_putstr.c ft_putcharerr.c ft_putstrerr.c ft_memset.c \
		   ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memchr.c ft_strlen.c \
		   ft_memcmp.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
		   ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
		   ft_strstr.c ft_strncmp.c ft_strcmp.c ft_atoi.c ft_isalnum.c \
		   ft_isdigit.c ft_isalpha.c ft_isprint.c ft_isascii.c ft_tolower.c \
		   ft_toupper.c ft_memmove.c ft_isspace.c ft_memalloc.c ft_strclr.c \
		   ft_strdel.c ft_strnew.c ft_memdel.c ft_striter.c ft_strsub.c \
		   ft_strnequ.c ft_strmapi.c ft_strmap.c ft_striteri.c ft_strequ.c \
		   ft_strjoin.c ft_strtrim.c ft_putnbr.c ft_putendl.c ft_putnbr_fd.c \
		   ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_strsplit.c \
		   ft_itoa.c ft_lstnew.c ft_lstmap.c ft_lstiter.c ft_lstdelone.c \
		   ft_lstdel.c ft_lstadd.c ft_hidenp.c ft_strcapitalize.c ft_strndup.c \
		   get_next_line.c
NAME = libft.a
FLAG = -Wall -Wextra -Werror
OBJ_NAME = $(SRC_NAME:.c=.o)
CC = clang $(FLAG)
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))


all : $(NAME)

$(NAME) :  $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "\r\033[K""\r\033[K""\033[32mCompilation terminee !\033[0m\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@printf "\033[42m \033[0m"
	@mkdir -p $(OBJ_PATH)
	@$(CC) -I./includes -o $@ -c $<

loading :
	@printf "Compilation en cours...\n"

clean :
	@rm -rf $(OBJ_PATH)
	@echo "\033[1;30mFichier .o supprime.\033[0m"

fclean : clean
	@rm -f $(NAME)
	@echo "\033[1;37mLibrairie detruite.\033[0m"

re : fclean $(NAME)

norm :
	@norminette srcs/ includes/

header :
	cp includes/libft.h ./
