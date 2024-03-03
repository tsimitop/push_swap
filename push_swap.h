#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// # include "/workspaces/PUSH/Libft/libft.h"
// # include "/Users/tsimitop/Documents/Testing/PUSH/Libft/libft.h"
# include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
// t_stack	*initialize_without_quotes(t_stack *stack_A, int argc, char **argv);
t_stack	*initialise_stack(t_stack *stack, char *argv_split);
char	space(char *str);
// int		check_int(char *str);
int		check_int(char *str, char **argv_split);
int		check_dup(char **argv_split);
int		check_limits(char *str);


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


/*free*/
// void	del_content(int *content);
// void	free_stack(t_stack *stack, void (*del)(void*));
// void	free_stack2(t_stack *stack);
void	free_stack(t_stack *stack);
void	free_split(char **str);
void	ft_exit(char *msg, int exit_value, char **argv_split);


/*extras*/
void	check_node(t_stack *stack_A);
void	check_stack(t_stack *stack);

/*new*/
void	ft_check_if_int(char *str, char **argv_split);
void	check_if_dup(char **argv_split);
void	ft_check_limits(char *str, char **argv_split);
void	ft_parse_input(char **argv);
void	check_leaks(void);
t_stack	*ft_initialize_stackA(t_stack *stack_A, char **argv);
char	**ft_parse_input_without_quotes(char **argv, int argc); //it starts with the argv[0]
t_stack	*ft_initialize_stackA_without_quotes(t_stack *stack_A, char **argv);





t_stack	*make_index_string_above_3(t_stack *stack_A, int argc, char **argv);



#endif
