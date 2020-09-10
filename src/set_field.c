#include "ft_printf.h"

int		set_field(t_plist *list, const char *format, va_list *ap)
{
	int	i;

	i = 0;
	if (list->has_star)
	{
		list->min_w = list->star_value;
		list->has_star = false;
	}
	else
	{
		list->min_w = ft_atoi(format);
		while (*format >= '0' && *format <= '9')
		{
			i++;
			format++;
		}
	}
	(void)ap;
	list->skip += i;
	return (i);
}
