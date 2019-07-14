CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftminishell_utils.a
SRC = minishell_utils.c minishell_utils2.c minishell_utils3.c minishell_utils4.c \
	minishell_utils5.c node.c node2.c node3.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
