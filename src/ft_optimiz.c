#include "push_swap.h"

int	ft_optimiz(t_stack *general);
int	ft_opt_both_p(t_list *bg, t_list *ls, char *s1, char *s2);
int	ft_opt_both_s(t_list *ls, char *s1, char *s2, char *s3);
int	ft_opt_p(t_list *bg, t_list *ls, char *s1, char *s2);
int	ft_opt_s(t_list *ls, char *s1, char *s2, char *s3);

int	ft_optimiz(t_stack *general)
{
	t_list	*ls;
	t_list	*bg;

	ls = general->print;
	bg = ls;
	while (ls)
	{
		if (ft_opt_both_p(bg, ls, "pb", "pa"))
			return (1);
		if (ft_opt_both_p(bg, ls, "ra", "rra"))
			return (1);
		if (ft_opt_both_p(bg, ls, "rb", "rrb"))
			return (1);
		if (ft_opt_both_s(ls, "rrb", "rra", "rrr"))
			return (1);
		if (ft_opt_both_s(ls, "rb", "ra", "rr"))
			return (1);
		if (ft_opt_both_s(ls, "sb", "sa", "ss"))
			return (1);
		bg = ls;
		ls = ls->next;
	}
	return (0);
}

int	ft_opt_both_p(t_list *bg, t_list *ls, char *s1, char *s2)
{
	if (ft_opt_p(bg, ls, s1, s2))
		return (1);
	if (ft_opt_p(bg, ls, s2, s1))
		return (1);
	return (0);
}

int	ft_opt_both_s(t_list *ls, char *s1, char *s2, char *s3)
{
	if (ft_opt_s(ls, s1, s2, s3))
		return (1);
	if (ft_opt_s(ls, s2, s1, s3))
		return (1);
	return (0);
}

int	ft_opt_p(t_list *bg, t_list *ls, char *s1, char *s2)
{
	if (!ft_strncmp(ls->content, s1, ft_strlen(s1) + 1))
	{
		if (ls->next)
		{
			if (!ft_strncmp(ls->next->content, s2, ft_strlen(s2) + 1))
			{
				bg->next = ls->next->next;
				free(ls->next->content);
				free(ls->next);
				free(ls->content);
				free(ls);
				return (1);
			}
		}
	}
	return (0);
}

int	ft_opt_s(t_list *ls, char *s1, char *s2, char *s3)
{
	t_list	*bg;

	if (!ft_strncmp(ls->content, s1, ft_strlen(s1) + 1))
	{
		if (ls->next)
		{
			if (!ft_strncmp(ls->next->content, s2, ft_strlen(s2) + 1))
			{
				bg = ls->next->next;
				free(ls->next->content);
				free(ls->next);
				ls->next = bg;
				ft_memcpy(ls->content, s3, ft_strlen(s3) + 1);
				return (1);
			}
		}
	}
	return (0);
}
