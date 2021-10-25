#include "push_swap.h"

size_t	ft_value_len(t_value *stack);
t_value	*ft_value_last(t_value *stack);
t_value	*ft_value_new(int v, int chunk);
void	ft_value_add_back(t_value **stack, t_value *new);
void	ft_value_add_front(t_value **stack, t_value *new);

size_t	ft_value_len(t_value *stack)
{
	size_t	len;

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

t_value	*ft_value_last(t_value *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_value	*ft_value_new(int v, int chunk)
{
	t_value	*new;

	new = malloc(sizeof(t_value));
	if (!new)
		return (0);
	new->v = v;
	new->chunk = chunk;
	new->next = 0;
	return (new);
}

void	ft_value_add_back(t_value **stack, t_value *new)
{
	t_value	*tmp;

	if (!(*stack))
		*stack = new;
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_value_add_front(t_value **stack, t_value *new)
{
	if (!(*stack))
		*stack = new;
	else
	{
		new->next = *stack;
		*stack = new;
	}
}
