#include "ft_printf.h"

int				search_setters(char c, const char *flags)
{
	const char	*save;

	save = flags;
	while (*flags)
	{
		if (c == *flags)
			return (flags - save);
		flags++;
	}
	return (-1);
}
