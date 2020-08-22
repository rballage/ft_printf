#include "ft_printf.h"

void	set_space(t_plist *list, const char *format)
{
	list->space = 1;
	list->skip++;
	(void)format;
}
