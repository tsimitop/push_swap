#include <stdio.h>
// #include "../Libft/libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == ' ' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' || str[i] == '+')
			if (str[i] == '-')
				sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

//main that prints out input
int main(int argc, char **argv)
{
    int i;

    i = 0;
    int digit = 0;
    while (i++ < argc - 1)
    {
        printf("%s\n", argv[1]);
        digit = ft_atoi(argv[1]);
        printf("digit = %d\n", digit);
    }
    return (0);
}