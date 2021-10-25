#include "push_swap.h"

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
	{
		ft_exit(general);
		return (ft_return_error());
	}
	ft_exec(&general);
	while (ft_optimiz(&general))
		;
	ft_print_print(general);
	ft_exit(general);
	return (0);
}
