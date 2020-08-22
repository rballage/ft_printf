#include "ft_printf.h"

void	handle_lu(t_plist *list, va_list *ap, int skip)
{
	list->type.lu = va_arg(*ap, unsigned long);
	list->res = ft_lutoa(list->type.lu);
	list->uns = 1;
	list->res = add_attributes(list, (long double)list->type.lu);
	list->skip += skip;
}
