
#include "libft.h"

int	ft_isodd(int n)
{
	int bit;

	bit = (n >> 0) & 1;
	return (bit);
}

int	ft_iseven(int n)
{
	return (!ft_isodd(n));
}
