CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = minishell

SRC = cd.c env.c minishell.c replace.c echo.c exit.c minishell2.c shell_split.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	@make -C libft
	@make -C libft/ft_printf
	@make -C libft/get_next_line
	@make -C libft/minishell_utils
	@$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -Llibft/ft_printf -lftprintf \
		-Llibft/get_next_line -lftget_next_line -Llibft/minishell_utils -lftminishell_utils -o $@

clean:
	@make clean -C libft
	@make clean -C libft/ft_printf
	@make clean -C libft/get_next_line
	@make clean -C libft/minishell_utils
	@rm -f *.o

fclean:
	@make fclean -C libft
	@make fclean -C libft/ft_printf
	@make fclean -C libft/get_next_line
	@make fclean -C libft/minishell_utils
	@rm -f *.o
	@rm -f $(NAME)

norm:
	norminette $(SRC) minishell.h

norm-all: norm
	norminette libft/{*.c,*.h} libft/ft_printf/{*.c,*.h} libft/get_next_line/{*.c,*.h} libft/minishell_utils/{*.c,*.h}

re: fclean all

.PHONY: all clean fclean re norm norm-all
