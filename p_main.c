/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:50:15 by tsimitop          #+#    #+#             */
/*   Updated: 2024/02/27 18:11:35 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack_A = (t_stack *)ft_calloc(argc + 1, sizeof(t_node));
	if (!stack_A)
		return (0);
	t_stack *stack_B = (t_stack *)ft_calloc(argc + 1, sizeof(t_node));
	if (!stack_B)
		return (0);
	if (argc == 2)
		stack_A = make_index_string(stack_A, argv);
	else if (argc > 2)
		stack_A = make_index_string_above_3(stack_A, argc, argv);
	if (!stack_A)
	{
		free(stack_A);
		free(stack_B);
		return (0);
	}
	if (stack_length(stack_A) && stack_length(stack_A) > 3)
		k_sort(stack_A, stack_B);
	else if (stack_length(stack_A) == 3)
		sort_3(stack_A);
	else if (stack_length(stack_A) == 2)
	{
		if (stack_A->head->nbr > stack_A->head->next->nbr)
			sa(stack_A);
	}
// printf("FINAL STACK A\n"); //___________________________________________________
// check_stack(stack_A);
free(stack_A); //create free_stack function to del each node
free(stack_B);
	return (0);
}

t_stack	*make_index_string(t_stack *stack_A, char **argv)
{
	int		i;
	char	**argv_split;

	i = 0;
	*argv[1] = space(argv[1]);
	argv_split = ft_split(argv[1], ' ');
	while (argv_split[i])
	{
		if (check_int(argv_split[i]) == 0 && check_dup(argv_split) == 0 && check_limits(argv_split[i]) == 0)
		{

			stack_A = initialise_stack(stack_A, argv_split[i]);
			if (!stack_A)
				return (NULL);
		}
		else
		{
			// free_split(argv_split, i);
			// free(argv_split);
			return (NULL); //exit (-1);				//handle errors
		}
		i++;
	}
	set_index(stack_A);
	free_split(argv_split, i);
	free(argv_split); //double free???
// printf("\nLAST CHECK FOR NODES IN NOT_MAIN\n");
// check_stack(stack_A);
// printf("DONE\n");
// check_node(stack_A);
	return (stack_A);
}

t_stack	*make_index_string_above_3(t_stack *stack_A, int argc, char **argv)
{
	int		i;
	char	**argv_split;
	i = 0;
	argv_split = ft_calloc(argc+1, sizeof(char *));
	while (i < argc)
	{
		argv_split[i] = argv[i + 1];
		i++;
	}
	i = 0;
	while (argc > 1)		//elegxei sosta? handle errors
	{
		argv_split[i] = argv[i + 1];
		argc--;
		i++;
	}
	i = 0;
	while (argv_split[i])
	{
		if (check_int(argv_split[i]) == 0 && check_dup(argv_split) == 0 && check_limits(argv_split[i]) == 0)
		{
			stack_A = initialise_stack(stack_A, argv_split[i]);
			if (!stack_A)
				return (NULL);
		}
		else
		{
			// free_split(argv_split, i);
			// free(argv_split); //useless??????
			return (NULL); //exit (-1);				//handle errors
		} //exit (-1);				//handle errors && leaks
		i++;
	}
	set_index(stack_A);
	// if (argv_split[i - 1])
	// 	free_split(argv_split, i);
	if (argv_split)
		free(argv_split); //double free???
	return (stack_A);
}
