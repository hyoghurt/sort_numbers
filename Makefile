NAME			= push_swap
SRC				= main.c ft_add.c ft_gnl.c ft_check.c ft_value.c ft_operation.c ft_exec.c ft_exec_2.c ft_exec_add.c ft_exec_little.c ft_exit.c ft_mid.c ft_exec_operation.c ft_print.c ft_optimiz.c proverka.c
SRC_B			= main_bonus.c ft_checker_bonus.c ft_add.c ft_gnl.c ft_check.c ft_value.c ft_operation.c ft_exec.c ft_exec_2.c ft_exec_add.c ft_exec_little.c ft_exit.c ft_mid.c ft_exec_operation.c ft_print.c ft_optimiz.c
SRCDIR			= src
OBJDIR			= obj
OBJ				= $(addprefix $(OBJDIR)/,$(notdir $(SRC:.c=.o)))
OBJ_B			= $(addprefix $(OBJDIR)/,$(notdir $(SRC_B:.c=.o)))
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

$(NAME):		$(OBJ)
				make -C libft
				$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -o $(NAME) 

bonus:			$(OBJ_B)
				make -C libft
				$(CC) $(CFLAGS) $(OBJ_B) -Llibft -lft -o checker

$(OBJDIR):			
				mkdir -p $@

$(OBJDIR)/%.o:	$(SRCDIR)/%.c | $(OBJDIR)
				$(CC) -I. -Ilibft -c -MD $< -o $@

include $(wildcard $(OBJDIR)/*.d)

all:			$(NAME)

clean:	
				rm -rf $(OBJDIR)
				make clean -C libft

fclean:			clean
				rm -rf $(NAME)
				rm -rf checker
				make fclean -C libft

re:				fclean all
				make re -C libft

.PHONY:			all clean fclean re
