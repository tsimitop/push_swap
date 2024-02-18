#include "push_swap.h"

int	square_root(int number)
{
	double	x;
	double epsilon;

	x = number;
	epsilon = 0.000001;
	while ((x * x - number) > epsilon)
		x = 0.5 * (x + number / x);
	return (x);
}
