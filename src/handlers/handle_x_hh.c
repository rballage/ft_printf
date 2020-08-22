#include "ft_printf.h"

void	handle_hhx(t_plist *list, va_list *ap, int skip)
{
	list->type.uc = (unsigned char)va_arg(*ap, unsigned int);
	list->mode = HEXA_LOW;
	list->res = convert_hexa((unsigned int)list->type.uc, list);
	list->res = add_attributes(list, (long double)list->type.uc);
	list->skip += skip;
}
