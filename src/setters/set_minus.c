#include "ft_printf.h"

void	set_minus(t_plist *list, const char *format)
{
	list->minus = 1;
	list->skip++;
	(void)format;
}
