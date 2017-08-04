NAME = libftprintf.a
HEAD = ft_printf.h
LIBDIR = libft
SRC = *.c libft/*.c
CC = gcc
FLAG = -c
OBJ = *.o

all: $(NAME) clean

$(NAME): $(SRC) $(HEAD)
	@$(CC) $(FLAG) $(SRC)
	@ar rc $(NAME) $(OBJ)
	gcc main.c libftprintf.a

git : clean
	git add *

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(OBJ)

re: fclean all

.PHONY: clean fclean re

gitall:
	git add .
	git commit -m "${GIT_MSG}"
	git push
