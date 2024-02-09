#include "push_swap.h"

////////////////////////////////////////////////////////////////////////////////
////								STACK_A									////
////////////////////////////////////////////////////////////////////////////////

/*
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
*/
void	rra(t_stack *stack_A)
{
	t_node	*temp;
	t_node	*last;

	temp = stack_A->head;
	last = NULL;
	while (temp->next != NULL)
	{
		last = temp;
		temp = temp->next;
	}
	last->next = NULL;
	temp->next = stack_A->head;
	stack_A->head->prev = NULL;
	stack_A->head = temp;
    write(1, "rra\n", 4);
}

////////////////////////////////////////////////////////////////////////////////
////								STACK_B									////
////////////////////////////////////////////////////////////////////////////////


/*
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
*/
void	rrb(t_stack *stack_B)
{
	t_node	*temp;
	t_node	*last;

	temp = stack_B->head;
	last = NULL;
	while (temp->next != NULL)
	{
		last = temp;
		temp = temp->next;
	}
	last->next = NULL;
	temp->next = stack_B->head;
	stack_B->head->prev = NULL;
	stack_B->head = temp;
    write(1, "rrb\n", 4);
}

////////////////////////////////////////////////////////////////////////////////
////							BOTH STACKS									////
////////////////////////////////////////////////////////////////////////////////

/*
rrr : rra and rrb at the same time.+
*/
void	rrr(t_stack *stack_A, t_stack *stack_B)
{
	rra(stack_A);
	rrb(stack_B);
	write(1, "rrr\n", 3);
}
