/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:51:29 by tsimitop          #+#    #+#             */
/*   Updated: 2024/02/27 19:05:53 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_up(t_stack *stack_B, t_node *b_biggest)
{
	int	moves_up;
	t_node	*iterate;
	moves_up = 0;
	iterate = b_biggest;
// printf("STACK B\n");
// check_stack(stack_B);				//PROBLEM
// int hold_len = len;
// if (len == hold_len - 5)
// printf("biggest in calc up = %i\n", b_biggest->nbr);
// printf("iterate->nbr = %i\n", iterate->nbr);

	while (iterate != stack_B->head)
	{
// printf("iterate->nbr = %i\n", iterate->nbr);
		iterate = iterate->prev;
		moves_up++;
// printf("________calc up\n");
	}
// printf("\tmoves up = % i\n", moves_up);
	// exit(-1);

	return (moves_up);
}

int	calculate_down(t_node *b_biggest)
{
	int	moves_down;
	t_node	*iterate;

	moves_down = 0;
	iterate = b_biggest;
	while (iterate != NULL)
	{
// printf("iterate->nbr = %i\n", iterate->nbr);
		iterate = iterate->next;
		moves_down++;
	}
	moves_down++;
// printf("\tmoves down = % i\n", moves_down);
	return (moves_down);
}

void	move_down(t_stack *stack_B, t_node *b_biggest)
{
	while (b_biggest->next != NULL)
		rrb(stack_B);
	rrb(stack_B);
}

void	move_up(t_stack *stack_B, t_node *b_biggest)
{
	while (b_biggest->prev != NULL)
	{
		rb(stack_B);
	}
}

void	push_biggest_to_a(t_stack *stack_A, t_stack *stack_B)
{
	t_node	*biggest;
	int		down;
	int		up;

// printf("entered push biggest to a\n");
// printf("STACK B\n");
// check_stack(stack_B);
// exit(-1);
	while (stack_length(stack_B) != 0)
	{
// printf("stack length b = %i\n", stack_length(stack_B));
		biggest = find_biggest_b(stack_B);
// printf("STACK A\n");
// check_stack(stack_A);
// printf("STACK B\n");
// check_stack(stack_B);
// printf("biggest->nbr = %i\n", biggest->nbr);
	// exit(-1);
		up = calculate_up(stack_B, biggest);
		down = calculate_down(biggest);
		if (up > down)
			move_down(stack_B, biggest);
		else if (up <= down && up != 0)
			move_up(stack_B, biggest);
		pa(stack_A, stack_B);
// printf("STACK A\n");
// check_stack(stack_A);
// printf("STACK B\n");
// check_stack(stack_B);
		// int len = stack_length(stack_B);
		// int hold_len = len;
		// if (len == hold_len - 1)
		// 	exit(-1);
		// len--;
	}
}

void	k_sort(t_stack *stack_A, t_stack *stack_B)
{
	int		formula;
	int		id;
	t_node	*iterate;

// printf("STACK A\n");
// check_stack(stack_A);
// printf("STACK B\n");
// check_stack(stack_B);
// exit(-1);
	id = 0;
	formula = ((int)square_root(stack_length(stack_A)) * 14 / 10);
// printf("formula = %i\n", formula);
	iterate = stack_A->head;
	while (iterate != NULL)
	{
		if (iterate->index <= id)
		{
			pb(stack_A, stack_B);
			rb(stack_B);
			id++;
		}
		else if (iterate->index <= id + formula)
		{
			pb(stack_A, stack_B);
			id++;
		}
		else
			ra(stack_A);
		if (stack_A->head)
			iterate = (stack_A->head);
		else
		{
			stack_A->head = NULL;
			iterate = NULL;
		}
// printf("STACK A\n");
// check_stack(stack_A);
// exit(-1);
	}
// printf("finished k-sort loop\n");
// printf("STACK A\n");
// check_stack(stack_A);
// printf("STACK B\n");
// check_stack(stack_B);
// exit(-1);
	push_biggest_to_a(stack_A, stack_B); //other function;
}
