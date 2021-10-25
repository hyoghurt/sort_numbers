#include "push_swap.h"

int	ft_check_sort_ascending(t_value *stack);
int	ft_check_sort_descending(t_value *stack);
int	ft_check_digit(char *s);
int	ft_check_duplicat(t_value *stack);
int	ft_check_arg(int argc, char **argv);

int	ft_check_sort_ascending(t_value *stack)
{
	int	tmp;
	int	chunk;

	tmp = stack->v;
	chunk = stack->chunk;
	while (stack)
	{
		if (chunk != stack->chunk)
			break ;
		if (stack->v < tmp)
			return (1);
		tmp = stack->v;
		stack = stack->next;
	}
	return (0);
}

int	ft_check_sort_descending(t_value *stack)
{
	int	tmp;
	int	chunk;

	tmp = stack->v;
	chunk = stack->chunk;
	while (stack)
	{
		if (chunk != stack->chunk)
			break ;
		if (stack->v > tmp)
			return (1);
		tmp = stack->v;
		stack = stack->next;
	}
	return (0);
}

int	ft_check_digit(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
	{
		if (i == 0)
		{
			if ((s[i] < '0' || s[i] > '9') && s[i] != '-')
				return (1);
		}
		else if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_duplicat(t_value *stack)
{
	t_value	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->v == tmp->v)
				return (1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}

int	ft_check_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_check_digit(argv[i]))
			return (1);
		i++;
	}
	return (0);
}
