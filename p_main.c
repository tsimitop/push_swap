#include "push_swap.h"

char	*new_atoi(const char *str);

int main(int argc, char **argv)
{
	char **argv_split;
	// char **new_split;
	t_stack A_stack;
	t_stack B_stack;
	// t_node	*temp = (t_node *)ft_calloc(1, sizeof(t_node));
	t_node	*new = NULL;

	A_stack.head = NULL; //(t_node *)ft_calloc(argc + 1, sizeof(t_node));
	// A_stack.size = 0;
	B_stack.head = NULL; //(t_node *)ft_calloc(argc + 1, sizeof(t_node));
	// B_stack.size = 0;
	if (argc == 2)
	{
		int i = 0;
		int digit;

		*argv[1] = space(argv[1]);
		argv_split = ft_split(argv[1], ' ');
		while (argv_split[i])
		{
			// if (*argv_split == ' ') //check if int
			// 	i++;
			// na ftiaxno kainourio node ado kathe fora anti gia malloc argc+1 pio prin?
			if (check_int(argv_split[i]) == 0 && check_dup(argv_split) == 0)
			{
				digit = ft_atoi(argv_split[i]);
				new = (t_node *)ft_calloc(1, sizeof(t_node));
				new->nbr = digit;
				new->index = -1;
				new->next = NULL;
				new->prev = NULL;
				if (A_stack.head == NULL)
					A_stack.head = new;
				else
				{
					new->next = A_stack.head;
					A_stack.head->prev = new;
					A_stack.head = new;
				}
				// new_split = new_atoi(argv_split[i]);
				i++;
				// A_stack.size = i;
			}
			else
				exit (-1);
			// set indexes
		}
		free(argv_split);
		// free(temp);
	}
	return (0);
}

/*
checks which nbr is smallest, gives it index 0, then gradually assigns the next
index to the next largest nbr until all indeces are assigned a non -1 value
*/
// t_stack	*index_assign(t_stack *stack_A)
// {
// 	t_node		*smallest;
// 	t_node		*iterate;
// 	t_node		*len;
// 	t_node		*current;
// 	int			value;
// 	int			stack_length;
// 	static int	gradual;


// 	stack_length = 0;
// 	gradual = 0;
// 	len = stack_A->head;
// 	current = stack_A->head;
// 	smallest = stack_A->head;
// 	iterate = stack_A->head;
// 	value = stack_A->head->nbr;
// 	while (len->next != NULL)
// 	{
// 		len=len->next;
// 		stack_length++;
// 	}
// 	while (iterate->next != NULL) //iterate->index == -1 && 
// 	{
// 		if (value > iterate->nbr)
// 		{
// 			value = iterate->nbr;
// 			smallest = iterate;
// 		}
// 		iterate = iterate->next;
// 	}
// 	smallest->index = gradual;
// 	gradual++;
// 	while (stack_length-- > 0)
// 	{
// 		index_assign(stack_A);
// 	}
// 	// while (current != NULL)
// 	// {
// 	// 	if (current->index)
// 	// }
// 	return (stack_A);
// }

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
	return (smallest);
}

t_node	*find_biggest(t_stack *stack_A)
{
	t_node			*biggest;
	t_node			*iterate;
	t_node			*current;
	unsigned int	value;

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
	t_node	*iterate;

	iterate = stack_A->head;
	while (iterate->index != -1 && iterate->next != NULL)
		iterate = iterate->next;
	if (iterate->index == -1)
		return (-1);
	else
		return (0);
}

unsigned int	stack_length(t_stack *stack_A)
{
	t_node			*iterate;
	unsigned int	ui;

	ui = 0;
	iterate = stack_A->head;
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

t_stack	*assign_idx(t_stack *stack_A) //, t_node *call_assign(t_node *small)
{
	// t_node			*biggest;
	static t_node	*smallest;
	t_node			*current;
	unsigned int	ui;
	t_node			*first_small;
	t_node			*second_small;
	// unsigned int	decrease;

	first_small = stack_A->head;
	second_small = last_node(stack_A);
	ui = stack_length(stack_A);
	// biggest = find_biggest(stack_A);
	current = find_biggest(stack_A);
	smallest = find_smallest(stack_A);
	while (ui-- > 0 && smallest->nbr < current->nbr)
	{
		//if (current->nbr > current->next->nbr) //TODO
		current = current->next;				//TODO
	}
	if (if_idx_minus(stack_A) == -1)
		assign_idx(stack_A);
	return (stack_A);
}

// t_node	*call_assign(t_node *small)
// {
// 	return (small);
// }

