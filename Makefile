NAME = libftprintf.a
HEAD = ft_printf.h
LIBDIR = libft
SRC = *.c libft/*.c
CC = gcc
FLAG = -c
OBJ = *.o

all: $(NAME)

$(NAME): $(SRC) $(HEAD)
	@$(CC) $(FLAG) $(SRC)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(OBJ)

re: fclean all

.PHONY: clean fclean re
