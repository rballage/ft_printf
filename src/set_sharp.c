#include "ft_printf.h"

int	set_sharp(t_plist *list, const char *format, va_list *ap)
{
	list->sharp = 1;
	list->skip++;
	(void)format;
	(void)ap;
	return (1);
}
