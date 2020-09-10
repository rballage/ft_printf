#include "ft_printf.h"

int	set_zero(t_plist *list, const char *format, va_list *ap)
{
	list->zero = 1;
	list->skip++;
	(void)format;
	(void)ap;
	return (1);
}
