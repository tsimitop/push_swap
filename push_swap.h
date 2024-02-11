#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// # include "/workspaces/PUSH/Libft/libft.h"
// # include "/Users/tsimitop/Documents/Testing/PUSH/Libft/libft.h"
# include "libft.h"

/*struct nodes*/
typedef struct	t_node
{
	// char			*init_inp;
	int				nbr;
	int				index;
	struct t_node	*next;
	struct t_node	*prev;
}				t_node;

typedef struct	t_stack
{
	t_node		*head;
	// size_t		size; //how many in the stack
}				t_stack;

/*utils*/
// void	delete_tmp(void *tmp);
// void	ft_ps_delone(t_node *lst, void (*del)(void*));
char	space(char *str);
int		check_int(char *str);
int		check_dup(char **argv_split);


/*commands*/

void	sa(t_stack *stack_Α);
void	sb(t_stack *stack_Β);
void	ss(t_stack *stack_A, t_stack *stack_B);

void	pa(t_stack *stack_A, t_stack *stack_B);
void	pb(t_stack *stack_A, t_stack *stack_B);

void	ra(t_stack *stack_A);
void	rb(t_stack *stack_B);
void	rr(t_stack *stack_A, t_stack *stack_B);

void	rra(t_stack *stack_A);
void	rrb(t_stack *stack_B);
void	rrr(t_stack *stack_A, t_stack *stack_B);

#endif
