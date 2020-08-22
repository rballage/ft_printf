#include "ft_printf.h"

void	handle_llx(t_plist *list, va_list *ap, int skip)
{
	list->type.llu = va_arg(*ap, long long);
	list->mode = HEXA_LOW;
	list->res = convert_hexa(list->type.llu, list);
	list->res = add_attributes(list, (long double)list->type.llu);
	list->skip += skip;
}
