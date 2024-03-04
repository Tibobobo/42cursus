SRCS	=	./ft_read.s \
			./ft_strcmp.s \
			./ft_strcpy.s \
			./ft_strdup.s \
			./ft_strlen.s \
			./ft_write.s \

B_SRCS  =	./ft_list_size_bonus.s \
			./ft_list_push_front_bonus.s \
		
OBJS	=	$(SRCS:%.s=%.o)

B_OBJS  =	$(B_SRCS:%.s=%.o)

NAME	=	libasm.a

NASM	=	nasm

NASMFLAGS = -felf64

all:		$(NAME)

%.o:		%.s
	$(NASM) $(NASMFLAGS) $< -o $(<:%.s=%.o)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean:		clean
	rm -f $(NAME)
	rm -f ./a.out

bonus:	$(OBJS) $(B_OBJS)
	ar rc $(NAME) $(OBJS) $(B_OBJS)

re:			fclean all

.PHONY:		all clean fclean re