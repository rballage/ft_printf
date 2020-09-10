#include "ft_printf.h"

void		handle_f(t_plist *list, va_list *ap, int skip)
{
	char *save;

	save = NULL;
	list->type.ld = (long double)va_arg(*ap, double);
	list->res = ft_ftoa_ld((long double)list->type.ld,
	(((long double)list->type.ld < 0) ? '-' : 0), list);
	save = list->res;
	list->f_type = 1;
	list->res = add_attributes(list, (long double)list->type.ld);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
