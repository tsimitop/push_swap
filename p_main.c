#include "push_swap.h"

// char	*new_atoi(const char *str);

int main(int argc, char **argv)
{
	char **argv_split;
	t_stack *A_stack = NULL;
	t_stack *B_stack = NULL;
	// t_node	*new = NULL;

	A_stack->head = NULL; //(t_node *)ft_calloc(argc + 1, sizeof(t_node));
	B_stack->head = NULL; //(t_node *)ft_calloc(argc + 1, sizeof(t_node));
	if (argc == 2)
	{
		int i = 0;
		// int digit;

		*argv[1] = space(argv[1]);
		argv_split = ft_split(argv[1], ' ');
		while (argv_split[i])
		{
			if (check_int(argv_split[i]) == 0 && check_dup(argv_split) == 0)
			{
				A_stack = initialise_stack(A_stack, *argv_split);
				// digit = ft_atoi(argv_split[i]);
				// new = (t_node *)ft_calloc(1, sizeof(t_node));
				// if (!new)
				// 	return (0);
				// new->nbr = digit;
				// new->index = -1;
				// new->used = 0;
				// new->next = NULL;
				// new->prev = NULL;
				// if (A_stack->head == NULL)
				// 	A_stack->head = new;
				// else
				// {
				// 	new->next = A_stack->head;
				// 	A_stack->head->prev = new;
				// 	A_stack->head = new;
				// }
				// i++;
			}
			else
				exit (-1);
			// set indexes
		}
		free(argv_split);
	}
	return (0);
}

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
