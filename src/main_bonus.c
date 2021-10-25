#include "push_swap.h"

t_list	*ft_read(t_stack *general)
{
	t_list	*list;
	t_list	*new;
	char	*line;
	int		res;

	list = 0;
	res = ft_gnl(0, &line);
	while (res > 0)
	{
		new = ft_lstnew(line);
		if (!new)
		{
			ft_lstclear(&list, free);
			return (0);
		}
		ft_lstadd_back(&list, new);
		res = ft_gnl(0, &line);
	}
	return (list);
}

int	ft_checker_a(char *s1, t_stack *general)
{
	if (ft_strlen(s1) != 2)
		return (0);
	else if (!ft_strncmp("sa", s1, 3))
		ft_s(&general->stack_a);
	else if (!ft_strncmp("sb", s1, 3))
		ft_s(&general->stack_b);
	else if (!ft_strncmp("ss", s1, 3))
		ft_s_s(general);
	else if (!ft_strncmp("ra", s1, 3))
		ft_r(&general->stack_a);
	else if (!ft_strncmp("rb", s1, 3))
		ft_r(&general->stack_b);
	else if (!ft_strncmp("rr", s1, 3))
		ft_r_r(general);
	else if (!ft_strncmp("pa", s1, 3))
		ft_p_one_in_two(&general->stack_b, &general->stack_a);
	else if (!ft_strncmp("pb", s1, 3))
		ft_p_one_in_two(&general->stack_a, &general->stack_b);
	else
		return (0);
	return (1);
}

int	ft_checker_b(char *s1, t_stack *general)
{
	if (ft_strlen(s1) != 3)
		return (0);
	else if (!ft_strncmp("rra", s1, 4))
		ft_rr(&general->stack_a);
	else if (!ft_strncmp("rrb", s1, 4))
		ft_rr(&general->stack_b);
	else if (!ft_strncmp("rrr", s1, 4))
		ft_r_r_r(general);
	else
		return (0);
	return (1);
}

int	ft_checker(t_stack *general)
{
	t_list	*list;
	t_list	*tmp;

	list = ft_read(general);
	if (!list)
		return (1);
	tmp = list;
	while (tmp)
	{
		if (!ft_checker_a(tmp->content, general))
		{
			if (!ft_checker_b(tmp->content, general))
			{
				ft_lstclear(&list, free);
				return (1);
			}
		}
		tmp = tmp->next;
	}
	ft_lstclear(&list, free);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack		general;

	ft_init(&general);
	if (ft_check_arg(argc, argv))
		return (ft_return_error());
	general.stack_a = ft_crt_stack_a(argc, argv);
	if (!general.stack_a)
		return (ft_return_error());
	if (ft_check_duplicat(general.stack_a))
		ft_putstr_fd("Error\n", 1);
	else if (ft_checker(&general))
		ft_putstr_fd("Error\n", 1);
	else if (!ft_check_sort_ascending(general.stack_a)
		&& !ft_value_len(general.stack_b))
	{
		ft_putstr_fd("OK\n", 1);
	}
	else
		ft_putstr_fd("KO\n", 1);
	ft_exit(general);
	return (0);
}
