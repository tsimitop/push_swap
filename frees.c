/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:48:22 by tsimitop          #+#    #+#             */
/*   Updated: 2024/03/02 19:14:52 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	del_content(int *content)
// {
// 	free(content);
// }

// void free_stack(t_stack *stack, void (*del)(void*))
// {
// 	t_node *current_head;
// 	t_node *temp;

// 	if (!stack->head)
// 		return;

// 	temp = stack->head;
// 	current_head = stack->head;
// 	while (current_head != NULL)
// 	{
// 		temp = current_head->next;
// 		del(&current_head->index);
// 		del(&current_head->nbr);
// 		del(&current_head->used);
// 		free(current_head);
// 		current_head = temp;
// 	}
// 	stack->head = NULL;
// }


void	free_stack(t_stack *stack)
{
	t_node	*temp;

	temp = stack->head;
	while (stack->head != NULL)
	{
		temp = stack->head;
		stack->head = stack->head->next;
		free(temp);
	}
	free(stack);
}

void	free_split(char **str)
{
	int i = 0;
	while (str[i])
	{
		free(str[i]);		// fix it
		i++;
	}
	free(str);
	// return (0);
}
void free_stack2(t_stack *stack)
{
	t_node *t;
	if (stack)
	{
		if (stack->head)
		{
			while (stack->head)
			{
			t = stack->head;
			stack->head = stack->head->next;
			free(t);
			}

		}

	}
}

// void	ft_exit(char *msg, int exit_value, char **argv_split)
// {
// 	ft_putendl_fd(msg, 2);
// 	free_split(argv_split);
// 	exit(exit_value);
// }

