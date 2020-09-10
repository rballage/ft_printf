#include "ft_printf.h"

int	set_minus(t_plist *list, const char *format, va_list *ap)
{
	list->minus = 1;
	list->skip++;
	(void)format;
	(void)ap;
	return (1);
}
