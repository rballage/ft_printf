#include "ft_printf.h"

void		handle_lf_maj(t_plist *list, va_list *ap, int skip)
{
	list->type.ld = va_arg(*ap, long double);
	list->res = ft_ftoa_ld((long double)list->type.ld,
	(((long double)list->type.ld < 0) ? '-' : 0), list);
	list->f_type = 1;
	list->res = add_attributes(list, list->type.ld);
	list->skip += skip;
}
