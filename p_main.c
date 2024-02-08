#include "push_swap.h"
# include "libft.h"

char	*new_atoi(const char *str);

int main(int argc, char **argv)
{
	char **argv_split;
	// char **new_split;
	t_stack A_stack;
	// t_stack B_stack;
	t_node	*temp;

	A_stack.head = (t_node *)ft_calloc(argc + 1, sizeof(t_node));
	// A_stack.size = 0;
	// B_stack.head = (t_node *)ft_calloc(argc + 1, sizeof(t_node));
	// B_stack.size = 0;
	if (argc == 2)
	{
		int i = 0;
		int digit;

		*argv[1] = space(argv[1]);
		argv_split = ft_split(argv[1], ' ');
		while (argv_split[i])
		{
			// if (*argv_split == ' ') //check if int
			// 	i++;
			if (check_int(argv_split[i]) == 0 && check_dup(argv_split[i]) == 0)
			{
				digit = ft_atoi(argv_split[i]);
				if (A_stack.head == NULL)
					A_stack.head->nbr = digit;
				else
				{
					temp = A_stack.head;
					A_stack.head->nbr = digit;
					A_stack.head->next = temp;
				}
				// new_split = new_atoi(argv_split[i]);
				i++;
				// A_stack.size = i;
			}
			else
				exit;
		}
		free(argv_split);
	}
	return (0);
}

// char	*new_atoi(const char *str)
// {
// 	int		i;
// 	int		sign;
// 	int		result;
// 	char	*new_str;

// 	i = 0;
// 	sign = 1;
// 	result = 0;
// 	new_str = str;
// 	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
// 		|| str[i] == '\f' || str[i] == ' ' || str[i] == '\r')
// 		i++;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-' || str[i] == '+')
// 			if (str[i] == '-')
// 				sign = -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		result = result * 10 + str[i] - '0';
// 		*new_str++ = '\0';
// 		i++;
// 	}
// 	return (*new_str);
// }
