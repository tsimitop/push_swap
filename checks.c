#include "push_swap.h"

//turns tabs of argv into spaces
char	space(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\t')
			str[i] = ' ';
		i++;
	}
	return (*str);
}

//checks if string is an int
int	check_int(char *str)
{
	int	i;
	int	ret_val;

	i = 0;
	ret_val = -1;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			ret_val = 0;
		else
			ret_val = 1;
		i++;
	}
	return (ret_val);
}

//if duplicates -1 else 0
int	check_dup(char **argv_split)
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
			if (ft_strncmp(argv_split[j], argv_split[i], 12) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
