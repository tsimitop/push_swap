#include "push_swap.h"

////////////////////////////////////////////////////////////////////////////////
////								STACK_A									////
////////////////////////////////////////////////////////////////////////////////

/*
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
*/
void	ra(t_stack *stack_A)
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
	// temp->prev = NULL;
	temp->next = stack_A->head;
	// stack_A->head = stack_A->head->next;
	stack_A->head->prev = temp; //if (stack_A->head != NULL)
	stack_A->head = temp;
    write(1, "ra\n", 3);
}

////////////////////////////////////////////////////////////////////////////////
////								STACK_B									////
////////////////////////////////////////////////////////////////////////////////


/*
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
*/
void	rb(t_stack *stack_B)
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
	// temp->prev = NULL;
	temp->next = stack_B->head;
	// stack_A->head = stack_A->head->next;
	stack_B->head->prev = temp; //if (stack_A->head != NULL)
	stack_B->head = temp;
    write(1, "rb\n", 3);
}

////////////////////////////////////////////////////////////////////////////////
////							BOTH STACKS									////
////////////////////////////////////////////////////////////////////////////////

/*
rr : ra and rb at the same time.
*/
void	rr(t_stack *stack_A, t_stack *stack_B)
{
	ra(stack_A);
	rb(stack_B);
	write(1, "rr\n", 3);
}
