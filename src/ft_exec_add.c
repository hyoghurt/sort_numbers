#include "push_swap.h"

size_t	ft_len_chunk(t_value *stack);
size_t	ft_len_chunk_ch(char ch, t_stack *general);
int		ft_find_max_chunk(t_stack *general);
int		ft_compare_mid(char ch, t_stack *general, int mid);

size_t	ft_len_chunk(t_value *stack)
{
	size_t	len;
	int		chunk;

	if (!stack)
		return (0);
	len = 0;
	chunk = stack->chunk;
	while (stack && chunk == stack->chunk)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

size_t	ft_len_chunk_ch(char ch, t_stack *general)
{
	if (ch == 'a')
		return (ft_len_chunk(general->stack_a));
	return (ft_len_chunk(general->stack_b));
}

int	ft_find_max_chunk(t_stack *general)
{
	int		chunk_a;
	int		chunk_b;

	chunk_a = 1;
	chunk_b = 1;
	if (general->stack_a)
		chunk_a = general->stack_a->chunk + 1;
	if (general->stack_b)
		chunk_b = general->stack_b->chunk + 1;
	if (chunk_a > chunk_b)
		return (chunk_a);
	return (chunk_b);
}

int	ft_compare_mid(char ch, t_stack *general, int mid)
{
	if (ch == 'a')
	{
		if (general->stack_a->v < mid)
			return (1);
	}
	else
	{
		if (general->stack_b->v > mid)
			return (1);
	}
	return (0);
}
