/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:48:22 by tsimitop          #+#    #+#             */
/*   Updated: 2024/03/03 17:34:09 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	// free(stack); //pointer was not allocated
}

void	free_split(char **str)
{
	int i = 0;
// printf("argv_split[0] = %s\nargv_split[1] = %s\nargv_split[2] = %s\nargv_split[3] = %s\nargv_split[4] = %s\n", str[0], str[1], str[2], str[3], str[4]);

	while (str && str[i])
	{
		free(str[i]);		// fix it
printf("_______________free_________________\n");
		i++;
	}
	free(str);
}

void ft_exit(char *msg, int exit_value, char **argv_split)
{
	ft_putendl_fd(msg, 2);
	free_split(argv_split);
	exit(exit_value);
}

// void free_stack2(t_stack *stack)
// {
// 	t_node	*t;
// 	if (stack)
// 	{
// 		if (stack->head)
// 		{
// 			while (stack->head)
// 			{
// 				t = stack->head;
// 				stack->head = stack->head->next;
// 				free(t);
// 			}
// 		}
// 	}
// }

