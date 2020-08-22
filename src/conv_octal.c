
#include "ft_printf.h"

char	*convert_octal(unsigned long long nb)
{
	unsigned long long		nb_cpy;
	int						i;
	char					*str;

	nb_cpy = nb;
	i = ft_baselen(nb, 8);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = '\0';
	i -= 1;
	while (nb > 7)
	{
		str[i--] = nb % 8 + '0';
		nb /= 8;
	}
	str[i] = nb + '0';
	return (str);
}
