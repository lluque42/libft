# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 14:27:23 by lluque            #+#    #+#              #
#    Updated: 2023/11/11 08:38:25 by lluque           ###   ########.fr        #
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
	  ft_isupper.c \
	  ft_lstnew.c \
	  ft_lstadd_front.c \
	  ft_lstsize.c \
	  ft_lstlast.c \
	  ft_lstadd_back.c \
	  ft_lstdelone.c \
	  ft_lstclear.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_issign.c \
	  ft_isspace.c \
	  ft_pow.c \
	  ft_itoa_b.c \
	  ft_get_sym_table.c \
	  ft_ltoa.c \
	  ft_ltoa_b.c \
	  ft_print_memory.c \
	  ft_ultoa_b.c

OBJ = $(SRC:%.c=%.o)

CC_FLAGS = -Wall -Werror -Wextra

AR_FLAGS = -cru

NAME = libft.a

all:$(NAME)

$(NAME):$(OBJ)
	ar $(AR_FLAGS) $(NAME) $(OBJ)

$(OBJ): %.o: %.c
	cc -c $(CC_FLAGS) $^ -o $@

clean:
	rm -f $(OBJ)

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
.PHONY: all clean fclean re help
