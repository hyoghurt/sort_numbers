#include "push_swap.h"

void	ft_s_s(t_stack *general)
{
	ft_s(&general->stack_a);
	ft_s(&general->stack_b);
}

void	ft_r_r(t_stack *general)
{
	ft_r(&general->stack_a);
	ft_r(&general->stack_b);
}

void	ft_r_r_r(t_stack *general)
{
	ft_rr(&general->stack_a);
	ft_rr(&general->stack_b);
}
