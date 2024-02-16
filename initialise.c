#include "push_swap.h"


t_stack	*initialise_stack(t_stack *stack, char *argv_split)
{
	// t_stack	*stack;
	t_node	*new;
	int		digit;

	digit = ft_atoi(argv_split);
	new = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!new)
		return (0);
	new->nbr = digit;
printf("argv_split = %i\n", new->nbr);
	new->index = -1;
	new->used = 0;
	new->next = NULL;
	new->prev = NULL;
	if (stack->head == NULL)
		stack->head = new;
	else
	{
		new->next = stack->head;
		stack->head->prev = new;
		stack->head = new;
	}
	return(stack);
}

