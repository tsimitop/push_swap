/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:48:22 by tsimitop          #+#    #+#             */
/*   Updated: 2024/02/27 16:52:41 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_content(int *content)
{
	free(content);
}

void free_stack(t_stack *stack, void (*del)(void*))
{
	t_node *current_head;
	t_node *temp;

	if (!stack->head)
		return;

	temp = stack->head;
	current_head = stack->head;
	while (current_head != NULL)
	{
		temp = current_head->next;
		del(&current_head->index);
		del(&current_head->nbr);
		del(&current_head->used);
		free(current_head);
		current_head = temp;
	}
	stack->head = NULL;
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
