
#include "ft_printf.h"

char	*convert_hexa(unsigned long long nb, t_plist *list)
{
	static const char	hexa_str[17] = "0123456789abcdef";
	int					i;
	char				*str;

	i = ft_baselen(nb, 16);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = '\0';
	i -= 1;
	while (nb > 15)
	{
		str[i] = hexa_str[nb % 16];
		if (list->mode == HEXA_HIGH && nb % 16 > 9)
			str[i] -= 32;
		i--;
		nb /= 16;
	}
	str[i] = hexa_str[nb];
	if (list->mode == HEXA_HIGH && nb % 16 > 9)
		str[i] -= 32;
	return (str);
}
