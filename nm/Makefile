NAME = ft_nm

SOURCES_DIR = ./src/

BUILD_DIR = ./build/

SOURCES =	main.c \
			parseArguments.c \
			quit.c \
			checkFileType.c \
			parseFile64.c \
			parseFile32.c \
			utils.c \

OBJECTS		= $(addprefix ${BUILD_DIR}, ${SOURCES:.c=.o})

DEPS := $(OBJECTS:.o=.d)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

LIBFT_DIR = ./libft/
		
$(BUILD_DIR)%.o: $(SOURCES_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJECTS)
			make -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_DIR)libft.a -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(BUILD_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM)  $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean $(NAME)

.PHONY: all clean fclean re

-include $(DEPS)