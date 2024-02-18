#include "push_swap.h"

int	calculate_up(t_stack *stack_B, t_node *b_biggest)
{
	int	moves_up;
	t_node	*iterate;

	moves_up = 0;
	iterate = b_biggest;
	while (iterate != stack_B->head)
	{
		iterate = iterate->prev;
		moves_up++;
	}
	return (moves_up);
}

int	calculate_down(t_node *b_biggest)
{
	int	moves_down;
	t_node	*iterate;

	moves_down = 0;
	iterate = b_biggest;
	while (iterate != NULL)
	{
		iterate = iterate->next;
		moves_down++;
	}
	moves_down++;
	return (moves_down);
}

void	move_down(t_stack *stack_B, t_node *b_biggest)
{
	while (b_biggest->next != NULL)
		rrb(stack_B);
	rrb(stack_B);
}

void	move_up(t_stack *stack_B, t_node *b_biggest)
{
	while (b_biggest->prev != NULL)
		rb(stack_B);
}

void	push_biggest_to_a(t_stack *stack_A, t_stack *stack_B)
{
	t_node	*biggest;
	int		down;
	int		up;

	while (stack_length(stack_B) != 0)
	{
		biggest = find_biggest_b(stack_B);
		up = calculate_up(stack_B, biggest);
		down = calculate_down(biggest);
		if (up >= down)
			move_down(stack_B, biggest);
		else
			move_up(stack_B, biggest);
	}
	pa(stack_A, stack_B);
}

void	k_sort(t_stack *stack_A, t_stack *stack_B)
{
	int				formula;
	unsigned int	id;
	t_node			*iterate;

	id = 0;
	formula = ((int)square_root(stack_length(stack_A)) * 14 / 10);
	iterate = stack_A->head;
	while (iterate != NULL)
	{
		if (iterate->index <= id)
		{
			pb(stack_A, stack_B);
			rb(stack_B);
			id++;
		}
		else if (iterate->index <= id + formula)
		{
			pb(stack_A, stack_B);
			id++;
		}
		else
			ra(stack_A);
		iterate = (stack_A->head);
	}
	push_biggest_to_a(stack_A, stack_B); //other function;
}
