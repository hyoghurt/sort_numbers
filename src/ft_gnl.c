/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoghurt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:04:28 by hyoghurt          #+#    #+#             */
/*   Updated: 2021/06/08 08:08:41 by hyoghurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*my_ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(len + 1);
	if (!new)
		return (0);
	i = -1;
	j = -1;
	while (s1[++i])
		new[i] = s1[i];
	while (s2[++j])
	{
		new[i] = s2[j];
		i++;
	}
	new[i] = '\0';
	free(s1);
	return (new);
}

char	*my_create(char **stack)
{
	char	*new;
	char	*pak;
	char	*pak2;

	pak = ft_strchr(*stack, '\n');
	if (!pak)
	{
		new = ft_strdup(*stack);
		free(*stack);
		*stack = 0;
	}
	else
	{
		new = ft_substr(*stack, 0, pak - *stack);
		pak2 = ft_strdup(pak + 1);
		free(*stack);
		*stack = pak2;
	}
	return (new);
}

int	my_free(char *string)
{
	free(string);
	return (-1);
}

int	ft_bytes(char *buf, int fd, char **stack)
{
	int	bytes;

	bytes = 1;
	while (bytes && !(ft_strchr(*stack, '\n')))
	{
		ft_bzero(buf, 11);
		bytes = read(fd, buf, 10);
		if (bytes >= 0)
		{
			*stack = my_ft_strjoin(*stack, buf);
			if (!(*stack))
				return (bytes);
		}
	}
	return (bytes);
}

int	ft_gnl(int fd, char **line)
{
	char			*buf;
	static char		*stack;
	int				bytes;

	buf = (char *)malloc(10 + 1);
	if (fd < 0 || !line || !buf)
		return (-1);
	if (!stack)
	{
		stack = ft_strdup("");
		if (!stack)
			return (my_free(buf));
	}
	bytes = ft_bytes(buf, fd, &stack);
	if (!stack)
		return (my_free(buf));
	free(buf);
	*line = my_create(&stack);
	if (!(*line) || bytes < 0)
		return (my_free(stack));
	if (stack)
		return (1);
	return (0);
}
