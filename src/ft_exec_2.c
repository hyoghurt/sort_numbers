#include "push_swap.h"

void	ft_exec_b(t_stack *general);
void	ft_exec_a(t_stack *general);
void	ft_exec_long(char ch, t_stack *general);
void	ft_exec_rest(char ch, t_stack *general);

void	ft_exec_b(t_stack *general)
{
	size_t	len_chunk;

	len_chunk = ft_len_chunk(general->stack_b);
	while (len_chunk > 1 && ft_check_sort_descending(general->stack_b))
	{
		if (len_chunk == 2)
			ft_operation_s('b', general);
		else
			ft_exec_long('b', general);
		len_chunk = ft_len_chunk(general->stack_b);
	}
	ft_exec_rest('a', general);
}

void	ft_exec_a(t_stack *general)
{
	size_t	len_chunk;

	len_chunk = ft_len_chunk(general->stack_a);
	while (len_chunk > 1 && ft_check_sort_ascending(general->stack_a))
	{
		if (len_chunk == 2)
			ft_operation_s('a', general);
		else
			ft_exec_long('a', general);
		len_chunk = ft_len_chunk(general->stack_a);
	}
	ft_exec_rest('b', general);
}

void	ft_exec_long(char ch, t_stack *general)
{
	int		mid;
	int		chunk;
	size_t	len_chunk;
	size_t	count;

	count = 0;
	mid = ft_mid_ch(ch, general);
	len_chunk = ft_len_chunk_ch(ch, general);
	chunk = ft_find_max_chunk(general);
	while (len_chunk)
	{
		if (ft_compare_mid(ch, general, mid))
			ft_operation_p(ch, general, chunk);
		else
			count += ft_operation_r(ch, general);
		len_chunk--;
	}
	while (count)
		count -= ft_operation_rr(ch, general);
}

void	ft_exec_rest(char ch, t_stack *general)
{
	int		chunk;
	size_t	len_chunk;

	len_chunk = ft_len_chunk_ch(ch, general);
	chunk = general->stack_a->chunk;
	if (ch == 'a')
		chunk = general->stack_b->chunk;
	while (len_chunk < 3 && len_chunk != 0 && general->stack_a->chunk != 0)
	{
		if (len_chunk == 1)
			ft_operation_p(ch, general, chunk);
		else
		{
			ft_operation_s(ch, general);
			ft_operation_p(ch, general, chunk);
			ft_operation_p(ch, general, chunk);
		}
		len_chunk = ft_len_chunk_ch(ch, general);
	}
}
