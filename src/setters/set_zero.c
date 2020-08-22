#include "ft_printf.h"

void	set_zero(t_plist *list, const char *format)
{
	list->zero = 1;
	list->skip++;
	(void)format;
}
