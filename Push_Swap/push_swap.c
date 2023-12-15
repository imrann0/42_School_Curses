#include "Libfth/libft.h"
#include "push_swap.h"
#include <stdio.h>

void ft_push_swap(char **av, int control)
{
	t_stack	*stack;
	int		size;
	int		i;

	i = -1;
	stack = malloc(sizeof(t_stack));
	size = ft_word_counter(av);
	stack->a = malloc(sizeof(int) * size);
	if (!stack->a)
		return ;
	stack->size_a = size;
	stack->b = malloc(sizeof(int) * size);
	if (!stack->b)
	{
		free(stack->a);
		return ;
	}
	stack->size_b = 0;
	while (++i < size)
		stack->a[i] = ft_ps_atoi(av[i], stack, av, control);
}

int main(int ar,char **av)
{
	if (ar == 2)
	{
		av++;
		av = ft_split(*av,' ');
		while(*av)
		{
			av++;
			ft_push_swap(av,2);
		}
	}
	else
		ft_push_swap(++av,2);

}
