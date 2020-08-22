#include "ft_printf.h"

void	handle_ld(t_plist *list, va_list *ap, int skip)
{
	list->type.l = va_arg(*ap, long);
	list->res = ft_llitoa((long long)list->type.l);
	list->res = add_attributes(list, (long double)list->type.l);
	list->skip += skip;
}
