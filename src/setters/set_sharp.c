#include "ft_printf.h"

void	set_sharp(t_plist *list, const char *format)
{
	list->sharp = 1;
	list->skip++;
	(void)format;
}
