# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 10:48:17 by tgrasset          #+#    #+#              #
#    Updated: 2022/11/17 10:04:49 by tgrasset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	./ft_isalpha.c \
			./ft_isdigit.c \
			./ft_isalnum.c \
			./ft_isascii.c \
			./ft_isprint.c \
			./ft_strlen.c	\
			./ft_memset.c \
			./ft_bzero.c	\
			./ft_memcpy.c	\
			./ft_memmove.c \
			./ft_strlcpy.c \
			./ft_strlcat.c \
			./ft_toupper.c \
			./ft_tolower.c \
			./ft_strchr.c \
			./ft_strrchr.c \
			./ft_strncmp.c \
			./ft_memchr.c \
			./ft_memcmp.c \
			./ft_strnstr.c \
			./ft_atoi.c \
			./ft_calloc.c \
			./ft_strdup.c \
			./ft_substr.c \
			./ft_strjoin.c \
			./ft_strtrim.c \
			./ft_split.c \
			./ft_itoa.c \
			./ft_strmapi.c \
			./ft_striteri.c \
			./ft_putchar_fd.c \
			./ft_putstr_fd.c \
			./ft_putendl_fd.c \
			./ft_putnbr_fd.c \
			./ft_printf.c \
			./ft_printf_utils/print_char.c \
			./ft_printf_utils/print_dec.c \
			./ft_printf_utils/print_int.c \
			./ft_printf_utils/print_low_hex.c \
			./ft_printf_utils/print_percent.c \
			./ft_printf_utils/print_ptr.c \
			./ft_printf_utils/print_str.c \
			./ft_printf_utils/print_unsigned_dec.c \
			./ft_printf_utils/print_up_hex.c \
			./get_next_line.c \
			./get_next_line_utils.c \
			./ft_lstnew.c \
			./ft_lstadd_front.c \
			./ft_lstsize.c \
			./ft_lstlast.c \
			./ft_lstadd_back.c \
			./ft_lstdelone.c \
			./ft_lstclear.c \
			./ft_lstiter.c \
			./ft_lstmap.c \
		
OBJS	=	$(SRCS:%.c=%.o)

NAME	=	libft.a

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

all:		$(NAME)

%.o:		%.c
	$(CC) $(CFLAGS) -c $< -o $(<:%.c=%.o)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
