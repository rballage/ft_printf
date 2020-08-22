#include "ft_printf.h"

void	handle_hd(t_plist *list, va_list *ap, int skip)
{
	list->type.s = (short)va_arg(*ap, int);
	list->res = ft_itoa(list->type.s);
	list->res = add_attributes(list, (long double)list->type.s);
	list->skip += skip;
}
