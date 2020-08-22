#include "ft_printf.h"

void	set_precision(t_plist *list, const char *format)
{
	list->dot = 1;
	if (format[1] >= '0' && format[1] <= '9')
	{
		list->dot_size = ft_atoi(&format[1]);
		if (format[1] == '-' || format[1] == '+')
		{
			list->skip++;
			format++;
		}
		while (format[1] >= '0' && format[1] <= '9')
		{
			format++;
			list->skip++;
		}
		list->skip++;
	}
	else
	{
		list->dot_size = 0;
		list->skip++;
	}
}
