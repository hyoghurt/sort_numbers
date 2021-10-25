/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoghurt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:24:39 by hyoghurt          #+#    #+#             */
/*   Updated: 2021/06/02 21:55:11 by hyoghurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_init(t_stack *general);
t_value		*ft_crt_stack_a(int argc, char **argv);
long int	ft_atoicus(const char *nptr);

void	ft_init(t_stack *general)
{
	general->stack_a = 0;
	general->stack_b = 0;
	general->print = 0;
}

t_value	*ft_crt_stack_a(int argc, char **argv)
{
	t_value		*stack;
	t_value		*new;
	long int	lonn;
	size_t		i;

	stack = 0;
	i = 0;
	while (++i < argc)
	{
		lonn = ft_atoicus(argv[i]);
		if (lonn > 2147483647 || lonn < -2147483648)
		{
			ft_value_clear(&stack);
			return (0);
		}
		new = ft_value_new((int)lonn, 0);
		if (!new)
		{
			ft_value_clear(&stack);
			return (0);
		}
		ft_value_add_back(&stack, new);
	}
	return (stack);
}

long int	ft_atoicus(const char *nptr)
{
	long int	result;
	size_t		i;
	int			d;

	result = 0;
	d = 1;
	i = 0;
	while ((nptr[i] <= 13 && nptr[i] >= 8) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			d = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		result = (nptr[i] - '0') + result * 10;
		i++;
	}
	return (result * d);
}
