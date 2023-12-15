	#include "push_swap.h"
	#include <unistd.h>

	void ft_free_av(char **av,t_stack *stack, int control)
	{
		int i;

		i = 0;
		if (control == 2)
		{
			while(av[i])
			{
				free(av[i]);
				i++;
			}
			free(av);
		}
		ft_error(stack);
	}

	void ft_error(t_stack *stack)
	{
		free (stack->a);
		free (stack->b);
		free (stack);
		write(2,"Error\n",6);
	}
