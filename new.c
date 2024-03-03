/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:45:14 by tsimitop          #+#    #+#             */
/*   Updated: 2024/03/03 17:38:06 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_parse_input_without_quotes(char **argv, int argc)//it starts with the argv[0]
{
	int		i;
	char	**argv_split = NULL;

	i = 0;
	argv_split = ft_calloc(argc + 1, sizeof(char *));
	if (!argv_split)
		ft_exit("calloc failed", 1, NULL);
	while (i < argc)
	{
		argv_split[i] = argv[i + 1];
		i++;
	}
	i = 0;
	while (argv_split[i])
	{
		//1. check if no numeric characters inside:
		ft_check_if_int(argv_split[i], argv_split);
		//2. check for integer range:
		ft_check_limits(argv_split[i], argv_split);
		i++;
	}
	//4. check for duplicates:
	check_if_dup(argv_split); //it only checks for duplicates in one string/argument
// printf("_______________ft_parse_input_without_quotes__________________\n");
	return (argv_split);
}

t_stack	*ft_initialize_stackA_without_quotes(t_stack *stack_A, char **argv_split)
{
	int		i;

	i = 0;
	while (argv_split[i])
	{
		stack_A = initialise_stack(stack_A, argv_split[i]);
		if (!stack_A)
			ft_exit("stack_A not allocated", 1, argv_split);
		i++;
	}
	set_index(stack_A);
	free_split(argv_split);
printf("_______________ft_initialize_stackA_without_quotes__________________\n");
// printf("argv_split[0] = %s\nargv_split[1] = %s\nargv_split[2] = %s\nargv_split[3] = %s\nargv_split[4] = %s\n", argv_split[0], argv_split[1], argv_split[2], argv_split[3], argv_split[4]);
// exit(-1);
	return (stack_A);
}

void check_leaks(void)
{
	system("leaks push_swap");
}
