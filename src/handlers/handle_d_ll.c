#include "ft_printf.h"

void	handle_lld(t_plist *list, va_list *ap, int skip)
{
	list->type.ll = va_arg(*ap, long long);
	list->res = ft_llitoa(list->type.ll);
	list->res = add_attributes(list, (long double)list->type.ll);
	list->skip += skip;
}
