NAME = push_swap

LIBFT = Libfth
LIBFTM = Libfth/libft.a
FLAGS = -Wall -Wextra -Werror

SRC = push_swap.c utils.c ft_error.c

all:
	make -C $(LIBFT)
	cc $(FLAGS) $(LIBFTM) $(SRC) -o $(NAME)
fclean:
	make -C $(LIBFT) fclean
