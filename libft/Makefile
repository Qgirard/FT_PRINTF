# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 16:43:37 by qgirard           #+#    #+#              #
#    Updated: 2019/01/03 15:16:01 by qgirard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

HEADER = libft.h

CFLAGS = -Wall -Werror -Wextra

SRC = ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
		ft_strncat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
		ft_strcmp.c ft_strncmp.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memset.c \
		ft_bzero.c ft_memcpy.c ft_memccpy.c ft_strlcat.c ft_atoi.c \
		ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c \
		ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
		ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
		ft_strsplit.c ft_putchar.c ft_putstr.c ft_putendl.c ft_strmap.c \
		ft_strmapi.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_lstnew.c ft_lstdelone.c \
		ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_range.c \
		ft_concat_params.c ft_is_sort.c ft_swap.c ft_lstcount.c ft_printlist.c \
		ft_realloc.c ft_strjoinf.c get_next_line.c ft_strnjoinf.c \
		ft_itoa_base.c ft_toupperstr.c ft_tochartostr.c ft_utoa_base.c \
		ft_reallocstr.c ft_ltoa.c ft_ultoa_base.c ft_lltoa.c ft_stoa.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ) $(HEADER)
	ranlib $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
