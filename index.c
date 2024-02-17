#include "push_swap.h"

t_node	*find_smallest(t_stack *stack_A)
{
	t_node		*smallest;
	t_node		*iterate;
	t_node		*current;
	int			value;

	current = stack_A->head;
	smallest = stack_A->head;
	iterate = stack_A->head;
	value = stack_A->head->nbr;
	while (iterate->next != NULL) //iterate->index == -1 && 
	{
		if (value > iterate->nbr)
		{
			value = iterate->nbr;
			smallest = iterate;
		}
		iterate = iterate->next;
	}
	smallest->index = 0;
	smallest->used = 1;
	return (smallest);
}

t_node	*find_biggest_a(t_stack *stack_A)
{
	t_node			*biggest;
	t_node			*iterate;
	t_node			*current;
	int				value;

	current = stack_A->head;
	biggest = stack_A->head;
	iterate = stack_A->head;
	// value = 0;
	value = stack_A->head->nbr;
	while (iterate->next != NULL) //iterate->index == -1 && 
	{
		if (value < iterate->nbr)
		{
			value = iterate->nbr;
			biggest = iterate;
		}
		iterate = iterate->next;
	}
	biggest->index = 4294967295;
	biggest->used = 1;
	return (biggest);
}

t_node	*find_biggest_b(t_stack *stack_B)
{
	t_node			*biggest;
	t_node			*iterate;
	t_node			*current;
	int				value;

	current = stack_B->head;
	biggest = stack_B->head;
	iterate = stack_B->head;
	// value = 0;
	value = stack_B->head->nbr;
	while (iterate->next != NULL) //iterate->index == -1 && 
	{
		if (value < iterate->nbr)
		{
			value = iterate->nbr;
			biggest = iterate;
		}
		iterate = iterate->next;
	}
	biggest->index = 4294967295;
	biggest->used = 1;
	return (biggest);
}

int	if_used(t_stack *stack_A)
{
	t_node	*iterate;
	int		not_used;
	unsigned int		length;
printf("TEST MORE not_used\n");
	not_used = 0;
	iterate = stack_A->head;
printf("iterate->used _________________ %i\n", iterate->used);
	length = stack_length(stack_A);
	while (iterate->used != not_used && iterate != NULL && length > 0)
	{
printf("length = %i\n", length);
printf("iterate->used = %i\n", iterate->used);
		iterate = iterate->next;
		length--;
	}
printf("iterate->used _________________ %i\n", iterate->used);
	if (iterate->used == not_used)
		return (0);
	else
		return (1);
}

int	if_idx_minus(t_stack *stack_A)
{
	t_node			*iterate;
	unsigned int	minus;
	minus = -1;
	iterate = stack_A->head;
printf("TEST MORE minus\n");
	while (iterate->index != minus && iterate->next != NULL)
		iterate = iterate->next;
	if (iterate->index == minus)
		return (-1);
	else
		return (0);
}

unsigned int	stack_length(t_stack *stack)
{
	t_node			*iterate;
	unsigned int	ui;
	t_node			*debugg = stack->head;
	ui = 0;
	iterate = stack->head;
	while (iterate != NULL)
	{
printf("\t\tCURRENT NODE nbr value = %i\n", debugg->nbr);
		iterate = iterate->next;
		ui++;
		debugg = debugg->next;
	}
	return (ui);
}

/*
________________________________________________________________________________
________________________________________________________________________________
*/
// t_stack	*assign_idx(t_stack *stack_A)
// {
// 	t_node	*iterate;
// 	t_node	*smallest;
// 	t_node	*restart;
// 	t_node	*hold_small;
// 	int		i;
// 	int value;

// 	i = 0;
// 	value = if_idx_minus(stack_A);
// 	while (value == -1)
// 	{
// 		check_node(stack_A);
// 		iterate = stack_A->head;
// 		smallest = stack_A->head;
// 		restart = stack_A->head;
// 		while (restart != NULL)
// 		{
// 			if (iterate->used == 0)
// 			{
// 				hold_small = iterate;
// 				// handle_used(stack_A, iterate);
// 				if (iterate->nbr < hold_small->nbr)
// 					smallest = iterate;
// 			}
// 			iterate = iterate->next;
// 			restart = restart->next;
// 		}
// 		if (smallest->index == (unsigned int)-1)
// 			smallest->index = i;
// 		if (smallest->used == 0)
// 			smallest->used = 1;
// 		i++;
// 	value = if_idx_minus(stack_A);
// printf("VALUE = %i", value);
// printf("_______________________________smallest->index = %i\n", smallest->index);
// printf("HHHHHHHHHEEEEEEEEEEEEEYYYYYYYYYYYYYYY\n");
// 	}
// 	return (stack_A);
// }

t_stack		 *assign_idx(t_stack *stack_A)
{
	t_node		*iterate;
	t_node		*smallest;
	int			i;

	i = 0;
	while (if_idx_minus(stack_A) == -1)
	{
		iterate = stack_A->head;
		smallest = stack_A->head;
		while (iterate != NULL)
		{
			if (iterate->nbr < smallest->nbr && iterate->used == 0)
				smallest = iterate;
			iterate = iterate->next;
		}
		assure_idx_values(smallest, i);
		i++;
	}
	return (stack_A);
}

void	*assure_idx_values(t_node *smallest, int i)
{
	if (smallest->index == (unsigned int)-1)
		smallest->index = i;
	if (smallest->used == 0)
		smallest->used = 1;
	return (0);
}

// t_node	*handle_used(t_stack *stack_A, t_node *iterate)
// {
// 	t_node *check_used;
// 	t_node *keep;

// 	check_used = iterate;
// 	keep = iterate;
// 	while (check_used != NULL)
// 	{
// 		if (if_used(stack_A) == 0)
// 		{
// 			if (keep->nbr > check_used->nbr)
// 				keep = check_used;
// 		}
// 		check_used = check_used->next;
// 	}
// 	return (keep);
// }

void check_node(t_stack *stack_A)
{
	t_node *check = stack_A->head;
	while (check != NULL)
	{
printf("\ncheck->nbr = %i\ncheck->index = %i\ncheck->used = %i\n", check->nbr, check->index, check->used);
	check = check->next;
	}
}

// t_node	*last_node(t_stack *stack_A)
// {
// 	t_node	*last;

// 	last = stack_A->head;
// 	while (last->next != NULL)
// 		last = last->next;
// 	return (last);
// }

// t_node	*first_half(t_node *smallest, t_stack *stack_A)
// {
// 	t_node	*iterate;
// 	t_node	*new_small;

// 	iterate = stack_A->head;
// 	new_small = stack_A->head;
// 	while (iterate != smallest)
// 	{
// 		if ((iterate->nbr < new_small->nbr) && (iterate->used == 0))
// 		{
// 			new_small = iterate;
// 			new_small->used = 1;
// 		}
// 		iterate = iterate->next;
// 	}
// 	return (new_small);
// }

// t_node	*second_half(t_node *smallest)
// {
// 	t_node	*iterate;
// 	t_node	*new_small;

// 	iterate = smallest->next;
// 	new_small = smallest->next;
// 	while (iterate != NULL)
// 	{
// 		if ((iterate->nbr <= new_small->nbr) && (iterate->used == 0))
// 		{
// 			new_small = iterate;
// 			new_small->used = 1;
// 		}
// 		iterate = iterate->next;
// 	}
// 	return (new_small);
// }

// t_node	*compare_small(t_node *small_first, t_node *small_second)
// {
// 	t_node	*new_small;

// 	if (small_first->nbr > small_second->nbr)
// 	{
// 		new_small = small_second;
// 		small_first->used = 0;
// 	}
// 	else
// 	{
// 		new_small = small_first;
// 		small_second->used = 0;
// 	}
// 	return (new_small);
// }

// // give the smallest value to the t_node
// // t_stack	*assign_idx(t_stack *stack_A, t_node *small) //, t_node *call_assign(t_node *small)
// // {
// // 	unsigned int	ui;
// // 	t_node *small_first;
// // 	t_node *small_second;
// // 	int		minus;
// // printf("TEST MORE assign\n");
// // 	small_first = first_half(small, stack_A);
// // 	small_second = second_half(small);
// // 	ui = stack_length(stack_A);
// // 	small = compare_small(small_first, small_second);
// // 	minus = if_idx_minus(stack_A);
// // printf("minus = %i\n", minus);
// // 	if (minus == -1)
// // 		assign_idx(stack_A, small);
// // 	return (stack_A);
// // }

// t_stack	*assign_idx(t_stack *stack_A, t_node *small, t_node *biggest) //, t_node *call_assign(t_node *small)
// {
// 	// unsigned int	ui;
// 	t_node *small_first;
// 	t_node *small_second;
// 	int		used;
// printf("TEST MORE ASSIGN ASSIGN ASSIGN ASSIGN\n");
// // printf("first small->used = %i\n", small->used);

// 	small_first = first_half(small, stack_A);
// printf("small_first_half->used = %i\n", small_first->used);
// 	small_second = second_half(small);
// printf("small_second_half->used = %i\n", small_second->used);
// 	// ui = stack_length(stack_A);
// 	small = compare_small(small_first, small_second);
// 	if (small == biggest)
// 		return (stack_A);
// printf("small_last->used = %i\n", small->used);
// 	used = if_used(stack_A);
// printf("used = %i\n", used);
// 	if (used == 0)
// 		assign_idx(stack_A, small, biggest);
// 	return (stack_A);
// }

// 	}