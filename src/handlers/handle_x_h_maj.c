#include "ft_printf.h"

void	handle_hx_maj(t_plist *list, va_list *ap, int skip)
{
	list->type.us = (unsigned short)va_arg(*ap, unsigned int);
	list->mode = HEXA_HIGH;
	list->res = convert_hexa((unsigned int)list->type.us, list);
	list->res = add_attributes(list, (long double)list->type.us);
	list->skip += skip;
}
