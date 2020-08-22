#include "ft_printf.h"

void	handle_hhd(t_plist *list, va_list *ap, int skip)
{
	list->type.c = (char)va_arg(*ap, int);
	list->res = ft_itoa((int)list->type.c);
	list->res = add_attributes(list, (long double)list->type.c);
	list->skip += skip;
}
