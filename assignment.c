/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:50:30 by tsimitop          #+#    #+#             */
/*   Updated: 2024/03/02 15:44:17 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *stack_A)
{
	int	length;
	int	*copied_array;
	int	*sorted_array;

	length = stack_length(stack_A);
	copied_array = copy_array(stack_A, length);
	if (!copied_array)
		return ;
	sorted_array = sort_array(copied_array, length);
	if (!sorted_array)
		return ;
	array_to_index(sorted_array, stack_A, length);
	free(sorted_array);
	free(copied_array);
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
	int	*array;

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
	int		mem_length;

	mem_length = length;
	sorted_array = ft_calloc(length + 1, sizeof(int));		//FREE!!!
	if (sorted_array == NULL)
		return (NULL);
	while (0 <= length - 1)
	{
		sorted_array[length-1] = array[length-1];
		length--;
	}
	sorted_array = bubble_sort(sorted_array, mem_length);

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
