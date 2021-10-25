#include "push_swap.h"

void	ft_s(t_value **stack)
{
	t_value	*tmp_bg;
	t_value	*tmp_nx;
	t_value	*tmp_nx_nx;

	if (ft_value_len(*stack) >= 2)
	{
		tmp_bg = *stack;
		tmp_nx = tmp_bg->next;
		tmp_nx_nx = tmp_nx->next;
		tmp_nx->next = tmp_bg;
		tmp_bg->next = tmp_nx_nx;
		*stack = tmp_nx;
	}
}

void	ft_r(t_value **stack)
{
	t_value	*bg;
	t_value	*last;

	if (ft_value_len(*stack) >= 2)
	{
		bg = *stack;
		last = ft_value_last(*stack);
		last->next = bg;
		*stack = bg->next;
		bg->next = 0;
	}
}

void	ft_rr(t_value **stack)
{
	t_value	*last;
	t_value	*tmp;

	if (ft_value_len(*stack) >= 2)
	{
		last = *stack;
		while (last->next)
		{
			tmp = last;
			last = last->next;
		}
		tmp->next = 0;
		last->next = *stack;
		*stack = last;
	}
}

void	ft_p_one_in_two(t_value **one, t_value **two)
{
	t_value	*st_a;

	st_a = *one;
	if (*one)
	{
		*one = st_a->next;
		st_a->next = 0;
		ft_value_add_front(two, st_a);
	}
}
