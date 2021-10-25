#include "push_swap.h"

void	print_stack(t_stack general)
{
	size_t	i;
	size_t	len_a;
	size_t	len_b;
	t_value	*stack_a;
	t_value	*stack_b;

	stack_a = general.stack_a;
	stack_b = general.stack_b;

	len_a = ft_value_len(stack_a);
	len_b = ft_value_len(stack_b);

	while (len_a || len_b)
	{
		if (len_a >= len_b)
		{
			printf("%10d", stack_a->v);
			printf(" |%d", stack_a->chunk);
			stack_a = stack_a->next;
		}
		if (len_a < len_b)
		{
			printf("%13s", "");
		}
		if (len_b >= len_a)
		{
			printf("%12d", stack_b->v);
			printf(" |%d", stack_b->chunk);
			if (stack_b->next)
				stack_b = stack_b->next;
		}
		if (len_a > len_b)
			len_a--;
		else if (len_b > len_a)
			len_b--;
		else if (len_a == len_b)
		{
			len_a--;
			len_b--;
		}
		printf("\n");
	}
	printf("----------");
	printf("     ");
	printf("----------");
	printf("\n");
	printf("   stack_a");
	printf("        stack_b");
	printf("\n\n");
}
