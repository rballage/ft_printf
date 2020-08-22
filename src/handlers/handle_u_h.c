#include "ft_printf.h"

void	handle_hu(t_plist *list, va_list *ap, int skip)
{
	list->type.us = (unsigned short)va_arg(*ap, unsigned int);
	list->res = ft_llitoa((long long)list->type.us);
	list->uns = 1;
	list->res = add_attributes(list, (long double)list->type.us);
	list->skip += skip;
}
