#include "push_swap.h"

int		ft_return_error(void);
void	ft_value_clear(t_value **stack);
void	ft_exit(t_stack general);

int	ft_return_error(void)
{
	ft_putstr_fd("Error\n", 1);
	return (1);
}

void	ft_value_clear(t_value **stack)
{
	t_value	*tmp;
	t_value	*bg;

	tmp = *stack;
	while (tmp)
	{
		bg = tmp;
		tmp = tmp->next;
		free(bg);
	}
	*stack = 0;
}

void	ft_exit(t_stack general)
{
	if (general.stack_a)
		ft_value_clear(&general.stack_a);
	if (general.stack_b)
		ft_value_clear(&general.stack_b);
	if (general.print)
		ft_lstclear(&general.print, free);
}
