#include "ft_printf.h"

void	handle_lo(t_plist *list, va_list *ap, int skip)
{
	list->type.lu = va_arg(*ap, unsigned long);
	list->mode = OCTAL;
	list->res = convert_octal((unsigned long long)list->type.lu);
	list->res = add_attributes(list, (long double)list->type.lu);
	list->skip += skip;
}
