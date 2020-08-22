#include "ft_printf.h"

void	handle_llo(t_plist *list, va_list *ap, int skip)
{
	list->type.llu = (unsigned long long)va_arg(*ap, long long);
	list->mode = OCTAL;
	list->res = convert_octal(list->type.llu);
	list->res = add_attributes(list, (long double)list->type.llu);
	list->skip += skip;
}
