#include "ft_printf.h"

void	set_plus(t_plist *list, const char *format)
{
	list->plus = 1;
	list->skip++;
	(void)format;
}
