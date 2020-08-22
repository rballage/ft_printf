#include "ft_printf.h"

void	handle_d(t_plist *list, va_list *ap, int skip)
{
	list->type.i = va_arg(*ap, int);
	list->res = ft_itoa(list->type.i);
	list->res = add_attributes(list, (long double)list->type.i);
	list->skip += skip;
}
