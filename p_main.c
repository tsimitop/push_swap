#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack_A = (t_stack *)ft_calloc(argc + 1, sizeof(t_node));
	t_stack *stack_B = (t_stack *)ft_calloc(argc + 1, sizeof(t_node));

	if (argc == 2)
		make_index_string(stack_A, argv);
	//na ftiakso gia argc > 2
	k_sort(stack_A, stack_B);
	return (0);
}

void	make_index_string(t_stack *A_stack, char **argv)
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
				A_stack = initialise_stack(A_stack, argv_split[i]);
			else
				return ; //exit (-1);
			i++;
		}
		set_index(A_stack);
		free(argv_split);
printf("\nLAST CHECK FOR NODES IN NOT_MAIN");
check_node(A_stack);
printf("DONE");
}
