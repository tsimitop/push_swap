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
	unsigned int	index;
	int				used;
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
t_stack	*initialise_stack(t_stack *stack, char argv_split);
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


/*index*/

t_node			*find_smallest(t_stack *stack_A);
t_node			*find_biggest(t_stack *stack_A);
int				if_idx_minus(t_stack *stack_A);
unsigned int	stack_length(t_stack *stack);
t_node			*last_node(t_stack *stack_A);
t_node			*first_half(t_node *smallest, t_stack *stack_A);
t_node			*second_half(t_node *smallest);
t_node			*compare_small(t_node *small_first, t_node *small_second);
t_stack			*assign_idx(t_stack *stack_A, t_node *small);

#endif
