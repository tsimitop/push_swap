#include "push_swap.h"
// char	*new_atoi(const char *str);
int main(int argc, char **argv)
{
printf("TEST\n");
	char **argv_split;
	t_stack *A_stack = (t_stack *)ft_calloc(argc + 1, sizeof(t_node));
	// t_stack *B_stack = (t_stack *)ft_calloc(argc + 1, sizeof(t_node));
	// t_node *new = ft_calloc(1, sizeof(t_node));
	// t_node	*new = NULL;

	// A_stack->head = new; //(t_node *)ft_calloc(argc + 1, sizeof(t_node));
	// B_stack->head = new; //(t_node *)ft_calloc(argc + 1, sizeof(t_node));
	if (argc == 2)
	{
		int i = 0;
		// int digit = 0;

		*argv[1] = space(argv[1]);
		argv_split = ft_split(argv[1], ' ');
		while (argv_split[i])
		{
printf("argv[i] = %s\n", argv_split[i]);
			if (check_int(argv_split[i]) == 0 && check_dup(argv_split) == 0)
			{
				A_stack = initialise_stack(A_stack, argv_split[i]);
			}
			else
				return (0); //exit (-1);
			i++;
			// set indexes
// printf("TEST MORE\n");
		}
		free(argv_split);
	}
	return (0);
}

