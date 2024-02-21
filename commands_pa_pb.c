#include "push_swap.h"

////////////////////////////////////////////////////////////////////////////////
////								STACK_A									////
////////////////////////////////////////////////////////////////////////////////

/*
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
*/
void	pa(t_stack *stack_A, t_stack *stack_B)
{
	t_node	*move;

	if (!stack_B->head)
	{
		printf("B is empty...!");
		return ;
	}
	move = stack_B->head;
	if (stack_B->head && stack_B->head->next)
	{
		stack_B->head = stack_B->head->next;
		move->next->prev = NULL;
	}
	if (stack_B->head != NULL)
		stack_B->head->prev = NULL;
	
	move->next = stack_A->head;
	move->prev = NULL;
	if (stack_A->head != NULL)
		stack_A->head->prev = move;
	stack_A->head = move;
    write(1, "pa\n", 3);
}

////////////////////////////////////////////////////////////////////////////////
////								STACK_B									////
////////////////////////////////////////////////////////////////////////////////


/*
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
*/
void	pb(t_stack *stack_A, t_stack *stack_B)
{
	t_node	*move;
	if (!stack_A->head)
	{
		printf("STACK A is empty!!");
		return ;
	}
	move = stack_A->head;
	if (stack_A->head && stack_A->head->next)
		stack_A->head = stack_A->head->next;
	if (stack_A->head != NULL)
		stack_A->head->prev = NULL;
	// move->next->prev = NULL;
	move->next = stack_B->head;
	move->prev = NULL;
	if (stack_B->head != NULL)
		stack_B->head->prev = move;
	stack_B->head = move;
    write(1, "pb\n", 3);
}
