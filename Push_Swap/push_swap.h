#include "Libfth/libft.h"

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
}t_stack;

int ft_word_counter(char **av);
int ft_ps_atoi(char *str, t_stack *stack, char **av, int control);
int ft_word_counter(char **av);

// ft_Error
void ft_free_av(char **av,t_stack *stack, int control);
void ft_error(t_stack *stack);

