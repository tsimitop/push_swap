#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// # include "/workspaces/PUSH/Libft/libft.h"
// # include "/Users/tsimitop/Documents/Testing/PUSH/Libft/libft.h"
# include "libft.h"
#include <stdio.h>

/*struct nodes*/
typedef struct	t_node
{
	// char			*init_inp;
	int				nbr;
	int				index;
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
t_stack	*make_index_string(t_stack *A_stack, char **argv);
t_stack	*make_index_string_above_3(t_stack *stack_A, int argc, char **argv);
t_stack	*initialise_stack(t_stack *stack, char *argv_split);
char	space(char *str);
int		check_int(char *str);
int		check_dup(char **argv_split);
int		check_limits(char *str);
void	*free_split(char **str, int i);


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

// t_node			*find_smallest(t_stack *stack_A);
// t_node			*find_biggest_a(t_stack *stack_A);
// int				if_used(t_stack *stack_A);
// int				if_idx_minus(t_stack *stack_A);
unsigned int	stack_length(t_stack *stack);
t_node			*last_node(t_stack *stack_A);
// t_node			*first_half(t_node *smallest, t_stack *stack_A);
// t_node			*second_half(t_node *smallest);
// t_node			*compare_small(t_node *small_first, t_node *small_second);
// t_stack			*assign_idx(t_stack *stack_A);
// void	*assure_idx_values(t_node *smallest, int i);
// t_node	*first_used_zero(t_stack *stack);
// t_stack		 *assign_idx_try(t_stack *stack_A);
// t_node	*find_biggest(t_stack *stack_A);
// void	stack_copy(t_stack *stack_A, int argc);
// void	cp_top(t_stack *stack_A, t_stack *stack_B);
// t_node	*handle_used(t_stack *stack_A, t_node *iterate);
// void	bring_up(t_stack *stack_B);

void	set_index(t_stack *stack_A);
void	array_to_index(int *arr_sort, t_stack *stack_A, int	length);
int	*copy_array(t_stack *stack_A, int argc);
int	*sort_array(int *array, int argc);
void	swap(int *a, int *b);
int	*bubble_sort(int *sorted_array, int argc);
void	print_array(int *array, char* str);



/*sorting*/

t_node	*find_biggest_b(t_stack *stack_B);
int		square_root(int number);
int	calculate_up(t_stack *stack_B, t_node *b_biggest);
int	calculate_down(t_node *b_biggest);
void	move_down(t_stack *stack_B, t_node *b_biggest);
void	move_up(t_stack *stack_B, t_node *b_biggest);
void	push_biggest_to_a(t_stack *stack_A, t_stack *stack_B);
void	k_sort(t_stack *stack_A, t_stack *stack_B);
void	sort_3(t_stack *stack_A);


/*extras*/
void check_node(t_stack *stack_A);
void	check_stack(t_stack *stack);



#endif
