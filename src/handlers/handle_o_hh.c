#include "ft_printf.h"

void	handle_hho(t_plist *list, va_list *ap, int skip)
{
	list->type.uc = (unsigned char)va_arg(*ap, int);
	list->mode = OCTAL;
	list->res = convert_octal((unsigned int)list->type.uc);
	list->res = add_attributes(list, (long double)list->type.uc);
	list->skip += skip;
}
