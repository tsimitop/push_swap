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
	while (str[i] != '\0' && ret_val != 1)
	{
		if (str[i] >= '0' && str[i] <= '9')
			ret_val = 0;
		else
			ret_val = 1;
		i++;
	}
	if (ret_val == 1)
		write (1, "Error: not all arguments are ints.\n", 35); //segfault
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
			{
				write (1, "Error: there are duplicated arguments.\n", 39);
				return (-1);		//SEGFAULT GIA DIPLES A3IES
			}
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
	printf("stack->head = %p\n", iterate);
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

int	check_limits(char *str)
{
	int	len;
	len = ft_strlen(str);
	// printf("len = %zu\n", ft_strlen(str));

	if (len > 10)
	{
		if (check_int(str) == 0)
		{
			if (str[0] == '-')
			{
				if (ft_strlen(str) > 11 || ft_strncmp(str, "-2147483648", 10) > 0)
				{
					write (1, "Error: not within int limits\n", 1);
					return (1);
				}
				// else if (ft_strncmp(str, "-2147483648", 10) > 0)
				// 	write (1, "Error: not within int limits\n", 29);
			}
			else if (ft_strlen(str) > 10 || ft_strncmp(str, "2147483648", 10) > 0)
			{
				// if (ft_strlen(str) > 10)
				// 	write (1, "Error: not within int limits\n", 1);
				// else if (ft_strncmp(str, "2147483648", 10) > 0)
					write (1, "Error: not within int limits\n", 29);
					return (1);
			}
		}
	}
	// printf("LIMITS???\n");
	return (0);
}


void	*free_split(char **str, int i)
{
	while (i - 1 > 0)
	{
		free(str[i]);		// fix it
		i--;
	}
	return (0);
}
