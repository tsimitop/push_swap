#include "push_swap.h"

void	set_index(t_stack *stack_A)
{
	int	length;
	int	*copied_array;
	int	*sorted_array;

	length = stack_length(stack_A);
	copied_array = copy_array(stack_A, length);
	sorted_array = sort_array(copied_array, length);
	array_to_index(sorted_array, stack_A, length);
	// check_node(stack_A);
}

void	array_to_index(int *arr_sort, t_stack *stack_A, int	length)
{
	t_node	*iterate;
	int		i;
	int		init_length;

	iterate = stack_A->head;
	init_length = length;
	while (iterate != NULL)
	{
		i = 0;
		length = init_length;
		while (arr_sort[i] != iterate->nbr && iterate != NULL && length > 0) //remove length
		{
			i++;
			length--;
		}
// printf("\t\t\ti = %i\n\t\t\tarr_sort[i] = %i\n\t\t\titerate->nbr = %i\n", i, arr_sort[i], iterate->nbr);
		if (arr_sort[i] == iterate->nbr)
		{
			iterate->index = i;
			iterate->used = 1;
		}
		iterate = iterate->next;
	}
}

int	*copy_array(t_stack *stack_A, int length)
{
	t_node	*iterate;
	// int i;
	int	*array;

	// i = 0;
	array = ft_calloc(length + 1, sizeof(int));				//FREE!!!
	if (!array)
		return (NULL);
	iterate = stack_A->head;
	while (iterate != NULL)
	{
		array[length - 1] = iterate->nbr;
		iterate = iterate->next;
		length--;
	}
	return (array);
}

int	*sort_array(int *array, int length)
{
	int *sorted_array;
	// char* str = "simple_array";
	int		mem_length;

	mem_length = length;
// printf("simple_array\n_____\n %i  %i \n_____\n", array[0], array[1]);
// print_array(array, str);

	sorted_array = ft_calloc(length + 1, sizeof(int));		//FREE!!!
	if (sorted_array == NULL)
		return (NULL);
	while (0 <= length - 1)
	{
		sorted_array[length-1] = array[length-1];
		length--;
	}
	sorted_array = bubble_sort(sorted_array, mem_length);
	free(array);
	return (sorted_array);
}

void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	*bubble_sort(int *sorted_array, int length)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < length - 1)
	{
		j = 0;
		while (j < length - 1)
		{
			if (sorted_array[j] > sorted_array [j + 1])
			{
				swap(&sorted_array[j], &sorted_array[j + 1]);
			}
			j++;
		}
		i++;
	}
// char *str = "sorted array";
// printf("HELLOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
// print_array(sorted_array, str);
// printf("\nsorted_array[0] = %i\n", sorted_array[0]);
// printf("sorted_array[1] = %i\n", sorted_array[1]);
// printf("sorted_array[2] = %i\n", sorted_array[2]);
// printf("sorted_array[3] = %i\n", sorted_array[3]);

	return (sorted_array);
}


void	print_array(int *array, char* str) //DELETE FUNCTION
{
	int i = 0;

	while (array[i] != 0)
	{
		printf("%s = %i\t", str, array[i]);
		i++;
	}
}
