#include "push_swap.h"

void	ft_exec(t_stack *general);
void	ft_exec_big(t_stack *general);
void	ft_put_a_by_b(t_stack *general);
void	ft_put_b_by_a(t_stack *general);

void	ft_exec(t_stack *general)
{
	size_t	len;

	if (ft_check_sort_ascending(general->stack_a))
	{
		len = ft_value_len(general->stack_a);
		if (len == 2)
			ft_exec_2(general);
		else if (len == 3)
			ft_exec_3(general);
		else if (len == 5)
			ft_exec_5(general);
		else
			ft_exec_big(general);
	}
}

void	ft_exec_big(t_stack *general)
{
	while (ft_check_sort_ascending(general->stack_a)
		|| ft_value_len(general->stack_b))
	{
		if (ft_value_len(general->stack_b))
		{
			if (ft_check_sort_descending(general->stack_b))
				ft_exec_b(general);
		}
		if (ft_check_sort_ascending(general->stack_a))
			ft_exec_a(general);
		if (general->stack_a->chunk != 0)
			ft_put_b_by_a(general);
		ft_put_a_by_b(general);
	}
}

void	ft_put_a_by_b(t_stack *general)
{
	size_t	len_chunk;
	int		chunk;

	if (!ft_check_sort_ascending(general->stack_a))
	{
		if (!ft_check_sort_descending(general->stack_b))
		{
			chunk = general->stack_a->chunk;
			len_chunk = ft_len_chunk(general->stack_b);
			while (len_chunk)
			{
				ft_operation_p('b', general, chunk);
				len_chunk--;
			}
		}
	}
}

void	ft_put_b_by_a(t_stack *general)
{
	size_t	len_chunk;
	int		chunk;

	if (!ft_check_sort_ascending(general->stack_a))
	{
		if (!ft_check_sort_descending(general->stack_b))
		{
			chunk = general->stack_b->chunk;
			len_chunk = ft_len_chunk(general->stack_a);
			while (len_chunk)
			{
				ft_operation_p('a', general, chunk);
				len_chunk--;
			}
		}
	}
}
