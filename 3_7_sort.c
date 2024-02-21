#include "push_swap.h"

void	sort_3(t_stack *stack_A)
{
	t_node	*node;

	node = stack_A->head;
	if (node->index == 0 && node->next->index == 1)
		return ;
	else if (node->index == 0 && node->next->index == 2)
	{
		rra(stack_A);
		sa(stack_A);
	}
	else if (node->index == 1 && node->next->index == 0)
		sa(stack_A);
	else if (node->index == 1 && node->next->index == 2)
		rra(stack_A);
	else if (node->index == 2 && node->next->index == 1)
	{
		sa(stack_A);
		rra(stack_A);
	}
	else if (node->index == 2 && node->next->index == 0)
		ra(stack_A);
}
