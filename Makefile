# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 14:27:23 by lluque            #+#    #+#              #
#    Updated: 2023/11/03 15:14:16 by lluque           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDR = libft.h

SRC = ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_strlen.c \
	  ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_strlcpy.c \
	  ft_strlcat.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strncmp.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strnstr.c \
	  ft_atoi.c \
	  ft_calloc.c \
	  ft_strdup.c \
	  ft_substr.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_split.c \
	  ft_itoa.c \
	  ft_strmapi.c \
	  ft_striteri.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_islower.c \
	  ft_isupper.c

SRC_BONUS = ft_lstnew_bonus.c \
		   	ft_lstadd_front_bonus.c \
		   	ft_lstsize_bonus.c \
		   	ft_lstlast_bonus.c \
		   	ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c 

OBJ = $(SRC:%.c=%.o)

OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

CC_FLAGS = -Wall -Werror -Wextra

AR_FLAGS = -cru

NAME = libft.a

all:$(NAME)

$(NAME):$(OBJ)
	ar $(AR_FLAGS) $(NAME) $(OBJ)

bonus:$(OBJ_BONUS)
	ar $(AR_FLAGS) $(NAME) $(OBJ_BONUS)

$(OBJ): %.o: %.c
	cc -c $(CC_FLAGS) $^ -o $@

$(OBJ_BONUS): %.o: %.c
	cc -c $(CC_FLAGS) $^ -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean:clean
	rm -f $(NAME)

re: fclean all

help:
	@echo
	@echo "    usar 'make', 'make all' o 'make $(NAME) para compilar solo lo que haya sido modificado (.o y binario final)"
	@echo "    usar 'make clean' para borrar los archivos .o"
	@echo "    usar 'make fclean para borar los archivos .o y el binario"
	@echo "    usar 'make re' para borrar todos los .o y el binario final y volver a compilar todo"
	@echo

# Esto evita problemas si existieran archivos con estos nombres.
# Pues son targets aquí y no se supone que representen archivos
.PHONY: all clean fclean re bonus help
