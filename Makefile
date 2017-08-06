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

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(OBJ)

re: fclean all

.PHONY: clean fclean re

git:
	# tester si message existe et != ' '
	# tester si chaque partie a fonctionne
	@git add .
	@git commit -m "${MSG}"
	git push
