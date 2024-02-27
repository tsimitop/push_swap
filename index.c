/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:51:07 by tsimitop          #+#    #+#             */
/*   Updated: 2024/02/27 16:51:09 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	stack_length(t_stack *stack)
{
	t_node	*iterate;
	int		i;

	i = 0;
	iterate = stack->head;
	while (iterate != NULL)
	{
		iterate = iterate->next;
		i++;
	}
	return (i);
}

t_node	*last_node(t_stack *stack_A)
{
	t_node	*last;

	last = stack_A->head;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

t_node	*find_biggest_b(t_stack *stack_B)
{
	t_node	*biggest;
	t_node	*iterate;
	int		value;

	biggest = stack_B->head;
	iterate = stack_B->head;
	value = stack_B->head->index;
	while (iterate != NULL)
	{
		if (value < iterate->index)
		{
			value = iterate->index;
			biggest = iterate;
		}
		iterate = iterate->next;
	}
	return (biggest);
}

// t_node	*find_smallest(t_stack *stack_A)
// {
// 	t_node		*smallest;
// 	t_node		*iterate;
// 	t_node		*current;
// 	int			value;
// 	current = stack_A->head;
// 	smallest = stack_A->head;
// 	iterate = stack_A->head;
// 	value = stack_A->head->nbr;
// 	while (iterate->next != NULL) //iterate->index == -1 && 
// 	{
// 		if (value > iterate->nbr)
// 		{
// 			value = iterate->nbr;
// 			smallest = iterate;
// 		}
// 		iterate = iterate->next;
// 	}
// 	smallest->index = 0;
// 	smallest->used = 1;
// 	return (smallest);
// }


// t_node	*find_biggest(t_stack *stack_A)
// {
// 	t_node			*biggest;
// 	t_node			*iterate;
// 	t_node			*current;
// 	int				value;
// 	current = stack_A->head;
// 	biggest = stack_A->head;
// 	iterate = stack_A->head;
// 	// value = 0;
// 	value = stack_A->head->nbr;
// 	while (iterate->next != NULL) //iterate->index == -1 && 
// 	{
// 		if (value < iterate->nbr)
// 		{
// 			value = iterate->nbr;
// 			biggest = iterate;
// 		}
// 		iterate = iterate->next;
// 	}
// 	return (biggest);
// }


// t_node	*find_biggest_a(t_stack *stack_A)
// {
// 	t_node			*biggest;
// 	t_node			*iterate;
// 	t_node			*current;
// 	int				value;
// 	current = stack_A->head;
// 	biggest = stack_A->head;
// 	iterate = stack_A->head;
// 	// value = 0;
// 	value = stack_A->head->nbr;
// 	while (iterate->next != NULL) //iterate->index == -1 && 
// 	{
// 		if (value < iterate->nbr)
// 		{
// 			value = iterate->nbr;
// 			biggest = iterate;
// 		}
// 		iterate = iterate->next;
// 	}
// 	biggest->index = 4294967295;
// 	biggest->used = 1;
// 	return (biggest);
// }


// int	if_used(t_stack *stack_A)
// {
// 	t_node	*iterate;
// 	int		not_used;
// 	unsigned int		length;
// printf("TEST if_used\n");
// 	not_used = 0;
// 	iterate = stack_A->head;
// printf("iterate->used _________________ %i\n", iterate->used);
// 	length = stack_length(stack_A);
// 	while (iterate->used != not_used && iterate != NULL && length > 0)
// 	{
// printf("length = %i\n", length);
// printf("iterate->used = %i\n", iterate->used);
// 		iterate = iterate->next;
// 		length--;
// 	}
// printf("iterate->used _________________ %i\n", iterate->used);
// 	if (iterate->used == not_used)
// 		return (0);
// 	else
// 		return (1);
// }

// int	if_idx_minus(t_stack *stack_A)
// {
// 	t_node			*iterate;
// 	unsigned int	minus;
// 	minus = -1;
// 	iterate = stack_A->head;
// printf("TEST idx minus\n");
// printf("iterate index head = %u\n", iterate->index);
// 	while (iterate->index != minus && iterate->next != NULL)
// 	{
// printf("iterate indexes = %u\n", iterate->index);
// 		iterate = iterate->next;
// 	}
// printf("iterate minus = %u\n", iterate->index);
// 	if (iterate->index == minus)
// 		return (-1);
// 	else
// 		return (0);
// }

