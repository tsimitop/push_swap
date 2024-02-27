/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_ra_rb_rr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:50:45 by tsimitop          #+#    #+#             */
/*   Updated: 2024/02/27 16:50:47 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

////////////////////////////////////////////////////////////////////////////////
////								STACK_A									////
////////////////////////////////////////////////////////////////////////////////

/*
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
*/
void	ra(t_stack *stack_A)
{
	t_node	*temp;
	t_node	*last;

	temp = stack_A->head;
	last = NULL;
	while (temp->next != NULL)
	{
		last = temp;
		temp = temp->next;
	}
	last->next = NULL;
	temp->prev = NULL;
	temp->next = stack_A->head;
	stack_A->head = stack_A->head->next;
	stack_A->head->prev = temp; //if (stack_A->head != NULL)
	stack_A->head = temp;
	write(1, "ra\n", 3);
}

////////////////////////////////////////////////////////////////////////////////
////								STACK_B									////
////////////////////////////////////////////////////////////////////////////////


/*
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.						CORRECT
*/
void	rb(t_stack *stack_B)
{
	t_node	*last;
	t_node	*first;
	t_node	*second;

	if (stack_B->head != NULL && stack_B->head->next != NULL)
	{
		last = last_node(stack_B);
		second = stack_B->head->next;
		first = stack_B->head;
		last->next = first;
		first->prev = last;
		first->next = NULL;
		second->prev = NULL;
		stack_B->head =  second;
		write(1, "rb\n", 3);
	}
}

// void rb(t_stack *stack_B)
// {
// 	t_node *last = last_node(stack_B);

// 	if (last != NULL && stack_B->head != last)
// 	{
// 		last->prev->next = NULL;
// 		last->prev = NULL;
// 		last->next = stack_B->head;
// 		stack_B->head->prev = last;
// 		stack_B->head = last;
// 		write(1, "rb\n", 3);
// 	}
// }



// void	rb(t_stack *stack_B)
// {
// printf("__________________________________________________________________\n");

// 	t_node	*temp;
// 	t_node	*last;
// 	t_node	*end;
// 	temp = stack_B->head;
// 	last = NULL;
// 	while (temp && temp->next != NULL)
// 	{
// 		last = temp;
// 		temp = temp->next;
// 	}
// 	// temp->next = NULL;
// 	if (temp)
// 	{
// // printf("enter rb, fix problem\n");
// 		temp->prev = NULL;
// 		temp->next = stack_B->head;
// 		last->next = NULL;
// // printf("TEST\n");
// // check_stack(stack_B);
// 	}
// 	else
// 		temp = stack_B->head;
// 	// temp->next = stack_B->head;
// 	if (stack_B->head)
// 	{
// 		// stack_B->head = stack_B->head->next;
// 		stack_B->head->prev = temp; //if (stack_A->head != NULL)
// 		stack_B->head = temp;
// // printf("HEY rb\nHEY\n");
// 		end = last_node(stack_B);
// 		end->next = NULL;
// 	}
// printf("__________________________________________________________________\n");
// check_stack(stack_B);

// 	write(1, "rb\n", 3);
// }


////////////////////////////////////////////////////////////////////////////////
////							BOTH STACKS									////
////////////////////////////////////////////////////////////////////////////////

/*
rr : ra and rb at the same time.
*/
void	rr(t_stack *stack_A, t_stack *stack_B)
{
	ra(stack_A);
	rb(stack_B);
	write(1, "rr\n", 3);
}
