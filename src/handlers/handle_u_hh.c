#include "ft_printf.h"

void	handle_hhu(t_plist *list, va_list *ap, int skip)
{
	list->type.uc = (unsigned char)va_arg(*ap, unsigned int);
	list->res = ft_itoa((int)list->type.uc);
	list->res = add_attributes(list, (long double)list->type.uc);
	list->skip += skip;
}
