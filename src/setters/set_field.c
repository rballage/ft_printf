#include "ft_printf.h"

void	set_field(t_plist *list, const char *format)
{
	list->min_w = ft_atoi(format);
	while (*format >= '0' && *format <= '9')
	{
		list->skip++;
		format++;
	}
}
