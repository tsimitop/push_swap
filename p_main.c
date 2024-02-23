#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack_A = (t_stack *)ft_calloc(argc + 1, sizeof(t_node));
	t_stack *stack_B = (t_stack *)ft_calloc(argc + 1, sizeof(t_node));

	if (argc == 2)
		stack_A = make_index_string(stack_A, argv);

	//na ftiakso gia argc > 2
// check_node(A_stack);
	if (stack_length(stack_A) > 3)
		k_sort(stack_A, stack_B);
	else
		sort_3(stack_A);
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
// printf("argv[i] = %s\n", argv_split[i]);
			if (check_int(argv_split[i]) == 0 && check_dup(argv_split) == 0)
				stack_A = initialise_stack(stack_A, argv_split[i]);
			else
				return (NULL); //exit (-1);				//handle errors
			i++;
		}
		set_index(stack_A);
		free(argv_split);
printf("\nLAST CHECK FOR NODES IN NOT_MAIN\n");
// check_node(stack_A);
// check_stack(stack_A);
printf("DONE\n");
	return (stack_A);
}
