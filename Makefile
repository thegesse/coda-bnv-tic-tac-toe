NAME = exec
SRCS = main.c \
	function.c
all: $(NAME)
$(NAME): $(SRCS)
	gcc $(SRCS) -o $(NAME)
fclean:
	rm -f $(NAME)
re: fclean all
