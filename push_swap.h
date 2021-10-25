#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>

typedef struct s_value
{
	int				v;
	int				chunk;
	struct s_value	*next;
}					t_value;

typedef struct s_stack
{
	t_value			*stack_a;
	t_value			*stack_b;
	t_list			*print;
}					t_stack;

int			ft_gnl(int fd, char **line);

size_t		ft_value_len(t_value *stack);
t_value		*ft_value_last(t_value *stack);
t_value		*ft_value_new(int v, int chunk);
void		ft_value_add_back(t_value **stack, t_value *new);
void		ft_value_add_front(t_value **stack, t_value *new);
void		ft_value_clear(t_value **stack);

void		ft_init(t_stack *general);
long int	ft_atoicus(const char *nptr);
t_value		*ft_crt_stack_a(int argc, char **argv);

void		ft_s(t_value **stack);
void		ft_p_one_in_two(t_value **one, t_value **two);
void		ft_r(t_value **stack);
void		ft_rr(t_value **stack);

int			ft_check_digit(char *s);
int			ft_check_duplicat(t_value *stack);
int			ft_check_arg(int argc, char **argv);
int			ft_check_sort_ascending(t_value *stack);
int			ft_check_sort_descending(t_value *stack);

size_t		ft_len_chunk(t_value *stack);
size_t		ft_len_chunk_ch(char ch, t_stack *general);
int			ft_find_max_chunk(t_stack *general);
int			ft_compare_mid(char ch, t_stack *general, int mid);

void		ft_exec(t_stack *general);
void		ft_exec_b(t_stack *general);
void		ft_exec_a(t_stack *general);
void		ft_exec_2(t_stack *general);
void		ft_exec_3(t_stack *general);
void		ft_exec_3_a(t_stack *general);
void		ft_exec_5(t_stack *general);
void		ft_exec_5_a(t_stack *general);
void		ft_exec_long(char ch, t_stack *general);

void		ft_exit(t_stack general);
int			ft_return_error(void);
void		ft_add_operation_print(char *string, t_stack *general);
void		ft_print_print(t_stack general);

void		ft_operation_s(char ch, t_stack *general);
void		ft_operation_p(char ch, t_stack *general, int chunk);
int			ft_operation_r(char ch, t_stack *general);
int			ft_operation_rr(char ch, t_stack *general);

int			ft_max(t_value *stack);
int			ft_min(t_value *stack);
int			ft_mid(t_value *stack);
int			ft_mid_ch(char ch, t_stack *general);

int			ft_optimiz(t_stack *general);

void		ft_s_s(t_stack *general);
void		ft_r_r(t_stack *general);
void		ft_r_r_r(t_stack *general);

void		print_stack(t_stack general);
#endif
