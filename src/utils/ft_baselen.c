#include "ft_printf.h"

int		ft_baselen(unsigned long long nb, unsigned long long base)
{
	int i;

	i = 1;
	while (nb > base - 1)
	{
		nb /= base;
		i++;
	}
	return (i);
}
