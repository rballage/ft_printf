#include "ft_printf.h"

int	set_space(t_plist *list, const char *format, va_list *ap)
{
	list->space = 1;
	list->skip++;
	(void)format;
	(void)ap;
	return (1);
}
