NAME = ft_printf
HEAD = ft_printf.h
LIB = libft.a
LIBDIR = libft
SRC = *.c
FLAG = -g
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC) $(HEAD)
	@echo "Compiling \033[92m$(LIB)\033[0m..."
	@make -C $(LIBDIR)/
	@echo "Compiling \033[92m$(NAME)\033[0m..."
	@gcc $(SRC) $(FLAG) $(LIBDIR)/$(LIB) -o $(NAME)
	@echo "$(NAME) compilation:\033[92m OK\033[0m"

clean:
	@echo "Deleting:\033[33m $(LIB) and *.o\033[0m"
	@rm -f $(OBJ)
	@make -C $(LIBDIR)/ clean

fclean: clean
	@echo "Deleting:\033[33m $(NAME)\033[0m"
	@echo "Deleting:\033[33m $(LIB)\033[0m"
	@rm -f $(NAME)
	@rm -f $(LIBDIR)/$(LIB)

re: fclean all

.PHONY: clean fclean re
