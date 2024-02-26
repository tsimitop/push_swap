#include <string.h>
#include <stdio.h>

int main(void)
{
	char *str1 = "2147483649";
	char *str2 = "2147483648";
	int i = 0;

	i = strncmp(str1, str2, 11);
	printf("%i\n", i);
	return (0);
}