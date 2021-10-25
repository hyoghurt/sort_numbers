#include "push_swap.h"

int	ft_max(t_value *stack)
{
	int	max;
	int	chnk;

	chnk = stack->chunk;
	max = stack->v;
	while (stack && chnk == stack->chunk)
	{
		if (max < stack->v)
			max = stack->v;
		stack = stack->next;
	}
	return (max);
}

int	ft_min(t_value *stack)
{
	int	min;
	int	chnk;

	chnk = stack->chunk;
	min = stack->v;
	while (stack && chnk == stack->chunk)
	{
		if (min > stack->v)
			min = stack->v;
		stack = stack->next;
	}
	return (min);
}

int	ft_mid(t_value *stack)
{
	int	max;
	int	min;

	max = ft_max(stack);
	min = ft_min(stack);
	return ((max + min) / 2);
}

int	ft_mid_ch(char ch, t_stack *general)
{
	if (ch == 'a')
		return (ft_mid(general->stack_a));
	return (ft_mid(general->stack_b));
}
