#include "ft_printf.h"

void	handle_x_maj(t_plist *list, va_list *ap, int skip)
{
	list->type.ll = (long long)va_arg(*ap, unsigned int);
	list->mode = HEXA_HIGH;
	list->res = convert_hexa(list->type.ll, list);
	list->res = add_attributes(list, list->type.ll);
	list->skip += skip;
}
