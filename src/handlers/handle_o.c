#include "ft_printf.h"

void	handle_o(t_plist *list, va_list *ap, int skip)
{
	list->type.u = va_arg(*ap, unsigned int);
	list->mode = OCTAL;
	list->res = convert_octal(list->type.u);
	list->res = add_attributes(list, (long double)list->type.u);
	list->skip += skip;
}
