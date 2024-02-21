#include "push_swap.h"

//turns tabs of argv into spaces
char	space(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\t')
			str[i] = ' ';
		i++;
	}
	return (*str);
}

//checks if string is an int
int	check_int(char *str)
{
	int	i;
	int	ret_val;

	i = 0;
	ret_val = -1;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			ret_val = 0;
		else
			ret_val = 1;
		i++;
	}
	return (ret_val);
}

//if duplicates -1 else 0
int	check_dup(char **argv_split)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv_split[i] != NULL)
	{
		// i = ft_atoi(argv_split[i]);
		j = i + 1;
		while (argv_split[j] != NULL)
		{
			if (ft_strncmp(argv_split[j], argv_split[i], 12) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

////////////////////////////////////////////////////////////////////////////////
////								DEBUG									////
////////////////////////////////////////////////////////////////////////////////

void	check_stack(t_stack *stack)
{
	t_node	*iterate;

	iterate = stack->head;
	while (iterate != NULL)
	{
		printf("stack->node = %p\n", iterate);
		printf("stack->node->index = %i\n", iterate->index);
		printf("stack->node->nbr = %i\n", iterate->nbr);
		printf("stack->node->next = %p\n", iterate->next);
		printf("stack->node->prev = %p\n", iterate->prev);
		iterate = iterate->next;
	}
}

void check_node(t_stack *stack_A)
{
	t_node *check = stack_A->head;
	while (check != NULL)
	{
printf("\ncheck->nbr = %i\ncheck->index = %i\ncheck->used = %i\n", check->nbr, check->index, check->used);
	check = check->next;
	}
}
