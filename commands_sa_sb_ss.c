/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_sa_sb_ss.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:50:59 by tsimitop          #+#    #+#             */
/*   Updated: 2024/02/27 16:51:01 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

////////////////////////////////////////////////////////////////////////////////
////								STACK_A									////
////////////////////////////////////////////////////////////////////////////////

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
*/
void    sa(t_stack *stack_A)
{
    t_node *first = stack_A->head;
    t_node *second = first->next;

    if (stack_A->head == NULL || stack_A->head->next == NULL)
        return; // Do nothing if there is only one or no elements

    // Swap the first two elements
    first->next = second->next;
    second->next = first;

    if (first->next != NULL)
        first->next->prev = first;
    second->prev = first->prev;
    first->prev = second;

    stack_A->head = second; // Update the head of the stack
    // ft_ps_delone(first, delete_tmp);
    write(1, "sa\n", 3);
}

////////////////////////////////////////////////////////////////////////////////
////								STACK_B									////
////////////////////////////////////////////////////////////////////////////////


/*
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
*/
void    sb(t_stack *stack_B)
{
    t_node *first = stack_B->head;
    t_node *second = first->next;
    if (stack_B->head == NULL || stack_B->head->next == NULL)
        return; // Do nothing if there is only one or no elements
    // Swap the first two elements
    first->next = second->next;
    second->next = first;
    if (first->next != NULL)
        first->next->prev = first;
    second->prev = first->prev;
    first->prev = second;
    stack_B->head = second; // Update the head of the stack
    // ft_ps_delone(first, delete_tmp);
    write(1, "sb\n", 3);
}

////////////////////////////////////////////////////////////////////////////////
////							BOTH STACKS									////
////////////////////////////////////////////////////////////////////////////////

void	ss(t_stack *stack_A, t_stack *stack_B)
{
	sa(stack_A);
	sb(stack_B);
	write (1, "ss\n", 3);
}


// frees tmp
// void	delete_tmp(void *tmp)
// {
// 	free(tmp);
// }

//lstdelone for push_swap
// void	ft_ps_delone(t_node *lst, void (*del)(void*))
// {
// 	if (!lst || !del)
// 		return ;
// 	del(lst->nbr);
//     del(lst->index);
// 	free(lst);
// }

// void sa(t_node *head, t_node *sec)
// {
// 	t_node *tmp;

// 	tmp = head;
// 	head->next = head->next->next;
// 	sec->next = tmp->next;
// 	head->prev = sec->prev;
// 	sec->prev = tmp->prev;
// 	ft_ps_delone(tmp, delete_tmp);
// 	write(1, "sa\n", 3);
// }
