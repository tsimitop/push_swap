/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:45:14 by tsimitop          #+#    #+#             */
/*   Updated: 2024/03/02 19:14:34 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// void	ft_check_if_int(char *str, char **argv_split)
// {
// 	int	i;

// 	i = 0;
// 	if (str[0] == '-' || str[0] == '+')
// 		i = 1;
// 	while (str[i] != '\0')
// 	{
// 		if (!(str[i] >= '0' && str[i] <= '9'))
// 			ft_exit("Error: not all arguments are ints", 0, argv_split);
// 		i++;
// 	}
// }

// void	check_if_dup(char **argv_split)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (argv_split[i] != NULL)
// 	{
// 		// i = ft_atoi(argv_split[i]);
// 		j = i + 1;
// 		while (argv_split[j] != NULL)
// 		{
// 			if (ft_atoll(argv_split[j]) == ft_atoll(argv_split[i]))
// 				ft_exit("Error: there are duplicated arguments", 0, argv_split);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	ft_check_limits(char *str, char **argv_split)
// {
// 	long long nbr;

// 	nbr = ft_atoll(str);

// 	if (nbr > INT_MAX || nbr < INT_MIN)
// 		ft_exit("Error: not within int limits", 0, argv_split);
// }

// void	ft_parse_input(char **argv)//it starts with the argv[0]
// {
// 	int		i;
// 	int		j;
// 	char	**argv_split;

// 	j = 1;
// 	while (argv[j])
// 	{
// 		argv_split = ft_split(argv[j], ' ');
// 		i = 0;
// 		while (argv_split[i])
// 		{
// 			//1. check if no numeric characters inside:
// 			ft_check_if_int(argv_split[i], argv_split);
// 			//2. check for integer range:
// 			ft_check_limits(argv_split[i], argv_split);
// 			i++;
// 		}
// 		//4. check for duplicates:
// 		check_if_dup(argv_split); //it only checks for duplicates in one string/argument
// 		free_split(argv_split);
// 		j++;
// 	}
// }

// char	**ft_parse_input_with_quotes(char **argv, int argc)//it starts with the argv[0]
// {
// 	int		i;
// 	// int		j;
// 	char	**argv_split = NULL;

// 	i = 0;
// 	argv_split = ft_calloc(argc+1, sizeof(char *));
// 	while (i < argc)
// 	{
// 		argv_split[i] = argv[i + 1];
// 		i++;
// 	}
// 	i = 0;
// 	// j = 1;
// 	// while (argv[j])
// 	// {
// 	// 	argv_split = ft_split(argv[j], ' ');
// 		// i = 0;
// 	while (argv_split[i])
// 	{
// 		//1. check if no numeric characters inside:
// 		ft_check_if_int(argv_split[i], argv_split);
// 		//2. check for integer range:
// 		ft_check_limits(argv_split[i], argv_split);
// 		i++;
// 	}
// 	//4. check for duplicates:
// 	check_if_dup(argv_split); //it only checks for duplicates in one string/argument
// 	free_split(argv_split);
// 		// j++;
// 	// }
// 	return (argv_split);
// }

// void check_leaks(void)
// {
// 	system("leaks push_swap");
// }

// t_stack	*ft_initialize_stackA(t_stack *stack_A, char **argv)
// {
// 	int		i;
// 	int		j;

// 	char	**argv_split;

// 	i = 0;
// 	j = 1;
// 	while (argv[j])
// 	{
// 		argv_split = ft_split(argv[j], ' ');
// 		j++;
// 	}
// 	// *argv[1] = space(argv[1]);
// 	while (argv_split[i])
// 	{
// 		stack_A = initialise_stack(stack_A, argv_split[i]);
// 		if (!stack_A)
// 			ft_exit("stack_A not allocated", 1, argv_split);
// 		i++;
// 	}
// 	set_index(stack_A);
// 	free_split(argv_split);
// 	return (stack_A);
// }
