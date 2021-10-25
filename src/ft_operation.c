#include "push_swap.h"

void	ft_operation_s(char ch, t_stack *general)
{
	if (ch == 'a')
	{
		if (general->stack_a->v > general->stack_a->next->v)
		{
			ft_s(&general->stack_a);
			ft_add_operation_print("sa", general);
		}
	}
	else
	{
		if (general->stack_b->v < general->stack_b->next->v)
		{
			ft_s(&general->stack_b);
			ft_add_operation_print("sb", general);
		}
	}
}

void	ft_operation_p(char ch, t_stack *general, int chunk)
{
	if (ch == 'a')
	{
		general->stack_a->chunk = chunk;
		ft_p_one_in_two(&general->stack_a, &general->stack_b);
		ft_add_operation_print("pb", general);
	}
	else
	{
		general->stack_b->chunk = chunk;
		ft_p_one_in_two(&general->stack_b, &general->stack_a);
		ft_add_operation_print("pa", general);
	}
}

int	ft_operation_r(char ch, t_stack *general)
{
	if (ch == 'a')
	{
		ft_r(&general->stack_a);
		ft_add_operation_print("ra", general);
	}
	else
	{
		ft_r(&general->stack_b);
		ft_add_operation_print("rb", general);
	}
	return (1);
}

int	ft_operation_rr(char ch, t_stack *general)
{
	if (ch == 'a')
	{
		ft_rr(&general->stack_a);
		ft_add_operation_print("rra", general);
	}
	else
	{
		ft_rr(&general->stack_b);
		ft_add_operation_print("rrb", general);
	}
	return (1);
}
