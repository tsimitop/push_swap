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

t_node	*find_biggest(t_stack *stack_A)
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
	return (biggest);
}

int	if_idx_minus(t_stack *stack_A)
{
	t_node			*iterate;
	unsigned int	minus;
	
	minus = -1;
	iterate = stack_A->head;
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

	ui = 0;
	iterate = stack->head;
	while (iterate->next != NULL)
	{
		iterate = iterate->next;
		ui++;
	}
	return (ui);
}

t_node	*last_node(t_stack *stack_A)
{
	t_node	*last;

	last = stack_A->head;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

// t_node	*call_assign(t_node *small)
// {
// 	return (small);
// }

t_node	*first_half(t_node *smallest, t_stack *stack_A)
{
	t_node	*iterate;
	t_node	*new_small;

	iterate = stack_A->head;
	new_small = stack_A->head;
	while (iterate != smallest)
	{
		if ((iterate->nbr < new_small->nbr) && (iterate->used == 0))
		{
			new_small = iterate;
			new_small->used = 1;
		}
		iterate = iterate->next;
	}
	return (new_small);
}

t_node	*second_half(t_node *smallest)
{
	t_node	*iterate;
	t_node	*new_small;

	iterate = smallest->next;
	new_small = smallest->next;
	while (iterate != NULL)
	{
		if ((iterate->nbr < new_small->nbr) && (iterate->used == 0))
		{
			new_small = iterate;
			new_small->used = 1;
		}
		iterate = iterate->next;
	}
	return (new_small);
}

t_node	*compare_small(t_node *small_first, t_node *small_second)
{
	t_node	*new_small;

	if (small_first->nbr > small_second->nbr)
	{
		new_small = small_second;
		small_first->used = 0;
	}
	else
	{
		new_small = small_first;
		small_second->used = 0;
	}
	return (new_small);
}

// give the smallest value to the t_node
t_stack	*assign_idx(t_stack *stack_A, t_node *small) //, t_node *call_assign(t_node *small)
{
	unsigned int	ui;
	t_node *small_first;
	t_node *small_second;

	small_first = first_half(small, stack_A);
	small_second = second_half(small);
	ui = stack_length(stack_A);
	small = compare_small(small_first, small_second);
	if (if_idx_minus(stack_A) == -1)
		assign_idx(stack_A, small);
	return (stack_A);
}
