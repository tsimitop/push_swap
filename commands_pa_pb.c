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
	int len = stack_length(stack_B);

// printf("STACK A\n");
// check_stack(stack_A);
// printf("STACK B\n");
// check_stack(stack_B);
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
	if (len == 1)		// without this B_stack ramains full after last pa...
		stack_B->head = NULL;
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
	t_node	*last;
	int		len;


	len = stack_length(stack_A);
	if (!stack_A->head)
	{
printf("STACK A is empty!!");
		return ;
	}
// printf("stack_B->head = %p\n", stack_B->head);
// printf("stack_B->head->next->nbr = %i\n, stack_B->head->next->next = %p\n, stack_B->head->next->prev = %p\n", stack_B->head->next->nbr, stack_B->head->next->next, stack_B->head->next->prev);
	move = stack_A->head;
	if (stack_A->head && stack_A->head->next)
		stack_A->head = stack_A->head->next;
	if (stack_A->head != NULL)
		stack_A->head->prev = NULL;
	// move->next->prev = NULL;
	move->next = stack_B->head;
	move->prev = NULL;
	if (stack_B->head != NULL)
	{
		stack_B->head->prev = move;
	}
	stack_B->head = move;
	// stack_B->head->prev = NULL;
	last = last_node(stack_B);
	last->next = NULL;
// printf("TEST\n");
// check_stack(stack_B);
	if (len == 1)
		stack_A->head = NULL;
	write(1, "pb\n", 3);
}
