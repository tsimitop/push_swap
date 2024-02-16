#include "push_swap.h"

int main(int argc, char **argv)
{
printf("TEST\n");
	t_stack *A_stack = (t_stack *)ft_calloc(argc + 1, sizeof(t_node));
	// t_stack *B_stack = (t_stack *)ft_calloc(argc + 1, sizeof(t_node));

	if (argc == 2)
	{
		make_index_string(A_stack, argv);
	}
	//na ftiakso gia argc > 2
	return (0);
}

void	make_index_string(t_stack *A_stack, char **argv)
{
	int		i;
	char	**argv_split;
	// t_node	*small;
	// t_node *biggest;

		i = 0;
		*argv[1] = space(argv[1]);
		argv_split = ft_split(argv[1], ' ');
		while (argv_split[i])
		{
printf("argv[i] = %s\n", argv_split[i]);
			if (check_int(argv_split[i]) == 0 && check_dup(argv_split) == 0)
				A_stack = initialise_stack(A_stack, argv_split[i]);
			else
				return ; //exit (-1);
			i++;
			// set indexes
		}
		// small = find_smallest(A_stack);
		// biggest = find_biggest(A_stack);
// printf("smallest->used = %i\n", small->used);
// printf("biggest->used = %i\n", biggest->used);
		assign_idx(A_stack);
printf("TEST MORE\n");
		free(argv_split);
}
