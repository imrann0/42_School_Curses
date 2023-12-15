#include "push_swap.h"

int ft_word_counter(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int ft_jumper(char *str, int *sign)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) && str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}
int ft_number(char *str, int i)
{
	if (str[i] == '\0')
		return 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	return (1);
}
#include <stdio.h>
int ft_ps_atoi(char *str, t_stack *stack, char **av, int control)
{
	unsigned int		i;
	int					sign;
	unsigned long int	num;

	num = 0;
	sign = 1;
	i = ft_jumper(str,&sign);
	if (!(ft_number(str,i)))
		ft_free_av(av,stack,control);
	while(str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_free_av(av, stack, control);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}
