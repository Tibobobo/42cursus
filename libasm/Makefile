SRCS	=	./ft_read.s \
			./ft_strcmp.s \
			./ft_strcpy.s \
			./ft_strdup.s \
			./ft_strlen.s \
			./ft_write.s \
		
OBJS	=	$(SRCS:%.s=%.o)

NAME	=	libasm.a

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

NASM	=	nasm

NASMFLAGS = -felf64

all:		$(NAME)

%.o:		%.s
	$(NASM) $(NASMFLAGS) $< -o $(<:%.s=%.o)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)
	rm -f ./a.out

re:			fclean all

compile: ./main.c $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME)

.PHONY:		all clean fclean re