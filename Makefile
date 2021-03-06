# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/21 12:24:17 by qgirard           #+#    #+#              #
#    Updated: 2019/01/31 17:12:52 by qgirard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h

SRC = libft/ft_strlen.c libft/ft_strdup.c libft/ft_strcpy.c libft/ft_strncpy.c \
		libft/ft_strcat.c libft/ft_strncat.c libft/ft_strchr.c \
		libft/ft_strrchr.c libft/ft_strstr.c libft/ft_strnstr.c \
		libft/ft_strcmp.c libft/ft_strncmp.c libft/ft_isalpha.c \
		libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c \
		libft/ft_isprint.c libft/ft_toupper.c libft/ft_tolower.c \
		libft/ft_memset.c libft/ft_bzero.c libft/ft_memcpy.c \
		libft/ft_memccpy.c libft/ft_strlcat.c libft/ft_atoi.c \
		libft/ft_memmove.c libft/ft_memchr.c libft/ft_memcmp.c \
		libft/ft_memalloc.c libft/ft_memdel.c libft/ft_strnew.c \
		libft/ft_strdel.c libft/ft_strclr.c libft/ft_striter.c \
		libft/ft_striteri.c libft/ft_strequ.c libft/ft_strnequ.c \
		libft/ft_strsub.c libft/ft_strjoin.c libft/ft_strtrim.c \
		libft/ft_strsplit.c libft/ft_putchar.c libft/ft_putstr.c \
		libft/ft_putendl.c libft/ft_strmap.c libft/ft_strmapi.c \
		libft/ft_putnbr.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c \
		libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_itoa.c \
		libft/ft_lstnew.c libft/ft_lstdelone.c libft/ft_lstdel.c \
		libft/ft_lstadd.c libft/ft_lstiter.c libft/ft_lstmap.c \
		libft/ft_range.c libft/ft_concat_params.c libft/ft_is_sort.c \
		libft/ft_swap.c libft/ft_lstcount.c libft/ft_printlist.c \
		libft/ft_realloc.c libft/ft_strjoinf.c libft/get_next_line.c \
		libft/ft_strnjoinf.c libft/ft_itoa_base.c libft/ft_toupperstr.c \
		libft/ft_tochartostr.c libft/ft_utoa_base.c libft/ft_reallocstr.c \
		libft/ft_ltoa.c libft/ft_ultoa_base.c libft/ft_lltoa.c libft/ft_stoa.c \
		libft/ft_sctoa.c libft/ft_uctoa_base.c libft/ft_ustoa_base.c \
		checkoptions.c checktype.c convertinstr.c convertinstrwsize.c \
		convertwidth.c ft_printf.c convertprecision.c exception.c \
		checksignerror.c convertprecisionprime.c freerror.c convertfloats.c \
		lists.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		ar rc $(NAME) $(OBJ) $(HEADER)
		ranlib $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c -I $(HEADER) $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
