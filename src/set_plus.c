#include "ft_printf.h"

int	set_plus(t_plist *list, const char *format, va_list *ap)
{
	list->plus = 1;
	list->skip++;
	(void)format;
	(void)ap;
	return (1);
}
