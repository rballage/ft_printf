#include "ft_printf.h"

void	handle_u(t_plist *list, va_list *ap, int skip)
{
	list->type.u = va_arg(*ap, unsigned int);
	list->res = ft_llitoa((long long)list->type.u);
	list->uns = 1;
	list->res = add_attributes(list, (long double)list->type.u);
	list->skip += skip;
}
