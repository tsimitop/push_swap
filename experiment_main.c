/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   experiment_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:50:15 by tsimitop          #+#    #+#             */
/*   Updated: 2024/03/02 19:15:46 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_exit(char *msg, int exit_value, char **argv_split)
{
	ft_putendl_fd(msg, 2);
	free_split(argv_split);
	// printf("hello before exit call\n");
	exit(exit_value);
	// printf("hello after exit call\n");
}

void	ft_check_if_int(char *str, char **argv_split)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i = 1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			ft_exit("Error: not all arguments are ints", 0, argv_split);
		i++;
	}
}

void check_if_dup(char **argv_split)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv_split[i] != NULL)
	{
		// i = ft_atoi(argv_split[i]);
		j = i + 1;
		while (argv_split[j] != NULL)
		{
			if (ft_atoll(argv_split[j]) == ft_atoll(argv_split[i]))
				ft_exit("Error: there are duplicated arguments", 0, argv_split);
			// if (ft_strncmp(argv_split[j], argv_split[i], 12) == 0)
			j++;
		}
		i++;
	}
}

void	ft_check_limits(char *str, char **argv_split)
{
	// int	len;
	// len = ft_strlen(str);

	// if (len > 10)
	// {
	// 		if (str[0] == '-')
	// 		{
	// 			if (ft_strlen(str) > 11 || ft_strncmp(str, "-2147483648", 10) > 0)
	// 				ft_exit("Error: not within int limits", 0, argv_split);
	// 		}
	// 		else if (ft_strlen(str) > 10 || ft_strncmp(str, "2147483647", 10) > 0) //check for +
	// 			ft_exit("Error: not within int limits", 0, argv_split);
	// }

	long long nbr;

	nbr = ft_atoll(str);

	if (nbr > INT_MAX || nbr < INT_MIN)
		ft_exit("Error: not within int limits", 0, argv_split);
}
// 	9,223,372,036,854,775807
void ft_parse_input(char **argv)//it starts with the argv[0]
{
	int		i;
	int		j;
	char	**argv_split;

	j = 1;
	while (argv[j])
	{
		argv_split = ft_split(argv[j], ' ');
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
		free_split(argv_split);
		j++;
	}
}

void check_leaks(void)
{
	system("leaks push_swap");
}

t_stack	*ft_initialize_stackA(t_stack *stack_A, char **argv)
{
	int		i;
	char	**argv_split;

	i = 0;
	// *argv[1] = space(argv[1]);
	argv_split = ft_split(argv[1], ' ');
	while (argv_split[i])
	{
		stack_A = initialise_stack(stack_A, argv_split[i]);
		if (!stack_A)
			ft_exit("stack_A not allocated", 1, argv_split);
		i++;
	}
	set_index(stack_A);
	free_split(argv_split);
	return (stack_A);
}

int main(int argc, char **argv)
{
	t_stack stack_A;
	t_stack stack_B;

	if (argc < 2)
		return (0);
	// atexit(check_leaks);
	// t_stack *stack_A = (t_stack *)ft_calloc(1, sizeof(t_stack));
	// if (!stack_A)
	// 	return (0);
	// stack_A->head = NULL;
	// t_stack *stack_B = (t_stack *)ft_calloc(1, sizeof(t_stack));
	// if (!stack_B)
	// 	return (0);
	// stack_B->head = NULL;
	ft_parse_input(argv);
	ft_initialize_stackA(&stack_A, argv);
	// printf("hello after parse call\n\n");
	// if (argc == 2)
	// 	make_index_string(&stack_A, argv);
	// else if (argc > 2)
	// 	make_index_string_above_3(&stack_A, argc, argv);
	// if (!stack_A)
	// {
	// 	free(stack_A);
	// 	free(stack_B);
	// 	return (0);
	// }
	if (stack_length(&stack_A) && stack_length(&stack_A) > 3)
		k_sort(&stack_A, &stack_B);
	else if (stack_length(&stack_A) == 3)
		sort_3(&stack_A);
	else if (stack_length(&stack_A) == 2)
	{
		if (stack_A.head->nbr > stack_A.head->next->nbr)
			sa(&stack_A);
	}
// printf("FINAL STACK A\n"); //___________________________________________________
// check_stack(&stack_A);
free_stack2(&stack_A); //create free_stack function to del each node
free_stack2(&stack_B);
	return (0);
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
		
		if (check_int(argv_split[i], argv_split) == 0 && check_dup(argv_split) == 0 && check_limits(argv_split[i]) == 0)
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
