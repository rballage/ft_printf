#include "ft_printf.h"

void	handle_hd(t_plist *list, va_list *ap, int skip)
{
	char *save;

	save = NULL;
	list->type.s = (short)va_arg(*ap, int);
	list->res = ft_itoa(list->type.s);
	save = list->res;
	list->res = add_attributes(list, (long double)list->type.s);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
