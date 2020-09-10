#include "ft_printf.h"

void	handle_d(t_plist *list, va_list *ap, int skip)
{
	char *save;

	save = NULL;
	list->type.i = va_arg(*ap, int);
	list->res = ft_itoa(list->type.i);
	save = list->res;
	list->res = add_attributes(list, (long double)list->type.i);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
