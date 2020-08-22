#include "ft_printf.h"

int	search_setters(char c, const char *flags)
{
	int i;

	i = 0;
	while (*flags)
	{
		if (c == *flags)
			return (i);
		flags++;
		i++;
	}
	return (-1);
}
