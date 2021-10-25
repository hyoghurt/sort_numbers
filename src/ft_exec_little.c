#include "push_swap.h"

void	ft_exec_2(t_stack *general);
void	ft_exec_3(t_stack *general);
void	ft_exec_3_a(t_stack *general);
void	ft_exec_5(t_stack *general);
void	ft_exec_5_a(t_stack *general);

void	ft_exec_2(t_stack *general)
{
	if (general->stack_a->v > general->stack_a->next->v)
		ft_operation_s('a', general);
}

void	ft_exec_3(t_stack *general)
{
	if (general->stack_a->v > general->stack_a->next->v)
		ft_exec_3_a(general);
	else
	{
		if (general->stack_a->v > general->stack_a->next->next->v)
			ft_operation_rr('a', general);
		else
		{
			ft_s(&general->stack_a);
			ft_add_operation_print("sa", general);
			ft_operation_r('a', general);
		}
	}
}

void	ft_exec_3_a(t_stack *general)
{
	if (general->stack_a->next->next->v > general->stack_a->v)
		ft_operation_s('a', general);
	else if (general->stack_a->next->next->v > general->stack_a->next->v)
		ft_operation_r('a', general);
	else
	{
		ft_operation_s('a', general);
		ft_operation_rr('a', general);
	}
}

void	ft_exec_5(t_stack *general)
{
	ft_exec_5_a(general);
	if (general->stack_b->v < general->stack_b->next->v)
	{
		ft_s(&general->stack_b);
		ft_add_operation_print("sb", general);
	}
	if (ft_check_sort_ascending(general->stack_a))
		ft_exec_3(general);
	ft_operation_p('b', general, 0);
	ft_operation_p('b', general, 0);
}

void	ft_exec_5_a(t_stack *general)
{
	int		mid;
	size_t	len_chunk;
	size_t	count;

	count = 0;
	mid = ft_mid_ch('a', general);
	len_chunk = ft_len_chunk_ch('a', general);
	while (len_chunk && count < 2)
	{
		if (ft_compare_mid('a', general, mid))
		{
			ft_operation_p('a', general, 0);
			count++;
		}
		else
			ft_operation_r('a', general);
		len_chunk--;
	}
}
