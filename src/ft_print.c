#include "push_swap.h"

void	ft_add_operation_print(char *string, t_stack *general)
{
	t_list	*new;
	char	*content;

	content = ft_strdup(string);
	if (!content)
		ft_exit(*general);
	new = ft_lstnew(content);
	if (!new)
	{
		free(content);
		ft_exit(*general);
	}
	ft_lstadd_back(&general->print, new);
}

void	ft_print_print(t_stack general)
{
	t_list	*ls;

	ls = general.print;
	while (ls)
	{
		if (((char *)ls->content)[0] != '\0')
		{
			ft_putstr_fd((char *)ls->content, 1);
			ft_putstr_fd("\n", 1);
		}
		ls = ls->next;
	}
}
