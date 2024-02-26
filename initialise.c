#include "push_swap.h"


t_stack	*initialise_stack(t_stack *stack, char *argv_split)
{
	t_node	*iterate;
	t_node	*new;
	int		digit;
// printf("_______________INIT STACK____________\n");

	iterate = stack->head;
	digit = ft_atoi(argv_split);
	new = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!new)
		return (0);
	new->nbr = digit;
	new->index = -1;
	new->used = 0;
	new->next = NULL;
	new->prev = NULL;
	if (stack->head == NULL)
		stack->head = new;
	else
	{
		while (iterate->next != NULL)
			iterate = iterate->next;
		iterate->next = new;
		new->prev = iterate;
	}
	return(stack);
}

