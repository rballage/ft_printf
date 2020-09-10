#include "ft_printf.h"

int	set_precision(t_plist *list, const char *format, va_list *ap)
{
	int i;

	i = 1;
	list->dot = 1;
	(void)ap;
	format++;
	if (*format >= '0' && *format <= '9')
	{
		list->precision = ft_atoi(format);
		while (*format >= '0' && *format <= '9')
		{
			format++;
			i++;
		}
	}
	else if (list->has_star)
	{
		list->precision = list->star_value >= 0 ? list->star_value : (list->dot = 0);
		list->has_star = false;
	}
	else
		list->precision = 0;
	list->skip += i;
	return (i);
}
