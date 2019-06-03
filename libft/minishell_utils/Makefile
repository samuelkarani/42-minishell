CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
NAME = libftminishell_utils.a
SRC = minishell_utils*.c node*.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
