#include "ft_printf.h"

void	handle_p(t_plist *list, va_list *ap, int skip)
{
	list->sharp = 1;
	list->pointer = 1;
	list->type.lu = va_arg(*ap, unsigned long);
	list->mode = HEXA_LOW;
	list->res = convert_hexa(list->type.lu, list);
	list->res = add_attributes(list, (long double)list->type.lu);
	list->skip += skip;
}
